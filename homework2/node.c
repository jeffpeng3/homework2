#include "node.h"
#include "queue.h"
#include "utils.h"
Node* getNode(Node* root, int value)
{
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
	if (*current == NULL)
	{
		*current = node;
		return 0;
	}
	if (node->value > (*current)->value)
	{
		return insertNode(&((*current)->right), node);
	}
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
	printTree(current->left);
	printf("%d ", current->value);
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
	if ((root->value > num1) && (root->value > num2))
	{
		return findLowestCommonNode(root->left, num1, num2);
	}
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
	if (current->right)
	{
		return getLargest(current->right);
	}
	return current->value;
}

void releaseTree(Node* current){
	if (!current)
	{
		return;
	}
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
	int maxHeight, height;
	int maxLength = getIntLen(getLargest(root));
	int temp;
	maxHeight = height = getHeight(root);
	Queue* queue = calloc(1, sizeof(Queue));
	if (!queue)
	{
		return;
	}
	Node* endFlag = (void*)1;
	Node* node;
	printf("the graph of tree:");
	enQueue(queue, endFlag);
	enQueue(queue, root);
	while (!isQueueEmpty(queue) && (height > -1))
	{
		node = deQueue(queue);
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
		if (node == NULL)
		{
			printf("%*s%*s", ((maxLength) / 2) + 1, "-", (maxLength - 1) / 2, "");
			enQueue(queue, NULL);
			enQueue(queue, NULL);
		}
		else
		{
			temp = node->value;

			printf("%*d%*s", (maxLength + getIntLen(temp) + 1) / 2, temp, (maxLength - getIntLen(temp)) / 2, "");
			enQueue(queue, node->left);
			enQueue(queue, node->right);
		}
		if (queue->head->value != (void*)1)
		{
			printSpace(maxLength * ((1 << (height + 1)) - 1));
		}
	}
	printf("\n");
	releaseQueue(queue);
	free(queue);
}