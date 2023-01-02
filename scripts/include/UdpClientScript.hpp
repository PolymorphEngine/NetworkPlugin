/*
** EPITECH PROJECT, 2020
** UdpClientScript.hpp
** File description:
** header for UdpClientScript.c
*/

#pragma once

#include "polymorph/engine/core.hpp"
#include "polymorph/network/udp/Client.hpp"

namespace polymorph::engine::network {

    class UdpClientScript;

    using UdpClient = safe_ptr<UdpClientScript>;
    using UdpClientBase = std::shared_ptr<UdpClientScript>;

    class UdpClientScript : public AComponent {

        ////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////

    public:
        explicit UdpClientScript(std::shared_ptr<myxmlpp::Node> node, GameObject gameObject)
            : AComponent(node, gameObject) {};

        virtual ~UdpClientScript() = default;


        //////////////////////--------------------------/////////////////////////



        ///////////////////////////// PROPERTIES ////////////////////////////////
    public:
        int port;
        std::string host;

        std::map<int, bool> safetiesMapping;

    protected:
        std::unique_ptr<polymorph::network::udp::Client> _client;


        //////////////////////--------------------------/////////////////////////



        /////////////////////////////// METHODS /////////////////////////////////
    public:
        virtual void connect(std::function<void(bool status, polymorph::network::SessionId session)> callback) = 0;
        virtual void connectWithSession(polymorph::network::SessionId session,
                                        polymorph::network::AuthorizationKey authKey,
                                        std::function<void(bool, polymorph::network::SessionId session)> callback) = 0;

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