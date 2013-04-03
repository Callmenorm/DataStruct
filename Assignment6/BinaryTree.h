#ifndef BINARYTREE_H_
#define BINARYTREE_H_

#include <stdlib.h>
#include <vector>
#include <iostream>

template <class Object>
class BinaryTree;

// BinaryNode class; stores a node in a tree.
//
// CONSTRUCTION: with (a) no parameters, or (b) an Object,
//     or (c) an Object, left pointer, and right pointer.
//
// *******************PUBLIC OPERATIONS**********************
// int size( )            --> Return size of subtree at node
// int height( )          --> Return height of subtree at node
// void printPostOrder( ) --> Print a postorder tree traversal
// void printInOrder( )   --> Print an inorder tree traversal
// void printPreOrder( )  --> Print a preorder tree traversal
// BinaryNode * duplicate( )    --> Return a duplicate tree
// *******************ERRORS*********************************
// None.

template <class Object>
class BinaryNode
{
  public:
    BinaryNode( const Object & theElement = Object( ),
                BinaryNode *lt = NULL, BinaryNode *rt = NULL );

    static int size( BinaryNode *t );
    static int height( const BinaryNode *t );
    static int averageHeight( BinaryNode *t, std::vector<int> &heights, bool clear );

    void printPreOrder( ) const;
    void printPostOrder( ) const;
    void printInOrder( ) const;
    void printInOrderWithIndentation( int height ) const;

    BinaryNode *duplicate( ) const;

  public:   // To keep things simple
    Object      element;
    BinaryNode *left;
    BinaryNode *right;
};

// Constructor.
template <class Object>
BinaryNode<Object>::BinaryNode( const Object & theElement,
                                BinaryNode *lt, BinaryNode *rt )
  : element( theElement ), left( lt ), right( rt )
{ 
}

// Return size of tree rooted at t.
template <class Object>
int BinaryNode<Object>::size( BinaryNode<Object> * t )
{
    if( t == NULL )
        return 0;
    else
        return 1 + size( t->left ) + size( t->right );
}

#define max MAX

template <class Comparable>
Comparable max( const Comparable & a, const Comparable & b )
{
    return a > b ? a : b;
}

// Return height of tree rooted at t.
template <class Object>
int BinaryNode<Object>::height(const BinaryNode<Object> * t )
{
    if( t == NULL )
        return -1;
    else{
        int node_height = 1 + max( height( t->left ), height( t->right ) );
        //std::cout << "node_height is: " << node_height << "\n";
        return node_height;
    }
}

// Return the average height of tree rooted at t.
template < class Object>
int BinaryNode<Object>::averageHeight( BinaryNode<Object> * t, std::vector<int> & heights, bool clear)
{
    if(clear == true){
        heights.clear();
        clear = false;
    }
    
    if( t == NULL)
        return -1;
    else{
        int node_height = 1 + max( averageHeight( t->left, heights, clear ), averageHeight( t->right, heights, clear ) );
        heights.push_back(node_height);
        return node_height;
    }
    
}

#undef max

// Print the tree rooted at current node using preorder traversal.
template <class Object>
void BinaryNode<Object>::printPreOrder( ) const
{
    std::cout << element << std::endl;                  // Node
    if( left != NULL )
        left->printPreOrder( );               // Left
    if( right != NULL )
        right->printPreOrder( );              // Right
}

// Print the tree rooted at current node using postorder traversal.
template <class Object>
void BinaryNode<Object>::printPostOrder( ) const
{
    if( left != NULL )                        // Left
        left->printPostOrder( );
    if( right != NULL )                       // Right
        right->printPostOrder( );
    std::cout << element << std::endl;                  // Node
}

// Print the tree rooted at current node using inorder traversal.
template <class Object>
void BinaryNode<Object>::printInOrder( ) const
{
    if( left != NULL )                        // Left
        left->printInOrder( );
    std::cout << element << std::endl;                  // Node
    if( right != NULL )
        right->printInOrder( );               // Right
}

// Print the tree rooted at current node using inorder traversal
// with indentation to make it look like a tree.
template <class Object>
void BinaryNode<Object>::printInOrderWithIndentation(int height) const
{
    if( left != NULL )
        left->printInOrderWithIndentation( height );
    int this_height = BinaryNode<Object>::height( this );
    while(this_height < height){
        std::cout << "\t";
        ++this_height;
    }
    std::cout << element << std::endl;
    if( right != NULL )
        right->printInOrderWithIndentation( height );
}

// Return a pointer to a node that is the root of a
// duplicate of the tree rooted at the current node.
template <class Object>
BinaryNode<Object> * BinaryNode<Object>::duplicate( ) const
{
    BinaryNode<Object> *root =
                         new BinaryNode<Object>( element );

    if( left != NULL )            // If there's a left subtree
        root->left = left->duplicate( );   // Duplicate; attach
    if( right != NULL )           // If there's a right subtree
        root->right = right->duplicate( ); // Duplicate; attach

    return root;                     // Return resulting tree
}

template <class Object>
class TreeIterator;


// BinaryTree class; stores a binary tree.
//
// CONSTRUCTION: with (a) no parameters or (b) an object to
//    be placed in the root of a one-element tree.
//
// *******************PUBLIC OPERATIONS**********************
// Various tree traversals, size, height, isEmpty, makeEmpty.
// Also, the following tricky method:
// void merge( Object root, BinaryTree t1, BinaryTree t2 )
//                        --> Construct a new tree
// *******************ERRORS*********************************
// Error message printed for illegal merges.

template <class Object>
class BinaryTree
{
  public:
    BinaryTree( ) : root( NULL ), heights(0) { }
    BinaryTree( const Object & rootItem )
      : root( new Node( rootItem ) ) { }
    BinaryTree( const BinaryTree & rhs )
      : root( NULL ) { *this = rhs; }

    ~BinaryTree( )
      { makeEmpty( ); }

    const BinaryTree & operator= ( const BinaryTree & rhs );

      // Recursive traversals, with printing
    void printPreOrder( ) const
      { if( root != NULL ) root->printPreOrder( ); }    
    void printInOrder( ) const
      { if( root != NULL ) root->printInOrder( ); }    
    void printPostOrder( ) const
      { if( root != NULL ) root->printPostOrder( ); }  
    void printInOrderWithIndentation( ) const
    {   
        if( root != NULL ){
            int height = Node::height( root );
            root->printInOrderWithIndentation( height ); 
        }
    }
     
    void makeEmpty( )
      { makeEmpty( root ); } 
    bool isEmpty( ) const
      { return root == NULL; }

      // Combine t1 and t2
    void merge( const Object & rootItem, BinaryTree & t1, BinaryTree & t2 );

    int size( ) const
      { return Node::size( root ); }
    int height( ) const
      { return Node::height( root ); }
    double averageHeight( ){
      Node::averageHeight( root, heights, true ); 
      
      int height_sum = 0;
      for(unsigned int i = 0; i < heights.size(); ++i){
          //std::cout << "height of heights[" << i << "]: " << heights[i] << "\n";
          height_sum += heights[i];
      }
      
      return double(height_sum)/heights.size();
    }
    
  private:
    typedef BinaryNode<Object> Node;
    Node *root;
    std::vector<int> heights;


    friend class TreeIterator<Object>;
    void makeEmpty( BinaryNode<Object> * & t );
};

// Deep copy.
template <class Object>
const BinaryTree<Object> &
BinaryTree<Object>::operator= ( const BinaryTree<Object> & rhs )
{
    if( this != &rhs )
    {
        makeEmpty( );
        if( rhs.root != NULL )
            root = rhs.root->duplicate( );
    }

    return *this;
}

// Merge routine for BinaryTree class.
// Forms a new tree from rootItem, t1 and t2.
// Does not allow t1 and t2 to be the same.
// Correctly handles other aliasing conditions.
template <class Object>
void BinaryTree<Object>::merge( const Object &  rootItem,
                         BinaryTree<Object> & t1, BinaryTree<Object> & t2 )
{
    if( t1.root == t2.root && t1.root != NULL )
    { 
        std::cerr << "Cannot merge a tree with itself; merge aborted." << std::endl;
        return;
    }

    Node *oldRoot = root;   // Save old root

      // Allocate new node
    root = new Node( rootItem, t1.root, t2.root );

      // Deallocate nodes in the original tree
    if( this != &t1 && this != &t2 )
        makeEmpty( oldRoot );

      // Ensure that every node is in one tree
    if( this != &t1 )
        t1.root = NULL;
    if( this != &t2 )
        t2.root = NULL;
}

// Make tree rooted at t empty, freeing nodes, and setting t to NULL.
template <class Object>
void BinaryTree<Object>::makeEmpty( BinaryNode<Object> * & t )
{
    if( t != NULL )
    {
        makeEmpty( t->left );
        makeEmpty( t->right );
        delete t;
        t = NULL;
    }
}

#endif
