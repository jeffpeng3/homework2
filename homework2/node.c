#include "node.h"
#include "queue.h"
#include "utils.h"
#include "math.h"
int insertNode(Node** root, int value)
{
	Node* temp = calloc(1, sizeof(Node));
	if (!temp)
	{
		return 0;
	}
	temp->value = value;
	if (*root == NULL)
	{
		*root = temp;
		return 0;
	}
	Node* current = *root;
	while (1)
	{
		if (value == current->value)
		{
			free(temp);
			return 1;
		}
		if (value > current->value)
		{
			if (current->right)
			{
				current = current->right;
			}
			else
			{
				current->right = temp;
				return 0;
			}
		}
		else
		{
			if (current->left)
			{
				current = current->left;
			}
			else
			{
				current->left = temp;
				return 0;
			}
		}
	}
	return 0;
}

int removeLowest(Node** root)
{
	if (!*root)
	{
		return 1;
	}
	Node* temp = *root, * current = *root;
	if (!current->left)
	{
		temp = *root;
		*root = current->right;
		free(temp);
		return 0;
	}
	while (current->left)
	{
		temp = current;
		current = current->left;
	}
	temp->left = current->right;
	free(current);
	return 0;
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
		printf("root not found\n");
		return NULL;
	}
	if (num1 >= num2)
	{
		num1 ^= num2;
		num2 ^= num1;
		num1 ^= num2;
	}
	Node* current = root;
	int left = (current->value > num1) && (current->value > num2);
	int right = (current->value < num1) && (current->value < num2);
	while (left || right)
	{
		if (left)
		{
			current = current->left;
		}
		else
		{
			current = current->right;
		}
		if (current != 0)
		{
			left = (current->value > num1) && (current->value > num2);
			right = (current->value < num1) && (current->value < num2);
		}
		else
		{
			left = 0;
			right = 0;
		}
	}
	root = current;
	while (1)
	{
		if (!current)
		{
			printf("left not found\n");
			return NULL;
		}
		if (current->value == num1)
		{
			break;
		}
		current = current->left;
	}
	current = root;
	while (1)
	{
		if (!current)
		{

			printf("right not found\n");
			return NULL;
		}
		if (current->value == num2)
		{
			break;
		}
		current = current->right;
	}
	return root;
}
int getLargest(Node* root)
{
	if (!root)
	{
		return 0;
	}
	while (root->right)
	{
		root = root->right;
	}
	return root->value;
}
void drawTree(Node* root)
{
	int maxHeight,height;
	int maxLength = getIntLen(getLargest(root));
	int temp;
	maxHeight = height = getHeight(root);
	Queue* queue = calloc(1, sizeof(Queue));
	Node* endFlag = (void*)1;
	QueueNode* queueNode;
	printf("the graph of tree:");
	enQueue(queue, endFlag);
	enQueue(queue, root);
	while (!isQueueEmpty(queue) && (height > -1))
	{
		queueNode = deQueue(queue);
		if (queueNode->value == (void*)1)
		{
			printf("\nlevel %*d\t|",getIntLen(maxHeight),maxHeight-height+1);
			printSpace(maxLength * (pow(2, height - 1) - 1));
			height--;
			enQueue(queue, endFlag);
			free(queueNode);
			continue;
		}
		if (queueNode->value == NULL)
		{
			printf("%*s%*s", ((maxLength) / 2) + 1, "-", (maxLength - 1) / 2, "");
			enQueue(queue, NULL);
			enQueue(queue, NULL);
		}
		else
		{
			temp = queueNode->value->value;

			printf("%*d%*s", (maxLength + getIntLen(temp) + 1) / 2, temp, (maxLength - getIntLen(temp)) / 2, "");
			enQueue(queue, queueNode->value->left);
			enQueue(queue, queueNode->value->right);
		}
		if (queue->head->value != (void*)1)
		{
			printSpace(maxLength * (pow(2, height + 1) - 1));
		}
		//need remove
	}

	releaseQueue(queue);
	free(queue);
}