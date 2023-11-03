#include "CppPolygonClient/client.hpp"

// -------------------------------- Stock Client -------------------------------- //
// ------------ Special Methods ------------ //
polygon_client::StockClient::StockClient(std::string api_key) : Client(api_key) {}

// ------------ Level 2 ------------ //
// -------- Trades -------- //
cpr::Response polygon_client::StockClient::Trades(
    std::string ticker,
    std::string order,
    std::string limit, 
    std::string sort
) {
    return cpr::Get(
        cpr::Url{
            "https://api.polygon.io/v3/trades/"
            +ticker 
            +"?order="+ order 
            +"&limit="+ limit
            +"&sort="+ sort
            +"&apiKey=" + this->api_key
        }
    );
}
cpr::Response polygon_client::StockClient::Trades(
    std::string ticker,
    std::string order,
    std::string limit, 
    std::string sort,
    std::string timestamp
) {
    return cpr::Get(
        cpr::Url{
            "https://api.polygon.io/v3/trades/"
            +ticker 
            +"?timestamp="+timestamp
            +"&order="+ order 
            +"&limit="+ limit
            +"&sort="+ sort
            +"&apiKey=" + this->api_key
        }
    );
}

cpr::Response polygon_client::StockClient::Last_Trade(std::string ticker) {
    return cpr::Get(
        cpr::Url{
            "https://api.polygon.io/v2/last/trade/" + ticker + "?apiKey=" + this->api_key
        }
    );
}

// -------- Quotes -------- //
cpr::Response polygon_client::StockClient::Quotes(
    std::string ticker,
    std::string order,
    std::string limit,
    std::string sort
) {
    return cpr::Get(
        cpr::Url{
            "https://api.polygon.io/v3/quotes/"+ticker
            +"?order="+order+"&limit="+limit+"&sort="+sort+"&apiKey=" + this->api_key
        }
    );
}
cpr::Response polygon_client::StockClient::Quotes(
    std::string ticker,
    std::string order,
    std::string limit,
    std::string sort,
    std::string timestamp
) {
    return cpr::Get(
        cpr::Url{
            "https://api.polygon.io/v3/quotes/"+ticker
            +"?timestamp="+timestamp
            +"&order="+order
            +"&limit="+limit
            +"&sort="+sort
            +"&apiKey="+this->api_key
        }
    );
}
cpr::Response polygon_client::StockClient::Last_Quote(std::string ticker) {
    return cpr::Get(
        cpr::Url{
            "https://api.polygon.io/v2/last/nbbo/" + ticker + "?apiKey=" + this->api_key
        }
    );
}
