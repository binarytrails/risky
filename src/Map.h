//! @file
//! @author Vsevolod Ivanov

#pragma once

#include <iostream>
#include <vector>
#include <boost/config.hpp>
#include "boost/graph/adjacency_list.hpp"
#include <boost/graph/subgraph.hpp>
#include "Player.h"
#include "Continent.h"

using namespace std;
using namespace boost;

class Map
{
    public:
        typedef subgraph<adjacency_list<
            vecS, vecS, undirectedS,
            property<vertex_index_t, size_t>,
            property<edge_index_t, size_t>
        >> Graph;

        Map(const int nbOfNodes);
        ~Map();

        Graph& addContinent(Continent* continent);
        int addCountry(Country* country, Graph& continent);
        bool hasCountry(Country* country) const;
        void connectCountries(const int country1, const int country2,
                     Map::Graph& continent);
        void print() const;

    private:
        Graph* map;
        vector<Graph> continents;
        vector<Continent*> continentsData;
        vector<Country*> countriesData;
};
