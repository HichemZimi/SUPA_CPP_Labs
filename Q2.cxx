#include <iostream>
#include <cmath>
int main (){
    
    double x=2.3; 
    double y=4.5;
    
    // Calculating the magnitude
    double M=std::sqrt(x*x+y*y);

    // result
    std::cout<<"the magnitude of the vector is: "<<M<<std::endl;
    return 0;
}