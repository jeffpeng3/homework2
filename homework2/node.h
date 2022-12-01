#pragma once 
#include "utils.h"

typedef struct _node
{
	int value;
	struct _node* left;
	struct _node* right;
} Node;


int insertNode(Node** root, int value);

int removeLowest(Node** root);

void printTree(Node* current);//need draw

int getHeight(Node* current);

Node* findLowestCommonNode(Node* root,int num1,int num2);

void drawTree(Node* current);//need draw

