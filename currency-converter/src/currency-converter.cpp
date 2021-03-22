#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>

#include <json/json.h>

int main (int argc, char **argv) {

    // check if the user would like to get the help text
    if (std::strcmp(argv[1], "help") == 0) {
        std::cout << "Currency conversion CLI App v0.0.1" << std::endl;
        std::cout << "Usage:\tconvertcur <currency from> <currency to> <number>" << std::endl;
        std::cout << "Supported Currencies:\nEUR, CAD, HKD, ISK, PHP, DKK, HUF, CZK, AUD, RON, SEK, IDR, INR, BRL, RUB, HRK, JPY, THB, CHF, SGD, PLN, BGN, TRY, CNY, NOK, NZD, ZAR, USD, MXN, ILS, GBP, KRW, MYR" << std::endl;
        return EXIT_SUCCESS;
    }
    
    // check if the required arguments are provided
    // 4 = command + currency from + currency to + number
    if (argc < 4) {
        std::cerr << "Missing arguments!\nUsage: convertcur <currency from> <currency to> <number>" << std::endl;
        return EXIT_FAILURE;
    }

    // Convert arguments into string
    std::vector<std::string> arguments;
    for (int i = 1; i <argc; i++) {
        arguments.push_back(argv[i]);
    }

    try {
        
        // convert number argument from string into integer
        std::string currencyFrom = arguments[0];
        std::string currencyTo = arguments[1];
        float number = std::stof(arguments[2]);

        std::cout << number << std::endl;

        // setup curlpp to get the latest exchange rates
        curlpp::Cleanup requestCleanup;
        curlpp::Easy request;

        // setup stringstream to access the response data
        std::stringstream JSONResponse;

        // set the URL
        request.setOpt<curlpp::Options::Url>("https://api.exchangeratesapi.io/latest?base=" + currencyFrom);

        // set write stream to access the response data
        request.setOpt(curlpp::Options::WriteStream(&JSONResponse));

        // send the request
        request.perform();

        // convert response into string
        std::string response = JSONResponse.str();

        // setup to parse JSON string
        // to save the error
        JSONCPP_STRING error;
        
        // to save the JSON
        Json::Value json;

        // to read the JSON string
        Json::CharReaderBuilder builder;
        const std::unique_ptr<Json::CharReader> reader(builder.newCharReader());

        // if an error occurs during parsing the JSON string
        if (!reader->parse(response.c_str(), response.c_str() + response.length(), &json, &error)) {
            std::cerr << error << std::endl;
            return EXIT_FAILURE;
        }

        // get the exchange rate of the currency that the number will be converted to
        float exchangeRate = json["rates"][currencyTo].asFloat();

        std::cout << exchangeRate << std::endl;

        // make the conversion
        float result = number * exchangeRate;

        std::cout << result << std::endl;

        return EXIT_SUCCESS;
    } catch (curlpp::LogicError & e) { 
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    } catch(curlpp::RuntimeError & e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    } catch (const std::exception & e) {
        std::cerr << "Last argument must be a number!" << std::endl;
        return EXIT_FAILURE;
    }
}