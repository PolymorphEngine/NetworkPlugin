/*
** EPITECH PROJECT, 2022
** ComponentFactory.hpp
** File description:
** header for ComponentFactory.c
*/

#pragma once

#include <unordered_map>
#include "polymorph/engine/api/scripting/AComponentFactory.hpp"

namespace polymorph::engine::api
{
    class NetFactory : public AComponentFactory
    {

////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////

    public:
        NetFactory();

        ~NetFactory() override = default;

    private:
        void
        _registerBuildables(std::unordered_map<std::string, FactoryLambda> &buildables) override;


//////////////////////--------------------------/////////////////////////



///////////////////////////// PROPERTIES ////////////////////////////////
    public:


    private:


//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
    public:


    private:


//////////////////////--------------------------/////////////////////////

    };
}