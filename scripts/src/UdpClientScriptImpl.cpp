/*
** EPITECH PROJECT, 2022
** UdpClientScriptImpl.cpp
** File description:
** UdpClientScriptImpl.cpp
*/

#include "UdpClientScriptImpl.hpp"

polymorph::engine::network::UdpClientScriptImpl::UdpClientScriptImpl(GameObject gameObject, std::shared_ptr<myxmlpp::Node> node)
        : UdpClientScript(node, gameObject)
{
}

void polymorph::engine::network::UdpClientScriptImpl::connect(
        std::function<void(bool, polymorph::network::SessionId)> callback)
{
    Debug.log("Connecting with UdpClientScriptImpl on " + host + ":" + std::to_string(port) + "...", debug::Logger::INFO);
    try {
        _createClient();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        callback(false, 0);
        return;
    }
    _client->connect(callback);
}

void polymorph::engine::network::UdpClientScriptImpl::connectWithSession(
        polymorph::network::SessionId session,
        polymorph::network::AuthorizationKey authKey,
        std::function<void(bool, polymorph::network::SessionId)> callback)
{
    Debug.log("Connecting (using session) with UdpClientScriptImpl on " + host + ":" + std::to_string(port) + "...", debug::Logger::INFO);
    try {
        _createClient();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        callback(false, 0);
        return;
    }
    _client->connectWithSession(session, authKey, callback);
}

void polymorph::engine::network::UdpClientScriptImpl::_createClient()
{
    std::map<polymorph::network::OpId, bool> safeties;
    std::transform(safetiesMapping.begin(), safetiesMapping.end(), std::inserter(safeties, safeties.begin()),
                   [](const std::pair<int, bool> &pair) {
                       return std::make_pair(static_cast<polymorph::network::OpId>(pair.first), pair.second);
                   });
    _client = polymorph::network::udp::Client::create(host, static_cast<std::uint16_t>(port), safeties);
}

void polymorph::engine::network::UdpClientScriptImpl::unregisterReceiveHandlers(polymorph::network::OpId opId)
{
    _client->unregisterReceiveHandlers(opId);
}

void polymorph::engine::network::UdpClientScriptImpl::build()
{
    _setProperty("host", host);
    _setProperty("port", port);
    _setProperty("safeties", safetiesMapping);
}

void polymorph::engine::network::UdpClientScriptImpl::saveAll()
{
    saveProperty("host", host);
    saveProperty("port", port);
    //saveProperty("safeties", safetiesMapping);
}
