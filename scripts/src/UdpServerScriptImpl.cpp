/*
** EPITECH PROJECT, 2022
** UdpServerScriptImpl.cpp
** File description:
** UdpServerScriptImpl.cpp
*/

#include "UdpServerScriptImpl.hpp"

void polymorph::engine::network::UdpServerScriptImpl::startServer()
{
    std::map<polymorph::network::OpId, bool> safeties;
    std::transform(safetiesMapping.begin(), safetiesMapping.end(), std::inserter(safeties, safeties.begin()),
                   [](const std::pair<int, bool> &pair) {
                       return std::make_pair(static_cast<polymorph::network::OpId>(pair.first), pair.second);
                   });
    _server = polymorph::network::udp::Server::create(static_cast<std::uint16_t>(port), safeties);
    _server->start();
}

std::uint16_t polymorph::engine::network::UdpServerScriptImpl::getRunningPort()
{
    return _server->getRunningPort();
}

polymorph::network::SessionStore *polymorph::engine::network::UdpServerScriptImpl::getSessionStore()
{
    return _server->getSessionStore();
}

void polymorph::engine::network::UdpServerScriptImpl::setSessionStore(polymorph::network::SessionStore *sessionStore)
{
    _server->setSessionStore(sessionStore);
}

void polymorph::engine::network::UdpServerScriptImpl::copyTcpSessionsFrom(polymorph::network::SessionStore *sessionStore)
{
    _server->copyTcpSessionsFrom(sessionStore);
}

void polymorph::engine::network::UdpServerScriptImpl::copyUdpSessionsFrom(polymorph::network::SessionStore *sessionStore)
{
    _server->copyUdpSessionsFrom(sessionStore);
}

void polymorph::engine::network::UdpServerScriptImpl::copyTcpAuthorizationKeysFrom(polymorph::network::SessionStore *sessionStore)
{
    _server->copyTcpAuthorizationKeysFrom(sessionStore);
}

void polymorph::engine::network::UdpServerScriptImpl::copyUdpAuthorizationKeysFrom(polymorph::network::SessionStore *sessionStore)
{
    _server->copyUdpAuthorizationKeysFrom(sessionStore);
}

polymorph::network::AuthorizationKey polymorph::engine::network::UdpServerScriptImpl::generateTcpAuthorizationKey(polymorph::network::SessionId sessionId)
{
    return _server->generateTcpAuthorizationKey(sessionId);
}

polymorph::network::AuthorizationKey polymorph::engine::network::UdpServerScriptImpl::generateUdpAuthorizationKey(polymorph::network::SessionId sessionId)
{
    return _server->generateUdpAuthorizationKey(sessionId);
}

void polymorph::engine::network::UdpServerScriptImpl::unregisterReceiveHandlers(polymorph::network::OpId opId)
{
    _server->unregisterReceiveHandlers(opId);
}

void polymorph::engine::network::UdpServerScriptImpl::build()
{
    _setProperty("port", port);
    _setProperty("safetiesMapping", safetiesMapping);
}

void polymorph::engine::network::UdpServerScriptImpl::saveAll()
{
    saveProperty("port", port);
    //saveProperty("safetiesMapping", safetiesMapping);
}
