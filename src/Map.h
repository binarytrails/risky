//! @file
//! @author Vsevolod Ivanov

#pragma once

#include <iostream>
#include <vector>
#include <boost/config.hpp>
#include "boost/graph/adjacency_list.hpp"
#include <boost/graph/subgraph.hpp>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "Player.h"
#include "Continent.h"
#include <map>

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
        vector<Country*> getCountries();
        void connectCountries(const int country1, const int country2,
                     Map::Graph& continent);
        bool valid() const;
        void log() const;
		//added by Keven Abellard
		vector<Country> getAdj(Country &c);


    private:
		//added by Keven Abellard
		map<Country*, const int> countryMapping;
		map < const int, Country*> countryMappingINV;

        Graph* map;
        vector<Graph> continents;
        vector<Continent*> continentsData;
        vector<Country*> countriesData;
};
