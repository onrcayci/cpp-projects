#include <iostream>
#include <string>
#include <vector>

// TODO: Add support for negative numbers in v0.0.3

int main(int argc, char **argv) {

    // check if the required arguments provided
    // 4 = command + base from + base to + number
    if (argc < 4) {
        std::cerr << "Required arguments are missing! Usage:\nconvertnum <number> <base from> <base to>" << std::endl;
        return EXIT_FAILURE;
    }

    // convert the command line arguments into string format
    std::vector<std::string> arguments;
    for (int i = 1; i < argc; i++) {
        arguments.push_back(argv[i]);
    }

    // check if the given arguments are numbers
    try {

        // convert arguments into integers
        int basefrom = std::stoi(arguments[0], nullptr, 10);
        int baseto = std::stoi(arguments[1], nullptr, 10);
        int number = std::stoi(arguments[2], nullptr, basefrom);

        // initialize the character array that will be used to construct the new number
        std::string digits = "0123456789abcedfghijklmnopqrstuvwxyz";

        // convert the number to the given base
        std::string result;
        while(number >= baseto) {
            int remainder = number % baseto;
            number /= baseto;
            result = digits[remainder] + result;
        }

        // add the last remainder to the result string
        result = digits[number] + result;

        // print out the result
        std::cout << result << std::endl;
        return EXIT_SUCCESS;
    }
    catch (const std::exception & e) {
        std::cerr << "Arguments must be numbers!" << std::endl;
        return EXIT_FAILURE;
    }
}