/*

The Tower Map is a Map that represents either part of all of a world. It is the interface used to:

- load maps from memory
- Keep track of an Active Map, that is the current Map that the "player" is on


*/

#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Components/Map.hpp"

#include <map>

namespace Tower
{
    class MapManager
    {
    public:
        ~MapManager(void);

        static shared_ptr<MapManager> Instance(void);

        void Add(const string& name, p_Map map);

        void Remove(const string& name);

    private:
        static shared_ptr<MapManager> _instance;
        shared_ptr<I_Map> _activeMap;
        std::map<string, shared_ptr<I_Map>> _maps;

        MapManager(void);
    };
    typedef shared_ptr<MapManager> p_MapManager;
}