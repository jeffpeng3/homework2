#include "utils.h"
#include "node.h"

Node* root = NULL;

FILE* dataSource;
char fileName[51] = { 0 };
const char* prompt =
"====================================================\n\
code	description\n\
(a)	Insert a key into a binary search tree.\n\
(r)	Remove the key with the lowest value.\n\
(p)	Print out all keys in increasing order.\n\
(h)	Compute the height of a binary search tree.\n\
(f)	Find the lowest common ancestor node of two given nodes in the tree.\n\
(g)	Draw this tree.\n\
(q)	Quit.\n\
please select mode:";

int seleteOperation(char mode)
{
	int value, result;
	int num1, num2;
	switch (mode)
	{
		case 'a':
			printf("Please enter a 32bit signed integer :");
			scanf_s(" %d", &value);
			result = insertNode(&root, value);
			if (result == 0)
			{
				printf("%d Inserted successfully.\n", value);
			}
			else
			{
				printf("%d Inserted failed:duplicate.\n", value);
			}
			return 0;
		case 'r':
			result = removeLowest(&root);
			if (result == 0)
			{
				printf("remove successfully.\n");
			}
			else
			{
				printf("tree is not exist.\n");
			}
			return 0;
		case 'p':
			printTree(root); // use function to print node
			return 0;
		case 'h':
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
		case 'f':
			printf("Please enter two number:\n--number 1:");
			scanf_s(" %d", &num1);
			printf("--number 2:");
			scanf_s(" %d", &num2);
			Node* commonNode = findLowestCommonNode(root, num1, num2);
			if (!commonNode)
			{
				printf("Number is not exist in this tree.\n");
				return 0;
			}
			printf("lowest common node is %d\n", commonNode->value);
			return 0;
		case 'g':
			drawTree(root); // use function to print node
			return 0;
		case 'q':
			return -1;
		default:
			printf("unknown mode\n");
			return 0;
	}
	printf("========================================================================================\n");
	return 0;
}

void printSpace(int count)
{
	for (int i = 0; i < count; i++)
	{
		printf(" ");
	}
}
int getIntLen(int value)
{
	int l = 1;
	while (value > 9)
	{
		l++; value /= 10;
	}
	return l;
}