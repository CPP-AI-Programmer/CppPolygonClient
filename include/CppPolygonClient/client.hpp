#pragma once
// std
#include <string>

// Third Party:
// requests
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>

// local
#include "CppPolygonClient/wss_client.hpp"


namespace polygon_client {

    // NOTICE: these classes are not safe for polymorphism

    // functions all clients will have
    class Client {
    public:
        // __VARIABLES__ //
        std::string api_key;

        // __METHODS__ //
        // ---------------- Special Methods ---------------- //
        Client(std::string api_key);
        // ---------------- Refenece Data ---------------- //
        nlohmann::json market_status();
        // Market Holdidays
        // Tickers
        
        // ---------------- Market Data ---------------- //
        // ------------ Level 1 ------------ //
        nlohmann::json Aggregates(
            std::string ticker,
            std::string multiplier,
            std::string timespan,
            std::string from,
            std::string to,
            std::string adjusted = "true", // optional
            std::string sort = "desc", // optional
            std::string limit = "120" // optional
        ); 
        nlohmann::json previous_close(std::string ticker, std::string adjusted = "true");

    };

    // functions specific to the StockClient
    class StockClient : public Client {
    public:
        StockClient(std::string api_key);
        // ---------------- Market Data ---------------- //
        // ------------ Level 1 ------------ //
        // Grouped Daily Barse
        // Daily Open/Close
        // -------- Technical Indicators (calculated by polygon) -------- //
        // SMA 
        // EMA
        // MACD
        // RSI

        // ------------ Level 2 ------------ //
        // -------- Trades -------- //
        nlohmann::json Trades(
            std::string ticker,
            std::string order,
            std::string limit, 
            std::string sort
        );
        nlohmann::json Trades(
            std::string ticker,
            std::string order,
            std::string limit,
            std::string sort, 
            std::string timestamp
        );
        nlohmann::json Last_Trade(std::string ticker);
        // -------- Quotes -------- //
        nlohmann::json Quotes(
            std::string ticker,
            std::string order,
            std::string limit,
            std::string sort
        );
        nlohmann::json Quotes(
            std::string ticker,
            std::string order,
            std::string limit,
            std::string sort,
            std::string timestamp
        );
        nlohmann::json Last_Quote(std::string ticker);

        // ---------------- Reference Data ---------------- //
        // Tickers
        // Ticker Details V3
        // Ticker Events
        // Ticker News
        // Ticker Types
        // Stock Splits V3
        // Dividends V3
        // Stock Financials VX
        // Conditions 
        // Exchanges
    };
    // TODO: Implement more clients:
    // forex client (child of current client)
    // crypto client (child of current client)
    // options client (this could be a child of StockClient most likely?)
    // indices client (could be similar stock)

}