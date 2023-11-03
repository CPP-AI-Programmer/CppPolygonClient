cmake_minimum_required(VERSION 3.22) # the version i am using
project(CppPolygonClient VERSION 1.0.0)

include(GNUInstallDirs) 

include(FetchContent)
# get cpr
# to speed up the program it is probably worth trying to use cURL and rapid_json (or another fast parser)
# install third party packages
include(FetchContent)
# Handle Json Config and Response Data
FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.2/json.tar.xz)
FetchContent_MakeAvailable(json)
# Handle Requests:
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
                         GIT_TAG 0817715923c9705e68994eb52ef9df3f6845beba) # The commit hash for 1.10.x. Replace with the latest from: https://github.com/libcpr/cpr/releases
FetchContent_MakeAvailable(cpr)

add_subdirectory(src)
add_subdirectory(include)