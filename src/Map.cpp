//! @file
//! @author Vsevolod Ivanov

#include "Map.h"

Map::Map(const int nbOfNodes)
{
    this->map = new Graph(nbOfNodes);
}

Map::~Map()
{
    delete this->map;
}

Map::Graph& Map::addContinent(Continent* continent)
{
    continentsData.push_back(continent);
    Map::Graph& graph = map->create_subgraph();
    continents.push_back(graph);
    return graph;
}

int Map::addCountry(Country* country, Map::Graph& continent)
{
    if (this->hasCountry(country))
    {
        cerr << "Error: " << country->getName() <<
                " is already on a continent" << endl;
        throw -1;
    }
    const int countryIndex = this->countriesData.size();
    add_vertex(countryIndex, continent);
    countriesData.push_back(country);
    return countryIndex;
}

bool Map::hasCountry(Country* country) const
{
    for (Country* c: this->countriesData)
    {
        if (country->getName() == c->getName())
            return true;
    }
    return false;
}

vector<Country*> Map::getCountries()
{
    return this->countriesData;
}

void Map::connectCountries(const int country1, const int country2,
                           Map::Graph& continent)
{
    add_edge(country1, country2, continent);
}

// complete (undirected) graph is known to have exactly V(V-1)/2
bool Map::valid() const
{
    int v;
    int edges;
    auto nodes = boost::vertices(*this->map);

    for (auto nIt = nodes.first; nIt != nodes.second; ++nIt)
    {
        auto neighbors = adjacent_vertices(*nIt, *this->map);

        for (auto adjIt = neighbors.first; adjIt != neighbors.second; ++adjIt)
            edges++;
        v++;
    }
    return (edges == ((v*(v-1))/2));
}

void Map::log() const
{
    auto console = spdlog::stdout_color_mt("map");
    stringstream output;
    auto nodes = boost::vertices(*this->map);

    for (auto nIt = nodes.first; nIt != nodes.second; ++nIt)
    {
        output << "Node=" << *nIt << " with Edges={";
        auto neighbors = adjacent_vertices(*nIt, *this->map);

        for (auto adjIt = neighbors.first; adjIt != neighbors.second; ++adjIt)
            output << "(" << *nIt << "," << *adjIt << ")";

        output << "}";
        console->debug(output.str()); output.str("");
    }
}

