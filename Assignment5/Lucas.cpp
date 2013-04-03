/* 
 * File:   Lucas.cpp
 * Author: norman
 * 
 * Created on February 28, 2013, 9:52 PM
 */

#include "Lucas.h"
#include <cmath>
#include <iostream>

Lucas::Lucas() {
}

Lucas::Lucas(const Lucas& orig) {
}

Lucas::~Lucas() {
}

int Lucas::findLucas(const unsigned int N, const int current){
    if(Lucas::LucasHolder.size() > (N + 1))
        return Lucas::LucasHolder[N];
    
//    std::cout << Lucas::LucasHolder.size() - 1 << " " << 
//            Lucas::LucasHolder[Lucas::LucasHolder.size()-1] << "\n";
    
    Lucas::LucasHolder.push_back(Lucas::LucasHolder[current -1] +
            Lucas::LucasHolder[current-2]);
    findLucas(N, current + 1);
    
}

int Lucas::output(int lucas, int N){
    return (N < 0) && (N % 2 != 0) ? -lucas : lucas;
}

