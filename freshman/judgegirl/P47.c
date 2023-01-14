# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Treenode {
	char val;
	int num_left;
	struct Treenode* left, * right;
} Node;

# define insert 'i'

Node* genNode(char val, Node* left, Node* right) {
	Node* node = malloc(sizeof(Node));
	node->val = val;
	node->num_left = 0;
	node->left = left, node->right = right;
	return node;
}

Node* largetimeprocess(Node* root, char val, int* timeptr) {
	(*timeptr)--;
	root->right = genNode(val, NULL, NULL);
	return (root->right);
}

Node* insertTree(Node* root, char val, int index, int findend, int* timeptr) {
	if (root == NULL) {
		root = genNode(val, NULL, NULL);
		if(*timeptr == 1) return root;
		(*timeptr)--;
		Node* C_root = root;
		while (*timeptr != 1)
			root = largetimeprocess(root, val, timeptr);
		root = C_root;
	}

	int l = root->num_left;
	if (index - 2 < l && findend == 0) {
		(root->num_left) += *timeptr;
		root->left = insertTree(root->left, val, index, findend, timeptr);
		if (*timeptr != 1) {
			Node* C_root = root;
			root = root->left;
			while (*timeptr != 1)
				root = largetimeprocess(root, val, timeptr);
			root = C_root;
		}
	}
	else {
		if(findend == 0) index = index - l - 1;
		root->right = insertTree(root->right, val, index, findend, timeptr);
		if (*timeptr != 1) {
			Node* C_root = root;
			root = root->right;
			while (*timeptr != 1)
				root = largetimeprocess(root, val, timeptr);
			root = C_root;
		}
	}	
	return root;
}

///////////////////////////////////////////////////////////////////////

void freeTree(Node* root) {
	if (root == NULL) return;
	freeTree(root->left);
	freeTree(root->right);
	free(root);
}

Node* process_insert(Node* root) {
	int index, times;
	int findend = 0;
	char type[6];
	char val;
	scanf("%s %c %d", type, &val, &times);

	if (type[0] == 'r') {
		index = -1;
		findend = 1;
	}
	else if (type[0] == 'l')
		index = 1;
	else 
		index = atoi(type);
	root = insertTree(root, val, index, findend, &times);
	
	return root;
}

void printTree(Node* root, char* charptr, int* intptr) {
	if (root == NULL) return;

	printTree(root->left, charptr, intptr);	

	char c = *charptr, v = root->val;
	int i = *intptr;
	if (i == 0) {
		(*intptr)++;
		*charptr = v;
	}
	else if (c == v)
		(*intptr)++;
	else {
		printf("%c %d ", c, i);
		*charptr = v;
		*intptr = 1;
	}

	printTree(root->right, charptr, intptr);
}

int main() {
	char type[8] = { 0 };
	char tchar;
	int tint;
	int cnt;	
	Node* root = NULL;
	
	while (scanf("%s", type) != EOF) {
		
		switch ((type[0])) {
		case insert:
			root = process_insert(root);
			break;
		default:
			tint = 0;                                                //  printf("main work\n");
			printTree(root, &tchar, &tint);
			if(root != NULL)
				printf("%c %d ", tchar, tint);
			printf("$\n");
			break;
		}
	}
	freeTree(root);

	return 0;
}

