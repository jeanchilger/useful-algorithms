#include <stdio.h>
#include <stdlib.h>
#include "redBlack.h"

#define BOLD_BLACK "\e[1;90m"
#define BOLD_RED "\e[1;31m"
#define BOLD_WHITE "\e[1;37m"
#define WHITE_BG "\e[47m"
#define RESET "\e[0m"

//
// Utility functions
//

long int max (long int a, long int b) {
    /*
     * Returns the max between a and b.
     * */

    return (a > b) ? a : b;
}

Node *newNode (Node *parent, long int val) {
    /*
     * Creates a new node and returns it.
     * */

    Node *new = (Node *)malloc(sizeof(Node));
    new -> value = val;
    new -> left = NULL;
    new -> right = NULL;
    new -> color = RED; // when inserted, node is red.
    new -> parent = parent;

    return new;
}

Node *getParent(Node *node) {
    /*
     * Utility function to get the parent of a node.
     * */

    //printf("parent\n");
    if (!empty(node)) {
        return (node) -> parent;
    }


    return NULL;
}

Node *getGrandParent(Node *node) {
    /*
     * Utility function to get the grand parent of a node.
     * */

    //printf("grandParent\n");
    if (!empty(node)) {
        return getParent(node -> parent);
    }

    return NULL;
}

Node *getUncle(Node *node) {
    /*
     * Utility function to get the uncle of a node.
     * */

    if (!empty(node)) {
        Node *gp = getGrandParent(node);
       // printf("uncle\n");
        if (!empty(gp)) {
            if (getParent(node) == gp -> left) {
                return gp -> right;

            } else if (getParent(node) == gp -> right) {
                return gp -> left;
            }
        }
    }

    return NULL;
}

void swap(Node *new, Node *old) {
    /*
     * Swap the values from new to old.
     * */

    old -> value = new -> value;
    old -> left = new -> left;
    old -> right = new -> right;
    old -> parent = new -> parent;
    old -> color = new -> color;
}

void leftRotate(Node **node) {
    /*
     * Performs the LEFT rotation in the subtree rooted in the given node.
     * */

    Node *a = (*node);
    Node *b = a -> right;
    Node *s2 = b -> left;
    
    if (!empty(s2)) {
        s2 -> parent = a;
    }
    
    Node *p = getParent(a);
    if (!empty(p)) {
        if (a == p -> left) {
            p -> left = b;
        } else {
            p -> right = b;
        }
    }
    
    b -> parent = a -> parent;
    a -> parent = b;
    
    b -> left = a;
    a -> right = s2;
    
    (*node) = b;
}

void rightRotate(Node **node) {
    /*
     * Performs the RIGHT rotation in the subtree rooted in the given node.
     * */

    Node *a = (*node);
    Node *b = a -> left;
    Node *s2 = b -> right;

    if (!empty(s2)) {
        s2 -> parent = a;
    }
    
    Node *p = getParent(a);
    if (!empty(p)) {
        if (a == p -> left) {
            p -> left = b;
        } else {
            p -> right = b;
        }
    }
    
    b -> parent = a -> parent;
    a -> parent = b;

    b -> right = a;
    a -> left = s2;
    
    (*node) = b;
}

void insertionFixUp(Node **node) {
    /*
     * Fixes the possible unbalance caused in the insertion of a new value.
     * */

    if (node == NULL || empty(*node)) return;
    
    // Node is the root:
    if (empty(getParent(*node))) {
        (*node) -> color = BLACK;
    
    } else if (getParent(*node) -> color == RED) {
        
        if (empty(getUncle(*node)) || getUncle(*node) -> color == BLACK) {
            // printf("\t\tBLACK UNCLE\n");
            Node *g = getGrandParent(*node);
            Node *p = getParent(*node);
            
            if (p == g -> left) {
                // left left case
                if ((*node) == p -> left) {
                    int gColor = g -> color;
                    g -> color = p -> color;
                    p -> color = gColor;
                    rightRotate(&g);
                    // printf("LEFT LEFT\n");
            
                // left right case
                } else if ((*node) == p -> right) {
                    leftRotate(&p);
                    int gColor = g -> color;
                    g -> color = p -> color;
                    p -> color = gColor;
                    rightRotate(&g);
                    // printf("LEFT RIGHT\n");
                }
            
            } else if (p == g -> right) {
                // right right case
                if ((*node) == p -> right) {
                    int gColor = g -> color;
                    g -> color = p -> color;
                    p -> color = gColor;
                    leftRotate(&g);
                    // printf("RIGHT RIGHT\n");
                    
                // right left case
                } else if ((*node) == p -> left) {
                    rightRotate(&p);
                    int gColor = g -> color;
                    g -> color = p -> color;
                    p -> color = gColor;
                    leftRotate(&g);
                    // printf("RIGHT LEFT\n");
                }
            }
            
        } else if (getUncle(*node) -> color == RED) {
            // printf("\t\tRED UNCLE\n");
            (getParent(*node)) -> color = BLACK;
            (getUncle(*node)) -> color = BLACK;
            (getGrandParent(*node)) -> color = RED;
        }
        
        if (empty(*node) || empty(getParent(*node))) insertionFixUp(NULL);
        else insertionFixUp(&((*node) -> parent -> parent));
    }
    
    return;
}

//
// Red-Black Tree functions
//

int empty(Node *root) {
    /*
     * Checks whether the tree is empty or not.
     * */

    return (root == NULL);
}

void insert(Node **root, Node **parent, long int val) {
    /*
     * Inserts a new element in the tree.
     * If the insertion makes the tree skewed, it is rebalanced following Red-Black rules.
     * */

    if (empty(*root)) {
        (*root) = newNode((*parent), val);
        insertionFixUp(root);
        return;
    
    } else {
        if (val > (*root) -> value) {
            insert(&((*root) -> right), root,  val);
        
        } else if (val < (*root) -> value) {
            insert(&((*root) -> left), root, val);
        
        } else {
            return;
        }
    }
}

Node *search(Node *root, long int val) {
    /*
     * Searchs for a given value in the tree and returns a pointer to its node.
     * If not found, returns NULL.
     * */

    if (empty(root)) return NULL;
    if (root -> value == val) return root;
    if (val > root -> value) return search(root -> right, val);
    if (val < root -> value) return search(root -> left, val);
}

void erase(Node **root, long int val) {
    /*
     * Removes a single element from the tree.
     * */

    printf("I don't work!!\n");
}

void printPreOrder(Node *root) {
    /*
     * Traverse the tree Pre Order and prints the nodes.
     * */

    if (empty(root)) return;
    if (root -> color == RED) printf(BOLD_RED" %ld"RESET, root -> value);
    else printf(BOLD_BLACK" %ld"RESET, root -> value);
    printPreOrder(root -> left);
    printPreOrder(root -> right);
}

void printInOrder(Node *root) {
    /*
     * Traverse the tree In Order (increasing) and prints the nodes.
     * */

    if (empty(root)) return;
    printInOrder(root -> left);
    if (root -> color == RED) printf(BOLD_RED" %ld"RESET, root -> value);
    else printf(BOLD_BLACK" %ld"RESET, root -> value);
    printInOrder(root -> right);
}

void printPostOrder(Node *root) {
    /*
     * Traverse the tree Post Order and prints the nodes.
     * */

    if (empty(root)) return;
    printPostOrder(root -> left);
    printPostOrder(root -> right);
    if (root -> color == RED) printf(BOLD_RED" %ld"RESET, root -> value);
    else printf(BOLD_BLACK" %ld"RESET, root -> value);
}

void bfs(Node *root, long int i) {
    /*
     * Helper function to prints all nodes at the ith level.
     * */

    if (empty(root)) return;
    if (i == 0) {
        if (root -> color == RED) printf(BOLD_RED" %ld"RESET, root -> value);
        else printf(BOLD_BLACK" %ld"RESET, root -> value);
    }
    bfs(root -> left, i - 1);
    bfs(root -> right, i - 1);
}

void printBFS(Node *root) {
    /*
     * Traverse the tree using BFS and prints the nodes.
     * */

    long int i;
    for (i = 0; i < calcTreeHeight(root); i++) {
        bfs(root, i);
        printf("\n");
    }
}

void clear(Node *root) {
    /*
     * Clear the entire tree.
     * */

    if (empty(root)) return;
    clear(root -> left);
    clear(root -> right);
    free(root);
}

long int calcTreeHeight(Node *root) {
    /*
     * Calculates the height of the tree at the given node.
     * By default, the root is counted.
     * */

    if (empty(root)) return 0;
    return max(1 + calcTreeHeight(root -> left),
               1 + calcTreeHeight(root -> right));
}

long int calcTreeBlackHeight(Node *root) {
    /*
     * Calculates the black-height of the tree at the given node.
     * */

    if (empty(root)) return 1;
    if (root -> color) return max(1 + calcTreeBlackHeight(root -> left),
                                  1 + calcTreeBlackHeight(root -> right));
}

long int countNumberOfNodes(Node *root) {
    /*
     * Counts the number of the nodes in the tree.
     * */

    if (empty(root)) return 0;
    return 1 + countNumberOfNodes(root -> left) + countNumberOfNodes(root -> right);
}

void showMenu() {
    printf("\n\t\t  MENU\n");
    printf("================================================\n");
    printf(" | 1 - Insert element                         |\n");
    printf(" | 2 - Search value                           |\n");
    printf(" | (X)3 - Erase element                       |\n");
    printf(" | 4 - Print elements                         |\n");
    printf(" | 5 - Clean list                             |\n");
    printf(" | 6 - Calc. tree height                      |\n");
    printf(" | 7 - Number of nodes                        |\n");
    printf(" | 9 - Show menu                              |\n");
    printf(" | 0 - Exit                                   |\n");
    printf("================================================\n");
}
