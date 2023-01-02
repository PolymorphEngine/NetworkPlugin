cmake_minimum_required(VERSION 3.17)

if (NOT TARGET PolymorphNetwork)
    include(FetchContent)
    FetchContent_Declare(
            PolymorphNetwork
            GIT_REPOSITORY https://github.com/PolymorphEngine/NetworkLibrary.git
            GIT_TAG        master
    )
    FetchContent_MakeAvailable(PolymorphNetwork)
    get_target_property(PolymorphNetwork-icls PolymorphNetwork INTERFACE_INCLUDE_DIRECTORIES)
endif()