/*
** EPITECH PROJECT, 2020
** UdpServerScriptImpl.hpp
** File description:
** header for UdpServerScriptImpl.c
*/

#pragma once

#include "UdpServerScript.hpp"

namespace polymorph::engine::network {

    class UdpServerScriptImpl : public UdpServerScript {

        ////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////

    public:
        explicit UdpServerScriptImpl(std::shared_ptr<myxmlpp::Node> node, GameObject gameObject)
            : UdpServerScript(node, gameObject) {};

        ~UdpServerScriptImpl() override = default;


        //////////////////////--------------------------/////////////////////////



        ///////////////////////////// PROPERTIES ////////////////////////////////
    public:


    private:


        //////////////////////--------------------------/////////////////////////



        /////////////////////////////// METHODS /////////////////////////////////
    public:

        void startServer() override;

        std::uint16_t getRunningPort() override;

        polymorph::network::SessionStore *getSessionStore() override;

        void setSessionStore(polymorph::network::SessionStore *sessionStore) override;

        void copyTcpSessionsFrom(polymorph::network::SessionStore *sessionStore) override;

        void copyUdpSessionsFrom(polymorph::network::SessionStore *sessionStore) override;

        void copyTcpAuthorizationKeysFrom(polymorph::network::SessionStore *sessionStore) override;

        void copyUdpAuthorizationKeysFrom(polymorph::network::SessionStore *sessionStore) override;

        polymorph::network::AuthorizationKey generateTcpAuthorizationKey(polymorph::network::SessionId sessionId) override;

        polymorph::network::AuthorizationKey generateUdpAuthorizationKey(polymorph::network::SessionId sessionId) override;

        void unregisterReceiveHandlers(polymorph::network::OpId opId) override;


    private:


        //////////////////////--------------------------/////////////////////////

    };
}