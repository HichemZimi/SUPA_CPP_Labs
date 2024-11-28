// read and print data : RPData
#include <iostream>
#include <fstream>
#include <string>
#include "RPData.h"
void RPData(const std::string& filePath, int N){
std::ifstream inputFile(filePath);
// Check the file 
if (!inputFile){
    std::cerr<<"error: the file could not be opened!"<<std::endl;
    return;
}
std::string line;
int lineCount=0;
int totalLines=0;

// Total lines
while (std::getline(inputFile,line))
{
    totalLines++;
}
// the beginning
inputFile.clear();
inputFile.seekg(0,std::ios::beg);

// Larger N
if (N>totalLines)
{
    std::cout<<"warning: the file contains few than "<<N<<"lines."<<std::endl;
    std::cout<<"Displaying the first five lines instead: "<<std::endl;
    N=std::min(5, totalLines);
}
// read and print N lines
while (lineCount <N && std::getline(inputFile,line))
{
    std::cout<<line<<std::endl;
    lineCount++;
}
inputFile.close();

}
