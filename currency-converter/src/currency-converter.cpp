#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>

int main (int argc, char **argv) {

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
        int number = std::stoi(arguments[2], nullptr, 10);

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

        std::cout << response << std::endl;

        return EXIT_SUCCESS;
    }
    catch (const std::exception & e) {
        std::cerr << "Last argument must be a number!" << std::endl;
        return EXIT_FAILURE;
    }
}