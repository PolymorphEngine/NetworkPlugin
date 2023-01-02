/*
** EPITECH PROJECT, 2022
** TcpClientScriptImpl.cpp
** File description:
** TcpClientScriptImpl.cpp
*/

#include "TcpClientScriptImpl.hpp"

polymorph::engine::network::TcpClientScriptImpl::TcpClientScriptImpl(GameObject gameObject, std::shared_ptr<myxmlpp::Node> node)
        : TcpClientScript(node, gameObject)
{
}

void polymorph::engine::network::TcpClientScriptImpl::connect(
        std::function<void(bool, polymorph::network::SessionId)> callback)
{
    try {
        _createClient();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        callback(false, 0);
        return;
    }
    _client->connect(callback);
}

void polymorph::engine::network::TcpClientScriptImpl::connectWithSession(
        polymorph::network::SessionId session,
        polymorph::network::AuthorizationKey authKey,
        std::function<void(bool, polymorph::network::SessionId)> callback)
{
    try {
        _createClient();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        callback(false, 0);
        return;
    }
    _client->connectWithSession(session, authKey, callback);
}

void polymorph::engine::network::TcpClientScriptImpl::_createClient()
{
    _client = polymorph::network::tcp::Client::create(host, static_cast<std::uint16_t>(port));
}

void polymorph::engine::network::TcpClientScriptImpl::unregisterReceiveHandlers(polymorph::network::OpId opId)
{
    _client->unregisterReceiveHandlers(opId);
}

void polymorph::engine::network::TcpClientScriptImpl::build()
{
    _setProperty("host", host);
    _setProperty("port", port);
}

void polymorph::engine::network::TcpClientScriptImpl::saveAll()
{
    saveProperty("host", host);
    saveProperty("port", port);
}
