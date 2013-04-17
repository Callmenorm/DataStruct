#include <iostream>

template <class Object>
class BinarySearchTree;

template <class Object>
class BinaryNode{
  public:

    BinaryNode( ): element(0), parent(0), left(0), right(0){}

    BinaryNode( Object theElement): element(theElement), parent(0), left(0), right(0){ }
    static int         height( const BinaryNode *t );
    static BinaryNode *insert( Object& x, BinaryNode *t );
    static BinaryNode *remove( Object& x, BinaryNode *t );
    static BinaryNode *removeMin( BinaryNode *t );
    static BinaryNode *findMin( BinaryNode *t );
    static BinaryNode *findMax( BinaryNode *t );
    static BinaryNode *find( Object& x, BinaryNode *t );
    static int        size(const BinaryNode *t );
    void printBST(int height);

    Object element;
    BinaryNode *parent;
    BinaryNode *left;
    BinaryNode *right;
};

template <class Object>
Object max( const Object& a, const Object& b ){
  return a > b ? a : b;
}

template <class Object>
int BinaryNode<Object>::height(const BinaryNode<Object> *t ){
  if( t == NULL )
    return -1;
  else{
    int node_height = 1 + max( height( t->left ), height( t->right ) );
    return node_height;
  }
}

template <class Object>
BinaryNode<Object> *BinaryNode<Object>::insert( Object& x, BinaryNode *t ){
  if( t == NULL )
    t = new BinaryNode( x );
  else if ( x < t->element ){
    t->left = insert( x, t->left );
    t->left->parent = t;
  }
  else if ( x > t->element ){
    t->right = insert(x, t->right );
    t->right->parent = t;
  }
  
  return t;
}

template <class Object>
BinaryNode<Object> *BinaryNode<Object>::remove( Object& x, BinaryNode *t ){
  if( t == NULL )
    return NULL;

  if( x < t->element )
    t->left = remove( x, t->left );
  else if (x > t->element )
    t->right = remove( x, t->right );
  else if( t->left != NULL && t->right != NULL ){
    t->element = findMin( t->right )->element;
    t->right = removeMin( t->right );
  } else
    t = ( t->left != NULL ) ? t->left : t->right;
 
  return t;
}

template <class Object>
BinaryNode<Object> *BinaryNode<Object>::removeMin( BinaryNode *t ){
  if( t == NULL )
    return NULL;
  else if( t->left != NULL ){
    t->left = removeMin( t->left );
    return t;
  } else if ( t->right != NULL )
    return t->right;
  else
    return t;
}

template <class Object>
BinaryNode<Object> *BinaryNode<Object>::findMin( BinaryNode *t ){
  if( t == NULL)
    return NULL;
  else if ( t->left != NULL ){
    t = findMin( t->left );
    return t;
  } else
    return t;
}

template <class Object>
BinaryNode<Object> *BinaryNode<Object>::findMax(BinaryNode *t ){
  if( t == NULL)
    return NULL;
  else if ( t->right != NULL ){
    t = findMax( t->right );
    return t;
  } else
    return t;
}

template <class Object>
BinaryNode<Object> *BinaryNode<Object>::find( Object& x, BinaryNode *t ){
  while( t != NULL ){
    if( x < t->element )
      t = t->left;
    else if ( x > t->element )
      t = t->right;
    else
      return t;
  }

  return NULL;
}

template <class Object>
int BinaryNode<Object>::size( const BinaryNode *t ){
  if( t == NULL )
    return 0;
  else
    return 1 + size(t->left) + size(t->right);
}

template <class Object>
void BinaryNode<Object>::printBST( int height ){
  if( left != NULL )
    left->printBST( height );
  int this_height = BinaryNode<Object>::height(this);
  while(this_height < height ){
    std::cout << "\t";
    ++this_height;
  }
  std::cout << element << std::endl;
  if( right != NULL )
    right->printBST( height );
}

template <class Object>
class BinarySearchTree{
  public:
    BinarySearchTree( ): root(0) {}
    BinarySearchTree(Object x): root(x) {}

    void insert ( Object& x ) {
      root = BinaryNode<Object>::insert( x, root );
    }

    void remove ( Object& x ) {
      root = BinaryNode<Object>::remove( x, root );
    }

    void removeMin ( ) {
      root = BinaryNode<Object>::removeMin( root );
    }
    
    void printRange( const Object lb, const Object ub );
    void printBST( );
    int size( ) const;

    Object findMin( );

    Object findMax( );

    Object find( Object& x );

    void makeEmpty( ) {
      BinaryNode<Object>::makeEmpty( root );
    }

    bool isEmpty( ) {
      return root == NULL;
    }

  private:
    Object elementAt( BinaryNode<Object> *t ){
      if(t != NULL)
        return t->element;
      else 
        return 0;
    }
    BinaryNode<Object> *root;

  
};

template <class Object>
Object BinarySearchTree<Object>::findMin( ) {
    if( root == NULL )
      return 0;
    else{
      return elementAt( BinaryNode<Object>::findMin( root ) );
    }
}

template <class Object>
Object BinarySearchTree<Object>::findMax( ) {
    if( root == NULL )
      return 0;
    else  
      return elementAt( BinaryNode<Object>::findMax( root ) );
}

template <class Object>
Object BinarySearchTree<Object>::find( Object& x ){
    if( root == NULL )
      return 0;
    else
      return elementAt( BinaryNode<Object>::find(x, root ) ); 
}

template <class Object>
void BinarySearchTree<Object>::printRange(const Object lb, const Object ub){
  BinaryNode<Object> *result;
  for(Object i = lb; i <= ub; ++i)
    if( (result = BinaryNode<Object>::find( i, root )) != NULL )
      std::cout << result->element << "\n";
}

template <class Object>
void BinarySearchTree<Object>::printBST( ){
  if( root != NULL ){
    int height = BinaryNode<Object>::height( root );
    root->printBST(height);
  }
}

template <class Object>
int BinarySearchTree<Object>::size( ) const{
  if( root == NULL )
    return -1;
  else
    return BinaryNode<Object>::size( root ); 
}
