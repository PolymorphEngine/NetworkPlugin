/*
** EPITECH PROJECT, 2022
** TcpServerScriptImpl.cpp
** File description:
** TcpServerScriptImpl.cpp
*/

#include "TcpServerScriptImpl.hpp"

void polymorph::engine::network::TcpServerScriptImpl::startServer()
{
    _server = polymorph::network::tcp::Server::create(static_cast<std::uint16_t>(port));
    _server->start();
}

std::uint16_t polymorph::engine::network::TcpServerScriptImpl::getRunningPort()
{
    return _server->getRunningPort();
}

polymorph::network::SessionStore *polymorph::engine::network::TcpServerScriptImpl::getSessionStore()
{
    return _server->getSessionStore();
}

void polymorph::engine::network::TcpServerScriptImpl::setSessionStore(polymorph::network::SessionStore *sessionStore)
{
    _server->setSessionStore(sessionStore);
}

void polymorph::engine::network::TcpServerScriptImpl::copyUdpSessionsFrom(polymorph::network::SessionStore *sessionStore)
{
    _server->copyUdpSessionsFrom(sessionStore);
}

void polymorph::engine::network::TcpServerScriptImpl::copyTcpSessionsFrom(polymorph::network::SessionStore *sessionStore)
{
    _server->copyTcpSessionsFrom(sessionStore);
}

void polymorph::engine::network::TcpServerScriptImpl::copyUdpAuthorizationKeysFrom(polymorph::network::SessionStore *sessionStore)
{
    _server->copyUdpAuthorizationKeysFrom(sessionStore);
}

void polymorph::engine::network::TcpServerScriptImpl::copyTcpAuthorizationKeysFrom(polymorph::network::SessionStore *sessionStore)
{
    _server->copyTcpAuthorizationKeysFrom(sessionStore);
}

polymorph::network::AuthorizationKey polymorph::engine::network::TcpServerScriptImpl::generateUdpAuthorizationKey(polymorph::network::SessionId sessionId)
{
    return _server->generateUdpAuthorizationKey(sessionId);
}

polymorph::network::AuthorizationKey polymorph::engine::network::TcpServerScriptImpl::generateTcpAuthorizationKey(polymorph::network::SessionId sessionId)
{
    return _server->generateTcpAuthorizationKey(sessionId);
}

void polymorph::engine::network::TcpServerScriptImpl::unregisterReceiveHandlers(polymorph::network::OpId opId)
{
    _server->unregisterReceiveHandlers(opId);
}

void polymorph::engine::network::TcpServerScriptImpl::build()
{
    _setProperty("port", port);
}

void polymorph::engine::network::TcpServerScriptImpl::saveAll()
{
    saveProperty("port", port);
}
