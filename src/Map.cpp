//! @file
//! @author Vsevolod Ivanov

#include "Map.h"

Map::Map()
{
}

Map::~Map()
{
}

Map::Node Map::addNode(Country country)
{
    return add_vertex(country, this->graph);
}

void Map::addEdge(Node v1, Node v2, Edge edge)
{
    add_edge(v1, v2, edge, this->graph);
}

void Map::print() const
{
    write_graphviz(cout, this->graph);
}
