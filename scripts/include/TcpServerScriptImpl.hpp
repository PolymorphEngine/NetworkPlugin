/*
** EPITECH PROJECT, 2020
** TcpServerScriptImpl.hpp
** File description:
** header for TcpServerScriptImpl.c
*/

#pragma once

#include "TcpServerScript.hpp"

namespace polymorph::engine::network {

    class TcpServerScriptImpl : public TcpServerScript {

        ////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////

    public:
        explicit TcpServerScriptImpl(GameObject gameObject, std::shared_ptr<myxmlpp::Node> node)
            : TcpServerScript(node, gameObject) {};

        ~TcpServerScriptImpl() override = default;

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

        void build() override;

        void saveAll() override;

    private:


        //////////////////////--------------------------/////////////////////////

    };
}