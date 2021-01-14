#include <stdio.h>
#include <stdlib.h>
#include "binarysearchtree.h"

int main(void) {
  // Build a binary search tree
  Node *root = NULL;
  printf("Minimum value of this bst: %d\n", min_bst(root));
  
  insert_bst(&root, 10);
  insert_bst(&root, 15);
  insert_bst(&root, 18);
  insert_bst(&root, 6);
  insert_bst(&root, 12);
  insert_bst(&root,  20);
  insert_bst(&root,  9);
  display(root);
  printf("\n");

  if (search_bst(root, 10)) {
    printf("Found!: 10\n");
  } else {
    printf("Not found!: 10\n");
  }
  
  if (search_bst(root, 20)) {
    printf("Found!: 20\n");
  } else {
    printf("Not found!: 20\n");
  }

  if (search_bst(root, 15)) {
    printf("Found!: 15\n");
  } else {
    printf("Not found!: 15\n");
  }

  if (search_bst(root, 7)) {
    printf("Found!: 7\n");
  } else {
    printf("Not found!: 7\n");
  }

  printf("Minimum value of this bst: %d\n", min_bst(root));

  delete_bst(&root, 20);
  display(root);
  printf("\n");
  delete_bst(&root, 6);
  display(root);
  printf("\n");
  delete_bst(&root, 15);
  display(root);
  printf("\n");
  delete_bst(&root, 10);
  display(root);
  printf("\n");

  return EXIT_SUCCESS;
}