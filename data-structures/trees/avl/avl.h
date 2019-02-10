#ifndef _$AVL_$a23e
#define _$AVL_$a23e

#include <stdio.h>
#include <stdlib.h>

struct TNode {

    long int value;
    struct TNode *left;
    struct TNode *right;
    long int height;
};

typedef struct TNode Node;

// Returns whether or not the tree is empty.
int empty(Node *);

// Inserts a new element in the tree.
// If the insertion makes tree skewed, it is rebalanced.
void insert(Node **, long int);

// Searchs for a given value.
// If the value is found within the tree, returns a pointer to it.
// Else, returns NULL.
Node *search(Node *, long int);

// Deletes the node with given value from the tree.
void erase(Node **,  long int);

// Traverse the tree Pre Order and prints the nodes.
void printPreOrder(Node *);

// Traverse the tree In Order and prints the nodes.
void printInOrder(Node *);

// Traverse the tree Post Order and prints the nodes.
void printPostOrder(Node *);

// Traverse the tree using Breadth First Search and prints the nodes.
void printBFS(Node *);

// Clear the entire tree.
void clear(Node *);

// Calculates the height of the tree at the given node.
// By default, the given node is counted. 
long int calcTreeHeight(Node *);

// Counts the number of nodes in the tree rooted in the given node.
long int countNumberOfNodes(Node *);

// Returns a pointer for the In-Order predecessor of the given node.
Node *getPredecessor(Node *, Node *, long int);

// Returns a pointer for the In-Order sucessor of the given node.
Node *getSucessor(Node *, Node *, long int);

// Prints the menu, showing avaiable options.
void showMenu();

#endif
