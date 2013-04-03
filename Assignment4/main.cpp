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
    int max = 0;
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
        if(ret.first->second > max && ret.first->second >=moreThanHalf){
            max = ret.first->second;
	    majElem = ret.first->first;
            break;
        }
    }
    if(majElem != "")
        cout << "The majority element is " << majElem << "."<< endl;
    else
        cout << "There is no majority element." << endl;
    return 0;
}

