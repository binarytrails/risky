#include "MapReader.h"

bool MapReader::read(string mapFile)
{
    cout << "Reading map " << mapFile << " ..." << endl;
    ifstream in(mapFile);
    string line;

    if (in.is_open() == false) {
        cerr << "Error opening the file" << endl;
        return false;
    }

    while (getline(in, line)) {
        if (line == "[Continents]")
            readContinents(in);
        if (line == "[Territories]")
            readTerritories(in);
    }

    if (this->contLines.empty() or this->terrLines.empty()) {
        cerr << "The map is invalid " << endl;
        return false;
    }
    return true;
}

void MapReader::readTerritories(ifstream &in)
{
    string line;
    while (getline(in, line)) {
        if (line.empty())
            break;
        this->terrLines.push_back(line);
    }
}

void MapReader::readContinents(ifstream &in)
{
    string line;
    while (getline(in, line)) {
        if (line.empty())
            break;
        this->contLines.push_back(line);
    }
}


int MapReader::getNbOfNodes()
{
    int count = 0;
    for (string line: this->contLines)
    {
        int nbOfCountries = stoi(line.substr(line.find("=") + 1));
        count += nbOfCountries;
    }
    return count;
}

void MapReader::load(Map &map)
{
    auto console = spdlog::stdout_color_mt("mapreader");
    stringstream output;

    // Continents
    std::map<string, Map::Graph&> continents;
    std::map<string, Map::Graph&>::iterator continentsIt;

    for (string line: this->contLines)
    {
        string name = line.substr(0, line.find("="));
        int nbOfCountries = stoi(line.substr(line.find("=") + 1));
        output << "Adding Continent " << name <<
                  " with " << nbOfCountries << " country nodes";
        console->debug(output.str()); output.str("");
        Continent* continent = new Continent(name);
        continents.insert(
            pair<string, Map::Graph&>(name, map.addContinent(continent))
        );
    }

    // Territories
    std::map<string, string> terrContinent;
    std::map<string, string>::iterator terrContinentIt;
    std::map<string, int> territories;
    std::map<string, int>::iterator territoriesIt;
    std::map<string, vector<string>> terrEdges;
    std::map<string, vector<string>>::iterator terrEdgesIt;

    for (string line: this->terrLines)
    {
        string name;
        int count = 0;
        stringstream linestream(line);
        string segment;
        Country* country;
        vector<string> edges;

        while (getline(linestream, segment, ','))
        {
            switch (count)
            {
                // territory
                case 0:
                {
                    name = segment;
                    output << "Adding " << name << " territory of ";
                    country = new Country(segment);
                    break;
                }
                // x pixel
                case 1:
                    break;
                // y pixel
                case 2:
                    break;
                // continent
                case 3:
                {
                    terrContinent.insert(pair<string, string>(name, segment));
                    output << segment << " continent with edges to ";
                    continentsIt = continents.find(segment);
                    int node = map.addCountry(country, continentsIt->second);
                    territories.insert(pair<string, int>(name, node));
                    break;
                }
                default:
                {
                    output << segment << ",";
                    edges.push_back(segment);
                    break;
                }
            }
            count++;
        }
        console->debug(output.str()); output.str("");
        terrEdges.insert(pair<string, vector<string>>(name, edges));
    }
    // Connecting the edges
    for (auto elem: territories)
    {
        // get the edge territory continent graph
        terrContinentIt = terrContinent.find(elem.first);
        string contName = terrContinentIt->second;
        continentsIt = continents.find(contName);
        // get the node id of the territory 
        int node1 = elem.second;
        output << "Connecting " << elem.first << " node" << node1;
        terrEdgesIt = terrEdges.find(elem.first);
        output << " with " << terrEdgesIt->second.size() << " edges " <<
                "at " << continentsIt->first << " subgraph:";
        console->debug(output.str()); output.str("");
        for (auto edge: terrEdgesIt->second)
        {
            // get the edge territory node id
            territoriesIt = territories.find(edge);
            if (territoriesIt != territories.end())
            {
                int node2 = territoriesIt->second;
                output << "" << elem.first << " node" << node1 <<
                        " -> " << edge << " node" << node2;
                console->debug(output.str()); output.str("");
                map.connectCountries(node1, node2, continentsIt->second);
            }
        }
    }
    map.log();
}


void MapReader::printMaps(string dirpath) const
{
    using namespace boost::filesystem;

    directory_iterator itr(dirpath);
    directory_iterator end_itr;

    for (; itr != end_itr; ++itr)
    {
        if (!is_directory(itr->status()))
        {
            cout << "[" << itr->path().stem().string() << "] ";
        }
    }
    cout << endl;

}
