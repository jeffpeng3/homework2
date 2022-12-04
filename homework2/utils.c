#include "utils.h"
#include "node.h"
Node* root = NULL;

FILE* dataSource;
char fileName[51] = { 0 };
const char* prompt =
"====================================================\n\
code	description\n\
(a)	Insert a key into a binary search tree.\n\
(c)	Clear this tree.\n\
(f)	Find the lowest common ancestor node of two given nodes in the tree.\n\
(g)	Draw this tree.\n\
(h)	Compute the height of a binary search tree.\n\
(p)	Print out all keys in increasing order.\n\
(q)	Quit.\n\
(r)	Remove the key with the lowest value.\n\
(t)	Randomly insert some node.\n\
please select mode:";

int seleteOperation(char mode)
{
	int value, result;
	int num1, num2;
	Node* node;
	switch (mode)
	{
		case 'a':
		{
			printf("Please enter a 32-bit integer :");
			scanf_s(" %d", &value);
			node = generateNode(value);
			result = insertNode(&root, node);
			if (result == 0)
			{
				printf("%d Inserted successfully.\n", value);
			}
			else
			{
				printf("%d Inserted failed:duplicate.\n", value);
			}
			return 0;
		}
		case 'r':
		{
			if (!root)
			{
				printf("tree is not exist.\n");
				return 1;
			}
			removeLowest(&root);
			return 0;
		}
		case 'p':
		{
			printTree(root); // use function to print node
			return 0;
		}
		case 'h':
		{
			// use function to deduplicate linked list
			result = getHeight(root);
			if (result != -1)
			{
				printf("the tree height is %d.\n", result);
			}
			else
			{
				printf("tree is not exist.\n");
			}
			return 0;
		}
		case 'f':
		{
			printf("Please enter two number:\n--number 1:");
			scanf_s(" %d", &num1);
			printf("--number 2:");
			scanf_s(" %d", &num2);
			node = findLowestCommonNode(root, num1, num2);
			if (!node)
			{
				printf("tree is not exist.\n");
				return 0;
			}
			if (!getNode(node, num1))
			{
				printf("Number is not exist in this tree.\n");
				return 0;
			}
			if (!getNode(node, num2))
			{
				printf("Number is not exist in this tree.\n");
				return 0;
			}
			printf("lowest common node is %d\n", node->value);
			return 0;
		}
		case 'g':
		{
			drawTree(root); // use function to print node
			return 0;
		}
		case 't':
		{
			printf("How many node you need :");
			scanf_s(" %d", &value);
			for (int i = 0; i < value; i++)
			{
				node = generateNode(rand());
				if (insertNode(&root, node))
				{
					i--;
				}
			}
			printf("Successfully added %d nodes.\n", value);
			return 0;
		}
		case 'c':
			{
				releaseTree(root);
				root = NULL;
				return 0;
			}
		case 'q':
		{
			return -1;
		}
		default:
		{
			printf("unknown mode\n");
			return 0;
		}
	}
	printf("========================================================================================\n");
	return 0;
}

void printSpace(int count)
{
	printf("%*s", count, "");
}

int getIntLen(int value)
{
	int l = 1;
	while (value > 9)
	{
		l++;
		value /= 10;
	}
	return l;
}