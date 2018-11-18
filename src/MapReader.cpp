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
    // Continents
    std::map<string, Map::Graph&> continents;
    std::map<string, Map::Graph&>::iterator continentsIt;

    for (string line: this->contLines)
    {
        string name = line.substr(0, line.find("="));
        int nbOfCountries = stoi(line.substr(line.find("=") + 1));
        cout << "Adding Continent " << name <<
                " with " << nbOfCountries << " country nodes" << endl;
        Continent* continent = new Continent(name);
        continents.insert(
            pair<string, Map::Graph&>(name, map.addContinent(continent))
        );
    }
    cout << "----------------------------------------" << endl;

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
                    cout << "Adding " << name << " territory of ";
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
                    cout << segment << " continent with edges to ";
                    continentsIt = continents.find(segment);
                    int node = map.addCountry(country, continentsIt->second);
                    territories.insert(pair<string, int>(name, node));
                    break;
                }
                default:
                {
                    cout << segment << ",";
                    edges.push_back(segment);
                    break;
                }
            }
            count++;
        }
        terrEdges.insert(pair<string, vector<string>>(name, edges));
        cout << endl;
    }
    cout << "----------------------------------------" << endl;
    // Connecting the edges
    for (auto elem: territories)
    {
        // get the edge territory continent graph
        terrContinentIt = terrContinent.find(elem.first);
        string contName = terrContinentIt->second;
        continentsIt = continents.find(contName);
        // get the node id of the territory 
        int node1 = elem.second;
        cout << "Connecting " << elem.first << " node" << node1;
        terrEdgesIt = terrEdges.find(elem.first);
        cout << " with " << terrEdgesIt->second.size() << " edges " <<
                "at " << continentsIt->first << " subgraph:" << endl;
        for (auto edge: terrEdgesIt->second)
        {
            // get the edge territory node id
            territoriesIt = territories.find(edge);
            if (territoriesIt != territories.end())
            {
                int node2 = territoriesIt->second;
                cout << "" << elem.first << " node" << node1 <<
                        " -> " << edge << " node" << node2 << endl;
                map.connectCountries(node1, node2, continentsIt->second);
            }
        }
        cout << endl;
    }
    cout << "----------------------------------------" << endl;
    map.print();
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
