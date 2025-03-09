/*

The Physics System is really just a collection of functions that needed a safe namespace to hide in.
It wont use any memory of it's one, but rather will contain all the general use functions required
for physics.

For instance, it has the Update function that every Particle needs to have called on it.

*/
#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Physics/Force/ForceRegistry.hpp"


namespace Tower
{
    class PhysicsSystem
    {
    public:
        PhysicsSystem(void);

        ~PhysicsSystem(void);

    private:
        ForceRegistry _forceRegistry;
    };
}