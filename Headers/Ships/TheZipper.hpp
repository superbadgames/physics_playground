#include "pch.h"
#include <Tower/framework.h>

#include <Tower/Entity.hpp>

namespace PhysicsDemo
{
    class TheZipper
    {
    public:
        TheZipper(void);

        ~TheZipper(void);

        void Init(void);

    private:
        Tower::p_Entity _entity;

    };
}