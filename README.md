# C++ CLI Projects

This repository includes some of the projects I have written in C++. So far the repository includes the following projects:

## Number Base Converter

This is the first project I have worked on using C++. It is a simple CLI app that takes in a number, its base and the base it will be converted to, and outputs the number in the desired base.

Usage: (./)convertnum [base from] [base to] [number]

This project allowed me to get familiar with the standard C++ libraries and also with the Makefile concept.

The source code of this project can be found under the folder [**num-converter**](./num-converter).

## Currency Converter

This is the project I have worked on after the **Number Base Converter**. This is another CLI app that takes in a number, its currency and the currency it will be converted to, and outputs the number in the given currency using the latest exchange rates.

Usage: (./)convertcur [currency from] [currency to] [number]

For help text or to see the supported currencies: (./)convertcur help

With this project, I was able to practice how to use third party C++ libraries, especially to make an HTTP request to an API to get the latest exchange rates and to parse the response JSON to access the desired currency's rate. I also used CMake to be able to successfully compile the source code and link the third party libraries.

The source code of this project can be found under the folder [**currency-converter**](./currency-converter).

Depedencies:

- [cURLpp](https://github.com/jpbarrette/curlpp)
- [jsoncpp](https://github.com/open-source-parsers/jsoncpp)
- [Cmake](https://cmake.org/cmake/help/v3.20/guide/tutorial/index.html)

**Note:** These projects are developed on **Linux**. Therefore, especially for the currency converter, CMake might not be able to work properly due to third party libraries being installed to different paths, or not being installed at all.