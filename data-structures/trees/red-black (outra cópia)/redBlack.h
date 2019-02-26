#ifndef _$RBT$21_$1a
#define _$RBT$21_$1a

#include <stdio.h>
#include <stdlib.h>

struct TNode {
    long int value;
    struct TNode *left;
    struct TNode *right;
    struct TNode *parent;
    int color;
};

typedef struct TNode Node;

// Checks whether the tree is empty or not.
int empty(Node *);

// Inserts a new element in the tree.
// If the insertion makes the tree skewed, it is rebalanced following Red-Black rules.
void insert(Node **, Node **, long int);


// Searchs for a given value in the tree and returns a pointer to its node.
// If not found, returns NULL.
Node *search(Node *, long int);

// Removes a single element from the tree.
void erase(Node **, long int);

// Traverse the tree Pre Order and prints the nodes.
void printPreOrder(Node *);

// Traverse the tree In Order and prints the nodes.
void printInOrder(Node *);

// Traverse the tree Post Order and prints the nodes.
void printPostOrder(Node *);

// Traverse the tree using BFS and prints the nodes.
void printBFS(Node *);

// Clear the entire tree.
void clear(Node *);

// Calculates the height of the tree at the given node.
// By default, the root is counted.
long int calcTreeHeight(Node *);

// Calculates the black-height of the tree at the given node.
long int calcTreeBlackHeight(Node *);

// Counts the number of the nodes in the tree.
long int countNumberOfNodes(Node *);

// Returns a pointer to the In-Order predecessor of the node with given value.
Node *getPredecessor(Node *, Node *, long int);

// Returns a pointer to the In-Order sucessor of the node with given value.
Node *getSucessor(Node *, Node *, long int);

// Prints the menu, showing avaiable options.
void showMenu();

#endif
