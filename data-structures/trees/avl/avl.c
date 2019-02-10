#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

#define BOLD_WHITE "\e[1;37m"
#define RESET "\e[0m"

//
// Utility functions
//

long int max(long int a, long int b) {
    /*
     * Returns the max between a and b.
     * */

    return (a > b) ? a : b;
}

long int power(long int b, long int e) {
    /*
     * Performs an exponentiation operation.
     * 'b' is the base and 'e' is the exponent.
     * */

    long int i;
    long int r = 1;
    if (!e) return 1;
    for (i=0; i < e; i++) {
        r *= b;
    }

    return r;
}

Node *findMaxNode(Node *root) {
    /*
     * Returns the node with MAX value within the subtree rooted in 'root'.
     * */

    if (empty(root)) return NULL;
    if (empty(root -> right)) return root;
    return findMaxNode(root -> right);
}

Node *findMinNode(Node *root) {
    /*
     * Returns the node with MIN value within the subtree rooted in 'root'.
     * */

    if (empty(root)) return NULL;
    if (empty(root -> left)) return root;
    return findMinNode(root -> left);
}

Node *newNode(long int val) {
    /*
     * Returns a new node.
     * */

    Node *node = (Node *)malloc(sizeof(Node));
    node -> left = NULL;
    node -> right = NULL;
    node -> value = val;
    node -> height = 0;
    return node;
}

int getHeight(Node *node) {
    /*
     * Returns the height attribute of a node.
     * No calculation is done.
     * */

    if (node == NULL) return 0;
    return node -> height;
}

void leftRotate(Node **node) {
    /*
     * Execute the LEFT rotation in the subtree where the given node is the root.
     * */

    Node *a = (*node);
    Node *b = a -> right;
    Node *aux = b -> left;

    b -> left = a;
    a -> right = aux;

    a -> height = max(getHeight(a -> left), getHeight(a -> right)) + 1;
    b -> height = max(getHeight(b -> left), getHeight(b -> right)) + 1;

    (*node) = b;
}

void rightRotate(Node **node) {
    /*
     * Executes the RIGHT rotation in the subtree where the given node is the root.
     * */

    Node *a = (*node);
    Node *b = a -> left;
    Node *aux = b -> right;

    b -> right = a;
    a -> left = aux;

    a -> height = max(getHeight(a -> left), getHeight(a -> right)) + 1;
    b -> height = max(getHeight(b -> left), getHeight(b -> right)) + 1;

    (*node) = b;
}

//
// AVL functions
// 

int empty(Node *root) {
    /*
     * Checks whether the tree is empty or not.
     * */

    return (root == NULL);
}

void insert(Node **root, long int val) {
    /*
     * Inserts a new element in the tree.
     * If the insertion makes the tree skewed, it is rebalanced.
     * */

    if (empty((*root))) {
        (*root) = newNode(val);

    } else {
        if (val > (*root) -> value) {
            insert(&((*root) -> right), val);

        } else if (val < (*root) -> value) {
            insert(&((*root) -> left), val);

        } else {
            //printf("Value already exists.\n");
            return;
        }
    }

    // Updates the heights after new node is inserted
    (*root) -> height = 1 + max(getHeight((*root) -> left),
                                getHeight((*root) -> right));

    // Checks if tree is unbalanced
    int balance = getHeight((*root) -> left) - getHeight((*root) -> right);

    if (balance > 1) {

        // left left case
        if (getHeight((*root) -> left -> left) > getHeight((*root) -> left -> right)) {
            rightRotate(root);

        // left right case
        } else {
            leftRotate(&((*root) -> left));
            rightRotate(root);
        }

    } else if (balance < -1) {

        // right right case
        if (getHeight((*root) -> right -> right) > getHeight((*root) -> right -> left)) {
            leftRotate(root);


        // right left case
        } else {
            rightRotate(&((*root) -> right));
            leftRotate(root);
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
     * Deletes a node with the given value from the tree.
     * */

    if (empty(*root)) return;

    if (((*root) -> value) == val) {
        // Node has one child
        if (empty((*root) -> left)) {
            Node *tmp = (*root) -> right;
            free(*root);
            (*root) = tmp;
        
        } else if (empty((*root) -> right)) {
            Node *tmp = (*root) -> left;
            free(*root);
            (*root) = tmp;
        
        // Node has two children
        } else {
            Node *p = getPredecessor(*root, NULL, val);
            long int rValue = (*root) -> value;
            (*root) -> value = p -> value;
            p -> value = rValue;
            (*root) -> height = 1 + max(getHeight((*root) -> left) - 1,
                                        getHeight((*root) -> right));
            erase(&((*root) -> left), rValue);
        }

    } else if (val > (*root) -> value) {
        erase(&((*root) -> right), val);
    
    } else {
        erase(&((*root) -> left), val);
    }

    if (empty(*root)) return;
    (*root) -> height = 1 + max(getHeight((*root) -> left),
                                getHeight((*root) -> right));
    int balance = getHeight((*root) -> left) - getHeight((*root) -> right);
    
    if (balance > 1) {
         
        //printf("LL: %d\tLR: %d\n", getHeight((*root) -> left -> left), getHeight((*root) -> left -> right));
        // left left case
        if (getHeight((*root) -> left -> left) >= getHeight((*root) -> left -> right)) {
            printf("LEFT LEFT\n");
            rightRotate(root);
        
        // left right case
        } else {
            printf("LEFT RIGHT\n");
            leftRotate(&((*root) -> left));
            rightRotate(root);
        }

    } else if (balance < -1) {
            
        // right right case
        if (getHeight((*root) -> right -> right) >= getHeight((*root) -> right -> left)) {
            printf("RIGHT RIGHT\n");
            leftRotate(root);
            
        // right left case
        } else {
            printf("RIGHT LEFT\n");
            rightRotate(&((*root) -> right));
            leftRotate(root);
        }
    }
}

void printPreOrder(Node *root) {
    /*
     * Traverse the tree Pre Order and prints the nodes.
     * */

    if (empty(root)) return;
    printf(BOLD_WHITE" %ld"RESET, root -> value);
    printPreOrder(root -> left);
    printPreOrder(root -> right);
}

void printInOrder(Node *root) {
    /*
     * Traverse the tree In Order (increasing) and prints the nodes.
     * */

    if (empty(root)) return;
    printInOrder(root -> left);
    printf(BOLD_WHITE" %ld"RESET, root -> value);
    printInOrder(root -> right);
}

void printPostOrder(Node *root) {
    /*
     * Traverse the tree Post Order and prints the nodes.
     * */

    if (empty(root)) return;
    printPostOrder(root -> left);
    printPostOrder(root -> right);
    printf(BOLD_WHITE" %ld"RESET, root -> value);
}

void bfs(Node *root, long int lvl) {
    /*
     * Performs the BFS in tree printing the visited nodes.
     * */

    if (empty(root) || lvl < 0) return;
    if (lvl == 0) printf(BOLD_WHITE" V: %ld"RESET" |  h: %ld ", root -> value, root -> height);
    bfs(root -> left, lvl - 1);
    bfs(root -> right, lvl - 1);
}

void printBFS(Node *root) {
    /*
     * Traverse the tree using Breadth First Search and prints the nodes.
     * */

    long int i;
    long int h = calcTreeHeight(root);
    for (i = 0; i < h; i++) {
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

long int calcTreeHeight(Node *node) {
    /*
     * Calculates the height of the tree at the given node.
     * By default, the root is counted.
     * */

    if (empty(node)) return 0;
    return max(1 + calcTreeHeight(node -> left),
               1 + calcTreeHeight(node -> right));
}

long int countNumberOfNodes(Node *root) {
    /*
     * Counts the number of the nodes in the tree.
     * */

    if (empty(root)) return 0;
    return countNumberOfNodes(root -> left) + countNumberOfNodes(root -> right) + 1;
}

Node *getPredecessor(Node *root, Node *pred, long int val) {
    /*
     * Returns the value of the In-Order predecessor of the given node.
     * */
     
    if (empty(root)) return NULL;
    if (root -> value == val) {
        if (!empty(root -> left)){
            return findMaxNode(root -> left);
        
        } else {
            return pred;                                   
        }             
    }
    
    if (root -> value < val) {
        return getPredecessor(root -> right, root, val);
    
    } else {
        return getPredecessor(root -> left, pred, val);
    }
}

Node *getSucessor(Node *root, Node *suc, long int val) {
    /*
     * Returns the value of the In-Order sucessor of the given node.
     * */
    
    if (empty(root)) return NULL;
    if (root -> value == val) {
        if (!empty(root -> right)) {
            return findMinNode(root -> right);
        
        } else {
            return suc;
        }
    }
    
    if (root -> value > val) {
        return getSucessor(root -> left, root, val);
    
    } else {
        return getSucessor(root -> right, suc, val);
    }
}

void showMenu() {
    printf("\n\t\t  MENU\n");
    printf("================================================\n");
    printf(" | 1  - Insert element                         |\n");
    printf(" | 2  - Search value                           |\n");
    printf(" | 3  - Erase element                          |\n");
    printf(" | 4  - Prints elements                        |\n");
    printf(" | 5  - Clean list                             |\n");
    printf(" | 6  - Calc. tree height                      |\n");
    printf(" | 7  - Number of nodes                        |\n");
    printf(" | 8  - Get predecessor                        |\n");
    printf(" | 9  - Get sucessor                           |\n");
    printf(" | 10 - Show menu                              |\n");
    printf(" | 0  - Exit                                   |\n");
    printf("================================================\n");
}
