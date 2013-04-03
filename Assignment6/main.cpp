/* 
 * File:   main.cpp
 * Author: norman
 *
 * Created on April 1, 2013, 10:03 PM
 */

#include <cstdlib>
#include <iostream>
#include "BinaryTree.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    BinaryTree<int> t1(1);
    BinaryTree<int> t3(3);
    BinaryTree<int> t5(5);
    BinaryTree<int> t7(7);
    BinaryTree<int> t2;
    BinaryTree<int> t4;
    BinaryTree<int> t6;
    
    t2.merge(2, t1, t3);
    cout << "----------------\n";
    cout << "t2 after merge of 1 and 3\n";
    t2.printInOrder();
    cout << "t2 size:" << t2.size() << "\n";
    cout << "t2 height:" << t2.height() << "\n";
    t6.merge(6, t5, t7);        
    cout << "----------------\n";
    cout << "t6 after merge of 5 and 7\n";
    t4.merge(4, t2, t6);
    
    cout << "t4 should be perfect 1-7; t2 empty\n";
    cout << "----------------\n";
    cout << "t4\n";
    t4.printInOrder();
    cout << "---------------\n";
    cout << "t2";
    t2.printInOrder();
    cout << "----------------\n";
    cout << "t4 size: " << t4.size( ) << "\n";
    cout << "t4 height: " << t4.height( ) << "\n";
    
    // newly added for testing.
    cout << "Print inorder with indentation: t4\n";
    t4.printInOrderWithIndentation( );
    cout << "t4 average height: " << t4.averageHeight( ) << "\n";

    return 0;
}

