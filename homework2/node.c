#include "node.h"
#include "queue.h"
#include "utils.h"
Node* getNode(Node* root, int value)
{
	// recursive find
	if (!root)
	{
		return NULL;
	}
	if (root->value < value)
	{
		return getNode(root->right, value);
	}
	if (root->value > value)
	{
		return getNode(root->left, value);
	}
	return root;
}

Node* generateNode(int value)
{
	//malloc a node and put the value in.
	Node* node = calloc(1, sizeof(Node));
	if (!node)
	{
		return NULL;
	}
	node->value = value;
	return node;
}

int insertNode(Node** current, Node* node)
{
	// If the tree is empty, create a new node with the given key and return it
	if (*current == NULL)
	{
		*current = node;
		return 0;
	}
	// If the key is less than the root's key, insert it into the left subtree
	if (node->value > (*current)->value)
	{
		return insertNode(&((*current)->right), node);
	}
	// If the key is greater than the root's key, insert it into the right subtree
	if (node->value < (*current)->value)
	{
		return insertNode(&((*current)->left), node);
	}
	free(node);
	return 1;
}

void removeLowest(Node** root)
{
	static Node* temp;
	if (!(*root)->left)
	{
		temp = *root;
		*root = (*root)->right;
		free(temp);
		return;
	}
	// Recursively remove the key with the lowest value from the left subtree
	return removeLowest(&((*root)->left));
}

void printTree(Node* current) // need draw
{
	static int count = 0;
	if (!current)
	{
		if (count == 0)
		{
			printf("tree is not exist.\n");
		}
		return;
	}
	count++;
	// Recursively print out the keys in the left subtree in increasing order
	printTree(current->left);
	// Print out the current's key
	printf("%d ", current->value);
	// Recursively print out the keys in the right subtree in increasing order
	printTree(current->right);
	if (count == 1)
	{
		printf("\n");
	}
	count--;
}

int getHeight(Node* current)
{
	static int count = 0;
	int num[2];
	if (!current)
	{
		if (count == 0)
		{
			return -1;
		}
		return count;
	}
	count++;
	// Compute the height of the left and right subtrees
	num[0] = getHeight(current->left);
	num[1] = getHeight(current->right);
	count--;
	return (num[0] > num[1] ? num[0] : num[1]);
}

Node* findLowestCommonNode(Node* root, int num1, int num2)
{
	if (!root)
	{
		return NULL;
	}
	// If the root's key is greater than both p and q, search the left subtree
	if ((root->value > num1) && (root->value > num2))
	{
		return findLowestCommonNode(root->left, num1, num2);
	}
	// If the root's key is less than both p and q, search the right subtree
	if ((root->value < num1) && (root->value < num2))
	{
		return findLowestCommonNode(root->right, num1, num2);
	}
	return root;
}

int getLargest(Node* current)
{
	if (!current)
	{
		return 0;
	}
	// Recursively find out the keys in the right subtree
	if (current->right)
	{
		return getLargest(current->right);
	}
	return current->value;
}

void releaseTree(Node* current){
	// If the tree is empty, return NULL
	if (!current)
	{
		return;
	}
	// Recursively clear the left and right subtrees
	releaseTree(current->left);
	releaseTree(current->right);
	free(current);
	return;
}

void drawTree(Node* root)
{
	if (!root)
	{
		printf("tree is not exist.\n");
		return;
	}
	//get width and height
	int maxHeight, height;
	int maxLength = getIntLen(getLargest(root));
	int temp;
	maxHeight = height = getHeight(root);
	//level-order traversal
	Queue* queue = calloc(1, sizeof(Queue));
	if (!queue)
	{
		return;
	}
	Node* endFlag = (void*)1;
	Node* node;
	printf("the graph of tree:");
	//address == 1 then new line
	enQueue(queue, endFlag);
	enQueue(queue, root);
	while (!isQueueEmpty(queue) && (height > -1))
	{
		// pop a node
		node = deQueue(queue);
		// new line and enqueue to queue
		if (node == (void*)1)
		{
			if (height)
			{
				printf("\n\nlevel %*d\t|", getIntLen(maxHeight), maxHeight - height + 1);
				printSpace(maxLength * ((1 << (height - 1)) - 1));
			}
			height--;
			enQueue(queue, endFlag);
			continue;
		}
		// enqueue two empty node and output -
		if (node == NULL)
		{
			printf("%*s%*s", ((maxLength) / 2) + 1, "-", (maxLength - 1) / 2, "");
			enQueue(queue, NULL);
			enQueue(queue, NULL);
		}
		// enqueue two child node and center align key
		else
		{
			temp = node->value;

			printf("%*d%*s", (maxLength + getIntLen(temp) + 1) / 2, temp, (maxLength - getIntLen(temp)) / 2, "");
			enQueue(queue, node->left);
			enQueue(queue, node->right);
		}
		// make it align if it not just new line
		if (queue->head->value != (void*)1)
		{
			printSpace(maxLength * ((1 << (height + 1)) - 1));
		}
	}
	printf("\n");
	// free queue and it's element
	releaseQueue(queue);
	free(queue);
}