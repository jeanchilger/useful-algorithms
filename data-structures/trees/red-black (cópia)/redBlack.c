
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
#include <stdio.h>
#include <stdlib.h>
#include "redBlack.h"

#define BOLD_BLACK "\e[1;90m"
#define BOLD_RED "\e[1;31m"
#define BOLD_WHITE "\e[1;37m"
#define WHITE_BG "\e[47m"
#define RESET "\e[0m"

#define NULL_COLOR -1
#define RED 0
#define BLACK 1
#define DOUBLE_BLACK 2

static Node *NULL_LEAF = &(Node) {
    .value = 0,
    .left = NULL,
    .right = NULL,
    .parent = NULL,
    .color = NULL_COLOR
};

//
// Utility functions
//

long int max (long int a, long int b) {
    /*
     * Returns the max between a and b.
     * */

    return (a > b) ? a : b;
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
     * Returns the node with MIN valuw within the subtree rooted in 'root'.
     * */

    if (empty(root)) return NULL;
    if (empty(root -> left)) return root;
    return findMinNode(root -> left);
}

Node *newNode (Node *parent, long int val) {
    /*
     * Creates a new node and returns it.
     * */

    Node *new = (Node *)malloc(sizeof(Node));
    new -> value = val;
    new -> left = NULL_LEAF;
    new -> right = NULL_LEAF;
    new -> color = RED; // when inserted, node is red.
    new -> parent = parent;

    return new;
}

Node *getParent(Node *node) {
    /*
     * Utility function to get the parent of a node.
     * */

    if (!empty(node)) return (node) -> parent;

    return NULL;
}

Node *getGrandParent(Node *node) {
    /*
     * Utility function to get the grand parent of a node.
     * */

    if (!empty(node)) return getParent(node -> parent);

    return NULL;
}

Node *getUncle(Node *node) {
    /*
     * Utility function to get the uncle of a node.
     * */

    if (!empty(node)) {
        Node *gp = getGrandParent(node);
        if (!empty(gp)) {
            if (getParent(node) == gp -> left) return gp -> right;
            else if (getParent(node) == gp -> right) return gp -> left;
        }
    }

    return NULL;
}

Node *getSibling(Node *node) {
    /*
     * Utility function to get the sibling of a node.
     * */

    if (!empty(node)) {
        Node *p = getParent(node);
        if (!empty(p)) {
            if (node == p -> left) return p -> right;
            else if (node == p -> right) return p -> left;
        }
    }

    return NULL;
}

int getColor(Node *node) {
    /*
     * Utility function to get the color of a node.
     * */

    if (empty(node)) return BLACK;
    return (node -> color);
    
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
    
    // Node is the root
    if (empty(getParent(*node))) {
        (*node) -> color = BLACK;
    
    // parent is red
    } else if (getColor(getParent(*node)) == RED) {

        // black uncle
        if (getColor(getUncle(*node)) == BLACK) {
            Node *g = getGrandParent(*node);
            Node *p = getParent(*node);
            
            if (p == g -> left) {
                // left left case
                if ((*node) == p -> left) {
                    int gColor = getColor(g);
                    g -> color = getColor(p);
                    p -> color = gColor;
                    rightRotate(&g);
            
                // left right case
                } else if ((*node) == p -> right) {
                    leftRotate(&p);
                    int gColor = getColor(g);
                    g -> color = getColor(p);
                    p -> color = gColor;
                    rightRotate(&g);
                }
            
            } else if (p == g -> right) {
                // right right case
                if ((*node) == p -> right) {
                    int gColor = getColor(g);
                    g -> color = getColor(p);
                    p -> color = gColor;
                    leftRotate(&g);
                    
                // right left case
                } else if ((*node) == p -> left) {
                    rightRotate(&p);
                    int gColor = getColor(g);
                    g -> color = getColor(p);
                    p -> color = gColor;
                    leftRotate(&g);
                }
            }
            
        // red uncle
        } else if (getColor(getUncle(*node)) == RED) {
            (getParent(*node)) -> color = BLACK;
            (getUncle(*node)) -> color = BLACK;
            (getGrandParent(*node)) -> color = RED;
        }
        
        if (empty(*node) || empty(getParent(*node))) insertionFixUp(NULL);
        else insertionFixUp(&((*node) -> parent -> parent));
    }
    
    return;
}

// TODO: mudar para fixDoubleBlack e chamar só quando um nó e DOUBLE_BLACK;
// remover NULL_LEAF e adicionar o resto das verificações em erase;
void delFixUp(Node *old, Node **new) {
    /*
     * Fixes the possible unbalance caused in the deletion of a node.
     * */

    // if (new == NULL || empty(*new)) return;

    // replaced node is root
    if (empty(getParent(*new))) {
        (*new) -> color = BLACK;
        return;
    }
    
    // old or new child is RED
    if ((new != NULL && (*new) -> color == RED) || old -> color == RED) {
        (*new) -> color = BLACK;
        return;
    }

    // both old and new are BLACK
    if ((new == NULL || empty(*new) || getColor(*new) == BLACK) && getColor(old) == BLACK)  {
        (*new) -> color = DOUBLE_BLACK;
        Node *sibling = getSibling(*new);

        // sibling is black
        if (getColor(sibling) == BLACK) {

            // new or old are red
            if (getColor(sibling -> left) == RED ) {
                // left left case
                if (sibling == getParent(sibling) -> left) {
                    sibling -> left -> color = BLACK;
                    rightRotate(&(sibling -> parent));

                // left right case
                } else {
                    sibling -> right -> color = BLACK;
                    leftRotate(&sibling);
                    rightRotate(&(sibling -> parent));

                }

            } else if (getColor(sibling -> right) == RED) {
                // right right case
                if (sibling == getParent(sibling) -> left) {
                    sibling -> right -> color = BLACK;
                    leftRotate(&(sibling -> parent));

                // right left case
                } else {
                    sibling -> left -> color = BLACK;
                    rightRotate(&sibling);
                    leftRotate(&(sibling -> parent));

                }

            // both new and old are black
            } else {
                (*new) -> color = BLACK;
                sibling -> color = RED;
                Node *parent = getParent(*new);
                if (getColor(parent) == RED) {
                    parent -> color = BLACK;
                } else {
                    parent -> color = DOUBLE_BLACK;
                    //delFixUp();

                }    
            }
        }
    }
}

//
// Red-Black Tree functions
//

int empty(Node *root) {
    /*
     * Checks whether the tree is empty or not.
     * */

    return (root == NULL ? 1 : root -> color == NULL_COLOR);
}

void insert(Node **root, Node **parent, long int val) {
    /*
     * Inserts a new element in the tree.
     * If the insertion makes the tree skewed, it is rebalanced following Red-Black rules.
     * */


    if (empty(*root)) { 
        if (parent == NULL) *parent = NULL_LEAF; 
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
     * Deletes the node with given value from the tree.
     * */

    if (empty(*root)) return;

    if (((*root) -> value) == val) {
        // Node has one or no child
        if (empty((*root) -> left)) {
            Node *tmp = (*root) -> right;
            Node *aux = (*root);
            free(*root);
            (*root) = tmp;
            delFixUp(aux, root);
    
        } else if (empty((*root) -> right)) {
            Node *tmp = (*root) -> left;
            Node *aux = (*root);
            free(*root);
            (*root) = tmp;
            delFixUp(aux, root);
        
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
    if (getColor(root) == BLACK) return max(1 + calcTreeBlackHeight(root -> left),
                                            1 + calcTreeBlackHeight(root -> right));
}

long int countNumberOfNodes(Node *root) {
    /*
     * Counts the number of the nodes in the tree.
     * */

    if (empty(root)) return 0;
    return 1 + countNumberOfNodes(root -> left) + countNumberOfNodes(root -> right);
}

Node *getPredecessor(Node *root, Node *pred, long int val) {
    /*
     * Returns a pointer to the In-Order predecessor of the node with given value.
     * */

    if (empty(root)) return NULL;
    if (root -> value == val) {
        if (!empty(root -> left)) 
            return findMaxNode(root -> left);
        
        else 
            return pred;
    }

    if (root -> value < val) 
        return getPredecessor(root -> right, pred, val);

    else
        return getPredecessor(root -> left, pred, val);
}

Node *getSucessor(Node *root, Node *pred, long int val) {
    /*
     * Returns a pointer to the In-Order sucessor of the node with given value.
     * */

    if (empty(root)) return NULL;
    if (root -> value == val) {
        if (!empty(root -> right))
            return findMinNode(root -> right);

        else
            return pred;
    }

    if (root -> value < val)
        return getSucessor(root -> right, root, val);

    else
        return getSucessor(root -> left, root, val);
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

