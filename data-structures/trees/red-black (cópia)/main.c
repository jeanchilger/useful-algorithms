#include <stdio.h>
#include <stdlib.h>
#include "redBlack.h"

int main() {
	int opt;
    long int val;
	Node *root = NULL;
    
    showMenu();

    insert(&root, &root, 9);
	insert(&root, &root, 5);
	insert(&root, &root, 10);
	insert(&root, &root, 0);


    while (1) {
        printf("\n>>> ");
        scanf(" %d", &opt);

        if (opt == 1) {
            printf("Value to insert: ");
            scanf(" %ld", &val);

            insert(&root, NULL, val);
			// printf("COLOR OF ROOT IS (0 - RED; 1 - BLACK): %d\n", root -> color);

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
            int h = calcTreeHeight(root);
            printf("%d, counting root,\n", h);
            printf("%d, not counting.\n", h - 1);

        } else if (opt == 7) {
            int n = countNumberOfNodes(root);
            printf("Number of nodes: %d\n", n);

        } else if (opt == 9) {
            showMenu();

        } else if (opt == 0) {
            printf("Goodbye.\n");
            break;

        } else {
            printf("What did you said?\n");
        }
    }
    return 0;
}
