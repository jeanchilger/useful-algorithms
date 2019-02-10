#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTree.h"

#define BOLD_WHITE "\e[1;37m"
#define RESET "\e[0m"

//
// Utility functions.
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
    for (i = 0; i < e; i++) {
        r *= b;
    }

    return r;
}

Node *findMaxNode(Node *root) {
    /*
     * Returns the node with MAX value within the subtree rooted in root.
     * */

    if (empty(root)) return NULL;
    if (empty(root -> right)) return root;
    return findMaxNode(root -> right);
}

Node *findMinNode (Node *root) {
    /*
     * Returns the node with MIN value within the subtree rooted in root.
     * */

    if (empty(root)) return NULL;
    if (empty(root -> left)) return root;
    return findMinNode(root -> left);
}

Node *newNode(long int val) {
    /*
     * Returns a new node.
     * */

    Node *new = (Node *)malloc(sizeof(Node));
    new -> left = NULL;
    new -> right = NULL;
    new -> value = val;

    return new;
}

void printSpaces(long int n) {
    /*
     * Prints n spaces.
     * */

    printf(" %ld ESPAÇOS\n\n", n);
    long int i;
    for (i = 0; i < n; i++) {
        printf(" ");
    }
}

//
// BST functions.
//

int empty(Node *root) {
    /*
     * Returns wether or not the list is empty.
     * */

    return (root == NULL);

}

void insert(Node **root, long int val) {
    /*
     * Inserts a new element to the Tree.
     * */

    if (empty((*root))) {
        (*root) = newNode(val);

    } else {
        if (val > (*root) -> value) {
            insert(&((*root) -> right), val);

        } else if (val < (*root) -> value) {
            insert(&((*root) -> left), val);

        } else {
            return;
        }
    }
}

Node *search (Node *root, long int val) {
    /*
     * Searches for a given value.
     * If the value is found within the list, returns a pointer to it.
     * Else, returns NULL.
     * */

    if (empty(root)) {
        return NULL;
    }

    if ((root -> value) == val) {
        return root;

    } else if (val > (root -> value)) {
        return search(root -> right, val);

    } else {
        return search((root -> left), val);
    }

}

void erase(Node **root, long int val) {
    /*
     * Deletes the node with given value from the tree.
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
            erase(&((*root) -> left), rValue);
        }

    } else if (val > ((*root) -> value)) {
        erase(&((*root) -> right), val);

    } else {
        erase(&((*root) -> left), val);
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

void bfs(Node *root, long int lvl, long int h, long int l) {
    /*
     * Performs the BFS in tree printing the visited nodes.
     * */

    if (empty(root) || lvl < 0) return;
    if (lvl == 0) printf(BOLD_WHITE" %ld"RESET, root -> value);
    bfs(root -> left, lvl - 1, h, l);
    bfs(root -> right, lvl - 1, h, l);
}

void printBFS(Node *root) {
    /*
     * Traverse the tree using Breadth First Search and prints the nodes.
     * */

    long int i;
    long int h = calcTreeHeight(root);
    for (i = 0; i < h; i++) {
        bfs(root, i, h, i);
        printf("\n");
    }
}

void clear(Node *root) {
    /*
     * Clear the entire list
     * */

    if (empty(root)) return;
    clear(root -> left);
    clear(root -> right);
    free(root);
}

long int calcTreeHeight(Node *root) {
    /*
     * Calculates the height of the tree.
     * */

    if (empty(root)) return 0;
    return max(1 + calcTreeHeight(root -> left),
               1 + calcTreeHeight(root -> right));
}

long int countNumberOfNodes(Node *root) {
    /*
     * Counts the number of nodes.
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
    printf(" | 4  - Print elements                         |\n");
    printf(" | 5  - Clean list                             |\n");
    printf(" | 6  - Calc. tree height                      |\n");
    printf(" | 7  - Number of nodes                        |\n");
    printf(" | 8  - Get predecessor                        |\n");
    printf(" | 9  - Get sucessor                           |\n");
    printf(" | 10 - Show menu                              |\n");
    printf(" | 0  - Exit                                   |\n");
    printf("================================================\n");
}
