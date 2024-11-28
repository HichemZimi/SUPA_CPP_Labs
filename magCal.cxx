#include <iostream>
#include <fstream>
#include <cmath>
#include <sstream>
#include <string>
#include "magCal.h"

void magCal(const std::string& filePath) {
    std::ifstream inputFile(filePath);

    // Check if the file was opened successfully
    if (!inputFile) {
        std::cerr << "Error: Could not open the file!" << std::endl;
        return;
    }

    std::string line;
    bool isFirstLine = true;

    // open the output file
    std::ofstream outputFile("magCal_output.txt");

    // check if the output file opened successfully
    if(!outputFile) {
        std::cerr<<"Error: Could not open output file!" <<std::endl;
        return;
    }

    // Loop through each line in the file
    while (std::getline(inputFile, line)) {
        // Skip the first row (header)
        if (isFirstLine) {
            isFirstLine = false;
            continue;
        }

        // Create a string stream to process each line
        std::stringstream ss(line);
        std::string value;

        float x = 0, y = 0;

        // Read the values from the comma-separated line
        if (std::getline(ss, value, ',')) { // Read x value
            x = std::stof(value); // Convert string to float
        }
        if (std::getline(ss, value, ',')) { // Read y value
            y = std::stof(value); // Convert string to float
        }

        // Calculate the magnitude for the pair (x, y)
        float magnitude = std::sqrt(x * x + y * y);
        std::cout << "Magnitude of (" << x << ", " << y << ") = " << magnitude << std::endl;

        // output the magnitude to console
        std::cout<<"Magnitude of("<<x<<", "<<y<<") = " <<  magnitude<<std::endl;

        // save the result of the file:
        outputFile <<"Magnitude of("<<x<<", "<<y<<") = " <<  magnitude<<std::endl;
    }

    inputFile.close();
    outputFile.close();
}