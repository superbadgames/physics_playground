#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Entity.hpp"

#include <vector>

namespace Tower
{
    class I_Map
    {
    public:
        I_Map(void);

        virtual ~I_Map(void);

        // TODO: After a text parser is build
        // After Entity Serialization is working
        // This Init function can take a filepath to load
        //inline virtual void v_Init(const string& filepath) {}
        inline virtual void v_Init(void) = 0;

        inline virtual void v_Update(F32 delta) { DefaultUpdate(delta); }

        inline virtual void v_Render(void) = 0;

        virtual void v_HandleInput(void) = 0;

        void AddEntity(p_Entity entity);

        void DefaultUpdate(F32 delta);

        void DefaultRender(const glm::mat4& viewMatrix);

    private:
        std::vector<p_Entity> _entities;

    };
    typedef shared_ptr<I_Map> p_Map;
}