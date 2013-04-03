/* 
 * File:   main.cpp
 * Author: norman
 *
 * Created on February 27, 2013, 8:41 PM
 */

#include <cstdlib>
#include "Lucas.h"
#include <iostream>
#include <cmath>

using namespace std;

/*
 * Initialize static LucasHolder
 */
vector<int> Lucas::LucasHolder(1,2);

int main(int argc, char** argv) {
    Lucas::LucasHolder.push_back(1);
    Lucas lucas;
    
    if(argc != 2){
        cout << "Usage: " << argv[0] << " <integer> \n";
        exit (1);
    }
    
    int n = atoi(argv[1]);
    int output;
    
    //cout << "0 " << Lucas::LucasHolder[0] << "\n";
    
    if( abs(n) >= 1 )
        output = lucas.findLucas(abs(n),2);
    else
        output = Lucas::LucasHolder[abs(n)];
    
    cout << "Lucas(" << n << "): " << lucas.output(output, n) << ".\n";
    
    

    return 0;
}

