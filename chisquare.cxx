#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include "chisquare.h"
void chisquare(const std::string& filePath){
std::ifstream inputFile(filePath);
// Check the file 
if (!inputFile){
    std::cerr<<"error: the file could not be opened!"<<std::endl;
    return;
}
std::vector< std::pair<double, double>>data; // storing the (x,y) pair
std::string line;
// skip the header
std::getline(inputFile, line);
 
// reading the data
while (std::getline(inputFile, line))
{
    std::stringstream ss(line);
    double x,y;
    char comma;
    if (ss>>x>>comma>>y){
        data.push_back({x, y});
    } else {
        std::cerr<<"Error: invalid data format in line: "<<std::endl;
        return;
    }
}
// if no data found 
if (data.empty())
{
    std::cerr<<"Error: no data to process!"<<std::endl;
        return;
}
// perform the least squares fitting
double sum_x=0, sum_y=0, sum_xx=0, sum_xy=0;
int N = data.size();
for (const auto& pair:data){
    sum_x += pair.first;
    sum_y += pair.second;
    sum_xx += pair.first * pair.first;
    sum_xy += pair.first * pair.second;
}
double p = (N * sum_xy - sum_x * sum_y) / ( N * sum_xx - sum_x * sum_x);
double q= (sum_y * sum_xx - sum_x * sum_xy) / (N * sum_xx - sum_x * sum_x);

// create the file 
std::ofstream outputFile("chisquare_output.txt");

// check if the ile can be opened 
if (!inputFile){
    std::cerr<<"error: the file could not be opened!"<<std::endl;
    return;
}
// the line of the best fit anf chi-square 
outputFile << "line of best fit: y = "<<p<< "x + "<<q<< std::endl;
// testing the chi-square
double chi_square =0;
for (const auto& pair: data)
{
    double expected_y= p * pair.first + q;
    chi_square += std::pow(pair.second - expected_y, 2) / expected_y;
}
// the out put value 
outputFile << "chi-square: "<< chi_square<<std::endl;
outputFile.close(); // close thye file 
}