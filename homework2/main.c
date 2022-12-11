#include "main.h"
#include <time.h>
int main()
{
	srand((unsigned int)time(0));
	char mode;
	while (1)
	{
		printf("%s", prompt);
		scanf_s(" %c", &mode, 1);                             // get user enter as mode select
		clearOutput();                                        // clear the console output to make it look easier
		if (seleteOperation(mode))
		{
			break;
		}
	}
	releaseTree(root);
	return 0;
} 
