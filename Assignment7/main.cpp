#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

int main(int argc, char **argv){
  BinarySearchTree<int> *t = new BinarySearchTree<int>();
  const int NUMS = 50;
  const int GAP = 37;

  cout << "Checking... (no more output means success)\n";

  for( int i = GAP; i != 0; i = ( i + GAP ) % NUMS ){
    t->insert( i );
//    cout << i << "\n";
  }

  cout << "After insertions. Size = " <<  t->size() << "\n";
  t->printBST();

  cout << "Elements between 9 and 21.\n";
  t->printRange(9, 21);
 
  for( int i = 1; i < NUMS; i +=2 ){
   // cout << "remove " << i << "\n";
    t->remove( i );
  }
//  cout << "Elements between 9 and 21.\n";
//  t->printRange(9, 21);

  cout << "After deletions. Size = " << t->size() << "\n";
  t->printBST();

  cout << "Elements between 9 and 12\n";
  t->printRange(9, 21);

  if( t->findMin( ) != 2 || t->findMax( ) != NUMS -2 )
    cout << "FindMin or FindMax error!\n";

  for( int i = 2; i < NUMS; i+=2 ){
 //   cout << "Find " << i << "\n";
    if( t->find( i ) != i )
      cout << "Find error1!\n";
  }

  for( int i = 1; i < NUMS; i += 2 )
    if( t->find( i ) != 0 )
      cout << "Find error2!\n";

  return 0;
}
