/*

An early physics engine test. This will demonstrate that the Particle can be affected by forces.

*/

#include "pch.h"
#include <Tower/framework.h>
#include <Tower/Components/Map.hpp>

namespace PhysicsDemo
{
    class BouncingZipperDemo : public Tower::I_Map
    {
    public:
        BouncingZipperDemo(void);

        ~BouncingZipperDemo(void) final;

        void v_Init(void) final;

        void v_Update(F32 delta) final;

        void v_Render(void) final;

        void v_HandleInput(void) final;

    private:
    };
};