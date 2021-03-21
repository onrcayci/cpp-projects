#include <iostream>
#include <vector>
#include <string>

#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>

int main (int argc, char **argv) {

    // check if the required arguments are provided
    // 4 = command + currency from + currency to + number
    if (argc < 4) {
        std::cerr << "Missing arguments! Usage\nconvertcur <currency from> <currency to> <number>" << std::endl;
        return EXIT_FAILURE;
    }

    // Convert arguments into string
    std::vector<std::string> arguments;
    for (int i = 1; i <argc; i++) {
        arguments.push_back(argv[i]);
    }

    try {
        
        // convert the number to int format
        // will throw an exception if the argument is not a number
        int number = std::stoi(arguments[2], nullptr, 10);
    }
    catch (const std::exception & e) {
        std::cerr << e.what() << '\n';
    }
}