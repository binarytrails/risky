//! @file
//! @author Vsevolod Ivanov

#pragma once

#include <iostream>
#include <vector>
#include "boost/graph/adjacency_list.hpp"
#include <boost/graph/graphviz.hpp>
#include "Player.h"
#include "Continent.h"
#include "Country.h"

using namespace std;
using namespace boost;

class Map
{
    public:
        typedef pair<Country, Country> Edge;
        typedef adjacency_list<vecS, vecS, undirectedS, Country, Edge> Graph;
        typedef graph_traits<Graph>::vertex_descriptor Node;

        Map();
        ~Map();

        Node addNode(Country country);
        void addEdge(Node v1, Node v2, Edge edge);
        void buildGraph();
        void print() const;

    private:
        Graph graph;
};
