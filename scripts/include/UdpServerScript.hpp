/*
** EPITECH PROJECT, 2020
** UdpServerScript.hpp
** File description:
** header for UdpServerScript.c
*/

#pragma once

#include "polymorph/engine/core.hpp"
#include "polymorph/network/udp/Server.hpp"

namespace polymorph::engine::network {

    class UdpServerScript;

    using UdpServer = safe_ptr<UdpServerScript>;
    using UdpServerBase = std::shared_ptr<UdpServerScript>;

    class UdpServerScript : public AComponent {

        ////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////

    public:
        explicit UdpServerScript(std::shared_ptr<myxmlpp::Node> node, GameObject gameObject)
            : AComponent(node, gameObject) {};

        virtual ~UdpServerScript() = default;


        //////////////////////--------------------------/////////////////////////



        ///////////////////////////// PROPERTIES ////////////////////////////////
    public:
        int port;

        std::map<int, bool> safetiesMapping;

    protected:
        std::unique_ptr<polymorph::network::udp::Server> _server;

        //////////////////////--------------------------/////////////////////////



        /////////////////////////////// METHODS /////////////////////////////////
    public:

        virtual void startServer() = 0;

        virtual std::uint16_t getRunningPort() = 0;

        virtual polymorph::network::SessionStore *getSessionStore() = 0;

        virtual void setSessionStore(polymorph::network::SessionStore *sessionStore) = 0;

        virtual void copyTcpSessionsFrom(polymorph::network::SessionStore *sessionStore) = 0;

        virtual void copyUdpSessionsFrom(polymorph::network::SessionStore *sessionStore) = 0;

        virtual void copyTcpAuthorizationKeysFrom(polymorph::network::SessionStore *sessionStore) = 0;

        virtual void copyUdpAuthorizationKeysFrom(polymorph::network::SessionStore *sessionStore) = 0;

        virtual polymorph::network::AuthorizationKey generateTcpAuthorizationKey(polymorph::network::SessionId sessionId) = 0;

        virtual polymorph::network::AuthorizationKey generateUdpAuthorizationKey(polymorph::network::SessionId sessionId) = 0;

        template<typename T>
        void send(polymorph::network::OpId opId, T &data)
        {
            if (!_server)
                throw debug::ExceptionLogger("Cannot send message without instantiated server");
            _server->send<T>(opId, data);
        }

        template<typename T>
        void registerReceiveHandler(polymorph::network::OpId opId,
                                    std::function<int(const polymorph::network::PacketHeader &, const T &)> handler)
        {
            if (!_server)
                throw debug::ExceptionLogger("Cannot register receive handler without instantiated server");
            _server->registerReceiveHandler<T>(opId, handler);
        }

        template<typename T>
        void sendTo(polymorph::network::OpId opId, T &data,
                    polymorph::network::SessionId sessionId,
                    std::function<void(const polymorph::network::PacketHeader &, const T &)> callback = nullptr)
        {
            if (!_server)
                throw debug::ExceptionLogger("Cannot send message without instantiated server");
            _server->sendTo<T>(opId, data, sessionId, callback);
        }

        virtual void unregisterReceiveHandlers(polymorph::network::OpId opId) = 0;

    private:


        //////////////////////--------------------------/////////////////////////

    };
}