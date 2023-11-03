project(CppPolygonClient)


target_include_directories(CppPolygonClient PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)

target_sources(CppPolygonClient PRIVATE
    CppPolygonClient/client.hpp
    CppPolygonClient/wss_client.hpp
)

install(DIRECTORY CppPolygonClient DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})