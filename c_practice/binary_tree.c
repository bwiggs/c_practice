//
//  binary_tree.c
//  c_practice
//
//  Created by Brian Wigginton on 2/15/12.
//  Copyright 2012 Wiggaware. All rights reserved.
//
#include <stdio.h>

// =============================================================================
// Data Structures
// =============================================================================

struct NODE {
	int value;
	struct NODE* left;
	struct NODE* right;
};
typedef struct NODE NODE;

// =============================================================================
// Prototypes
// =============================================================================

void insertNode(NODE*, int);
NODE* newNode(int);

// =============================================================================
// Variables
// =============================================================================

NODE *root, *ptr;

// =============================================================================
// Main
// =============================================================================

int main() {

	int input;

	while(1){
		printf("Enter an integer value\n");
		scanf("%d", &input);
		insertNode(root, input);
	}
	
	return 0;
}

// =============================================================================
// Methods
// =============================================================================

void insertNode(NODE* node, int value) {
	
	if(node == NULL) {
		node = newNode(value);
		return;
	}
	
	if(value == node->value) {
		return;
	} else if(value < node->value) {
		insertNode(node->left, value);
	} else {
		insertNode(node->right, value);
	}
	
	return;
}

NODE* newNode(int value) {
	return malloc(sizeof(NODE));
}