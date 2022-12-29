/*
** EPITECH PROJECT, 2020
** TcpClientScriptImpl.hpp
** File description:
** header for TcpClientScriptImpl.c
*/

#pragma once

#include "TcpClientScript.hpp"

namespace polymorph::engine::network
{


    class TcpClientScriptImpl : public TcpClientScript {

        ////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////

    public:
        explicit TcpClientScriptImpl(std::shared_ptr<myxmlpp::Node> node, GameObject gameObject);

        ~TcpClientScriptImpl() override = default;


        //////////////////////--------------------------/////////////////////////



        ///////////////////////////// PROPERTIES ////////////////////////////////



        //////////////////////--------------------------/////////////////////////



        /////////////////////////////// METHODS /////////////////////////////////
    public:
        void connect(std::function<void(bool, polymorph::network::SessionId)> callback) override;
        void connectWithSession(polymorph::network::SessionId session, polymorph::network::AuthorizationKey authKey,
                                std::function<void(bool, polymorph::network::SessionId)> callback) override;

        void unregisterReceiveHandlers(polymorph::network::OpId opId) override;


    private:
        void _createClient();


        //////////////////////--------------------------/////////////////////////

    };
}