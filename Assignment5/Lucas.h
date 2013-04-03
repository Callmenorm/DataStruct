/* 
 * File:   Lucas.h
 * Author: norman
 *
 * Created on February 28, 2013, 9:52 PM
 */

#ifndef LUCAS_H
#define	LUCAS_H
#include<vector>

class Lucas {
public:
    Lucas();
    Lucas(const Lucas& orig);
    virtual ~Lucas();
    
    int findLucas(const unsigned int N, const int current);
    int output(int lucas, int N);
    static std::vector<int> LucasHolder;

private:

    
    
};
#endif	/* LUCAS_H */

