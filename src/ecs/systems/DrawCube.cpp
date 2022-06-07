/*
** EPITECH PROJECT, 2022
** epi-cs
** File description:
** DrawCube
*/

#include "ecs/components/DrawableCube.hpp"
#include "ecs/components/ColorTexture.hpp"

#include "raylib/Camera.hpp"
#include "raylib/Texture.hpp"
#include "raylib/Matrix.hpp"
#include "raylib/GL.hpp"
#include "raylib/headers/raylib.h"

void ecs::DrawableCube::renderColor(Color &color)
{
    DrawCube(offset, scale.x, scale.y, scale.z, color);
}

void ecs::DrawableCube:: renderTexture(raylib::Texture &texture, Tint tint)
{
    DrawCubeTexture(texture.getTexture(), offset, scale.x, scale.y, scale.z, tint);
}

void ecs::DrawTextureCubeSystem::setSignature(ecs::ComponentManager &component)
{
    _signature = component.generateSignature<Transform, DrawableCube, TextureRef>();
}

void ecs::DrawTextureCubeSystem::update(ecs::World &world)
{
    raylib::Camera &camera = world.getRessource<raylib::Camera>();

    camera.begin3DMode();
    for (auto entity : _entities) {
        Transform &transform = world.getComponent<Transform>(entity);
        DrawableCube &cube = world.getComponent<DrawableCube>(entity);
        TextureRef &textRef = world.getComponent<TextureRef>(entity);
        raylib::Matrix mat = raylib::Matrix::fromTransform(transform)
        * raylib::Matrix::fromTranslate(cube.offset);
        Tint tint = WHITE;

        if (world.hasComponent<Tint>(entity))
            tint = world.getComponent<Tint>(entity);
        raylib::RlMatrixPush push;
        raylib::rlMultMatrix(mat);
        cube.renderTexture(*textRef.texture, tint);
    }
    camera.end3DMode();
}