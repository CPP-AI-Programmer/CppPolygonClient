#include "CppPolygonClient/client.hpp"

// TODO: Format this code
// -------------------------------- Base Client -------------------------------- //
// ---------------- Special Methods ---------------- //
polygon_client::Client::Client(std::string api_key) : api_key(api_key) {}

// ---------------- Refenece Data ---------------- //
nlohmann::json polygon_client::Client::market_status() {
    return nlohmann::json::parse(
        cpr::Get(
            cpr::Url{
                "https://api.polygon.io/v1/marketstatus/now?apiKey=" + this->api_key
            }
        ).text
    );
}

// ---------------- Market Data ---------------- //
// ------------ Level 1 ------------ //
nlohmann::json polygon_client::Client::Aggregates(
    std::string ticker,
    std::string multiplier,
    std::string timespan,
    std::string from,
    std::string to,
    std::string adjusted, // optional
    std::string sort, // optional
    std::string limit
) {
    return nlohmann::json::parse(
        cpr::Get(
            cpr::Url{
                "https://api.polygon.io/v2/aggs/ticker/" 
                + ticker 
                + "/range/" + multiplier + "/" 
                + timespan + "/"
                + from + "/"
                + to
                + "?adjusted=" + adjusted
                + "&sort=" + sort
                + "&limit=" + limit
                + "&apiKey=" + this->api_key
            }
        ).text
    );
}
nlohmann::json polygon_client::Client::previous_close(std::string ticker, std::string adjusted) {
    return nlohmann::json::parse(
        cpr::Get(
            cpr::Url{
                "https://api.polygon.io/v2/aggs/ticker/"
                +ticker
                +"/prev?adjusted="+adjusted+"&apiKey=" + this->api_key
            }
        ).text
    );
}
