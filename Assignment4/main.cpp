/* 
 * File:   main.cpp
 * Author: norman
 *
 * Created on February 6, 2013, 10:50 PM
 */

#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    map<string, int> counts;
    int moreThanHalf;
    string element;
    string majElem;
    moreThanHalf = (argc-1)/2 + 1;
    
    for(int i = 1; i< argc; ++i){
        element = argv[i];
        pair< map< string, int >::iterator, bool > ret;
        ret = counts.insert(pair<string, int>(element,1));
        if(ret.second == false){
            ++ret.first->second;
        }
    }
    map<string, int>::iterator it;
    it = counts.begin();
    int max = 0;
    while(it != counts.end()){
        if(it->second > max && it->second >=moreThanHalf){
            majElem = it->first;
            max = it->second;
        }
        ++it;
    }
    
    cout << majElem << " : " << max << endl;
    return 0;
}

