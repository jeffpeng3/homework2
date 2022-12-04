#pragma once
#include "utils.h"

typedef struct _node
{
	int value;
	struct _node* left;
	struct _node* right;
} Node;

extern struct _node* root;

Node* generateNode(int value);

Node* getNode(Node* root, int value);

int insertNode(Node** current, Node* node);

void removeLowest(Node** root);

void printTree(Node* current);

int getHeight(Node* current);

Node* findLowestCommonNode(Node* root, int num1, int num2);

void drawTree(Node* current);//need draw

void releaseTree(Node* current);
