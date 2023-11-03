project(CppPolygonClient)

add_library(CppPolygonClient SHARED
    client.cpp
    crypto.cpp
    forex.cpp
    indices.cpp  
    options.cpp  
    stock.cpp  
    wss_client.cpp
)
add_library(CppPolygonClient::CppPolygonClient ALIAS CppPolygonClient)

target_include_directories(CppPolygonClient SYSTEM PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/)
target_link_libraries(CppPolygonClient PUBLIC nlohmann_json::nlohmann_json cpr::cpr)

set_property(TARGET CppPolygonClient PROPERTY CXX_STANDARD 17)

install(
    TARGETS CppPolygonClient
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)