/*
** EPITECH PROJECT, 2020
** TcpClientScript.hpp
** File description:
** header for TcpClientScript.c
*/

#pragma once

#include "polymorph/engine/core.hpp"
#include "polymorph/network/tcp/Client.hpp"

namespace polymorph::engine::network {

    class TcpClientScript;

    using TcpClient = safe_ptr<TcpClientScript>;
    using TcpClientBase = std::shared_ptr<TcpClientScript>;

    class TcpClientScript : public AComponent {

        ////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////

    public:
        explicit TcpClientScript(std::shared_ptr<myxmlpp::Node> node, GameObject gameObject)
            : AComponent(node, gameObject) {};

        virtual ~TcpClientScript() = default;


        //////////////////////--------------------------/////////////////////////



        ///////////////////////////// PROPERTIES ////////////////////////////////
    public:
        std::string host;
        int port;

    protected:
        std::unique_ptr<polymorph::network::tcp::Client> _client;


        //////////////////////--------------------------/////////////////////////



        /////////////////////////////// METHODS /////////////////////////////////
    public:
        virtual void connect(std::function<void(bool, polymorph::network::SessionId)> callback) = 0;
        virtual void connectWithSession(polymorph::network::SessionId session, polymorph::network::AuthorizationKey authKey,
                                        std::function<void(bool, polymorph::network::SessionId)> callback) = 0;

        template<typename T>
        void send(polymorph::network::OpId opId, T &payload,
                  std::function<void(const polymorph::network::PacketHeader &, const T &)> callback = nullptr)
        {
            if (!_client)
                throw debug::ExceptionLogger("Cannot send message without instantiated client");
            _client->send<T>(opId, payload, callback);
        }

        template<typename T>
        void registerReceiveHandler(polymorph::network::OpId opId,
                                    std::function<int(const polymorph::network::PacketHeader &, const T &)> handler)
        {
            if (!_client)
                throw debug::ExceptionLogger("Cannot register receive handler without instantiated client");
            _client->registerReceiveHandler<T>(opId, handler);
        }

        virtual void unregisterReceiveHandlers(polymorph::network::OpId opId) = 0;

        //////////////////////--------------------------/////////////////////////

    };
}