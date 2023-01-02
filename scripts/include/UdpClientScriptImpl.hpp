/*
** EPITECH PROJECT, 2020
** UdpClientScriptImpl.hpp
** File description:
** header for UdpClientScriptImpl.c
*/

#pragma once

#include "UdpClientScript.hpp"

namespace polymorph::engine::network
{

    class UdpClientScriptImpl : public UdpClientScript {

        ////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////

    public:
        explicit UdpClientScriptImpl(GameObject gameObject, std::shared_ptr<myxmlpp::Node> node);

        virtual ~UdpClientScriptImpl() = default;


        //////////////////////--------------------------/////////////////////////



        ///////////////////////////// PROPERTIES ////////////////////////////////
    public:


        //////////////////////--------------------------/////////////////////////



        /////////////////////////////// METHODS /////////////////////////////////
    public:
        void connect(std::function<void(bool status, polymorph::network::SessionId session)> callback);
        void connectWithSession(polymorph::network::SessionId session,
                                polymorph::network::AuthorizationKey authKey,
                                std::function<void(bool, polymorph::network::SessionId session)> callback);

        void unregisterReceiveHandlers(polymorph::network::OpId opId) override;

        void build() override;

        void saveAll() override;

    private:
        void _createClient();


        //////////////////////--------------------------/////////////////////////

    };
}