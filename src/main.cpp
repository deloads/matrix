#include <iostream>
#include "matrix.hpp"

int main(){

    Matrix<int> matrix;


    matrix.setSize({10,10});
    matrix.set({3,3},1);

    for(int y = 0; y < matrix.size.y; y++){
        for(int x = 0; x < matrix.size.x; x++){
            std::cout << matrix.get({x,y}) << ' ';
        }

        std::cout << std::endl;
    }

    std::cout << std::endl;

    std::cout << "Capacity: " << matrix.capacity.x << ' ' << matrix.capacity.y << std::endl;
    std::cout << "Size: " << matrix.size.x << ' ' << matrix.size.y << std::endl;
    return 0;
}