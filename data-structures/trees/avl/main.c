#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

void insertRandomNumbers(Node **root, long int n, long int max) {
    /*
     * Generate n random numbers within the range [0, max[.
     * */

    long int i;
    for (i=0; i < n; i++) {
        long int val = rand() % max;
        insert(root, val);
    }
}

int main() {

	Node *root = NULL;
    int opt;
    long int val;

    showMenu();

    insert(&root, 9);
         insert(&root, 5);
              insert(&root, 10);
                   insert(&root, 0);
                        insert(&root, 6);
                             insert(&root, 11);
                                  insert(&root, -1);
                                  insert(&root, 1);
                                  insert(&root, 2);


    while (1) {
        printf("\n>>> ");
        scanf(" %d", &opt);
        
        if (opt == 1) {
            int x;
            long int n, max;
            printf("Insert lots of numbers? (1-Y/2-N): ");
            scanf(" %d", &x);
            if (x == 1) {
                printf("Number of numbers: ");
                scanf(" %ld", &n);
                printf("Max value (the max is not included): ");
                scanf(" %ld", &max);

                insertRandomNumbers(&root, n, max);

            } else if (x == 2) {
                printf("Value to insert: ");
                scanf(" %ld", &val);

                insert(&root, val);
            }

        } else if (opt == 2) {
            printf("Value to search: ");
            scanf(" %ld", &val);
            
            Node* elem = search(root, val);
            if (elem == NULL) {
                printf ("%ld not found\n", val);
            
            } else {
                printf("%ld found\n", val);
            }


        } else if (opt == 3) {
            printf("Value to erase: ");
            scanf(" %ld", &val);

            erase(&root, val);

        } else if (opt == 4) {           
            printf(" 1 - Pre-Order\n 2 - In-Order\n 3 - Post-Order\n 4 - BFS\n: ");
            int n;
            
            scanf(" %d", &n);
            if (n == 1) {
                printPreOrder(root);

            } else if (n == 2) {
                printInOrder(root);
            
            } else if (n == 3) {
                printPostOrder(root);

            } else if (n == 4) {
                printBFS(root);
            }
        
        } else if (opt == 5) {
            clear(root);
            root = NULL;
        
        } else if (opt == 6) {
            long int h = calcTreeHeight(root);
            printf("%ld, with root,\n", h);
            printf("%ld, without.\n", h - 1);

        } else if (opt == 7) {
            int n = countNumberOfNodes(root);
            printf("Number of nodes: %d\n", n);

        } else if (opt == 8) {
            printf("Get predecessor of: ");
            scanf(" %ld", &val);
            Node *p = getPredecessor(root, NULL, val);
            if (!empty(p)) {
                printf("Predecessor of %ld is %ld\n", val, p -> value);

            } else {
                printf("Value has no predecessor.\n");
            }

        } else if (opt == 9) {
            printf("Get sucessor of: ");
            scanf(" %ld", &val);
            Node *s = getSucessor(root, NULL, val);
            if (!empty(s)) {
                printf("Sucessor of %ld is %ld\n", val, s -> value);
            
            } else {
                printf("The value has no sucessor.\n");
            }

        } else if (opt == 10) {
            showMenu();
        
        } else if (opt == 0) {
            printf("Goodbye.\n");
            clear(root);
            break;

        } else {
            printf("What did you said?\n");
        }
    }
    return 0;
}
