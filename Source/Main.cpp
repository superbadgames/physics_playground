#include "pch.h"
#include "Maps/BouncingZipperDemo.hpp"

#include <Tower/framework.h>
#include <Tower/Managers/Director.hpp>
#include <Tower/Managers/InputManager.hpp>
#include <Tower/Managers/ShaderManager.hpp>
#include <Tower/Managers/TextureManager.hpp>
#include <Tower/Managers/MapManager.hpp>
#include <Tower/Systems/PhysicsSystem.hpp>

#include <GLFW/glfw3.h>


#include <iostream>

int main(void)
{
    // TODO: This should come from a config file
    const U32 WINDOW_WIDTH = 1200;
    const U32 WINDOW_HEIGHT = 800;

    // Cache the director for later
    Tower::p_Director director = Tower::Director::Instance();
    if (director == nullptr || !director->Init(Tower::WindowType::OPEN_GL, "Tower Sandbox", WINDOW_WIDTH, WINDOW_HEIGHT))
    {
        std::cout << "Error! Unable to initialize." << std::endl;
        return 1;
    }

    // Cache the Map Manager for later
    Tower::p_MapManager mapManager = Tower::MapManager::Instance();

    //
    // Set up any Input Bindings here
    //

    //
    // Initialize shaders
    //
    Tower::p_Shader basicShader = std::make_shared<Tower::Shader>();
    basicShader->Load("..\\..\\Assets\\Default\\Shaders\\basic_vertex.glsl", "..\\..\\Assets\\Default\\Shaders\\basic_fragment.glsl");
    Tower::ShaderManager::Instance()->RegisterShader("basic2d", basicShader);

    //
    // Initialize Textures
    //
    Tower::TextureManager::Instance()->LoadTexture("the_zipper", "..\\..\\Assets\\TheZipper\\Zipper_texture.png");


    //
    // Initialize Maps, and register them with the MapManager
    //
    Tower::p_Map bouncingZipperDemo = std::make_shared<Tower::I_Map>(PhysicsDemo::BouncingZipperDemo());

    mapManager->Add("bouncing_zipper_demo", bouncingZipperDemo);


    while (!director->ShouldProgramClose())
    {
        director->StartFrame();

        // MapManager update active map
        mapManager->UpdateActiveMap(director->GetDeltaTime());

        // MapManager Render active map
        mapManager->RenderActiveMap();

        director->EndFrame();
    }

    director->Cleanup();
    director = nullptr;

    std::cout << "Successful shutdown!" << std::endl;

    return 0;
}