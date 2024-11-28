#include <iostream>
#include <string>
#include "RPData.h"
#include "magCal.h"
#include "chisquare.h"
#include "XYcalculation.h"

int main() {
    // Path to the file
    std::string filePath = "/workspaces/SUPA_CPP_Labs/Exercises2024/Ex1_2/input2D_float.txt";
    
    // Ask the user to input the number of lines to print
    int N;
    std::cout << "Enter the number of lines to print: ";
    std::cin >> N;

    // Calling readAndPrintData function to print first N lines
    RPData (filePath, N);

    // Calling CalculateMagnitude function to calculate magnitudes for each row in the file
    magCal(filePath);
    // Debug: Print data before fitting the line
    std::cout << "\nAttempting to fit a line to the data...\n";

    // Calling FitLineAndChiSquare function to fit a line and calculate Chi-squared
    try {
        chisquare(filePath);  // Calling the function
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;  // Output error message to standard error stream
    }

    // calling calculatexy function to calculate x power y 
    XYcalculation(filePath);

    return 0;
}
