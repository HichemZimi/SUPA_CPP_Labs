#include <iostream>
#include <cmath>
int main (){
    // the inputs by the user
    double x, y;
    
    std::cout<<"Enter the value of x: ";
    std::cin>>x;
    std::cout<<"Enter the value of y: ";
    std::cin>>y;
    
    // Calculating the magnitude
    double M=std::sqrt(x*x+y*y);

    // result
    std::cout<<"the magnitude of the vector is: "<<M<<std::endl;
    return 0;
}