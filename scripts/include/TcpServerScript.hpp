/*
** EPITECH PROJECT, 2020
** TcpServerScript.hpp
** File description:
** header for TcpServerScript.c
*/

#pragma once

#include "polymorph/engine/core.hpp"
#include "polymorph/network/tcp/Server.hpp"

namespace polymorph::engine::network {

    class TcpServerScript;

    using TcpServer = safe_ptr<TcpServerScript>;
    using TcpServerBase = std::shared_ptr<TcpServerScript>;

    class TcpServerScript : public AComponent {

        ////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////

    public:
        explicit TcpServerScript(std::shared_ptr<myxmlpp::Node> node, GameObject gameObject)
            : AComponent(node, gameObject) {};

        virtual ~TcpServerScript() = default;

        //////////////////////--------------------------/////////////////////////



        ///////////////////////////// PROPERTIES ////////////////////////////////
    public:
        int port;

    protected:
        std::unique_ptr<polymorph::network::tcp::Server> _server;


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