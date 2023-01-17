/*
** EPITECH PROJECT, 2022
** ComponentFactory.cpp
** File description:
** ComponentFactory.cpp
*/

#include "../include/ComponentFactory.hpp"
#include <TcpClientScriptImpl.hpp>
#include <TcpServerScriptImpl.hpp>
#include <UdpClientScriptImpl.hpp>
#include <UdpServerScriptImpl.hpp>

polymorph::engine::api::NetFactory::NetFactory() : AComponentFactory()
{
}

void polymorph::engine::api::NetFactory::_registerBuildables(
        std::unordered_map<std::string, polymorph::engine::api::AComponentFactory::FactoryLambda> &buildables)
{
    buildables.emplace("TcpClient", make<polymorph::engine::network::TcpClientScriptImpl>());
    buildables.emplace("TcpServer", make<polymorph::engine::network::TcpServerScriptImpl>());
    buildables.emplace("UdpClient", make<polymorph::engine::network::UdpClientScriptImpl>());
    buildables.emplace("UdpServer", make<polymorph::engine::network::UdpServerScriptImpl>());
}