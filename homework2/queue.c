#include "queue.h"

void enQueue(Queue* queue, Node* node)
{
	if (!queue)
	{
		return;
	}
	QueueNode* queueNode = calloc(1, sizeof(QueueNode));
	if (queueNode)
	{
		queueNode->value = node;
	}
	else
	{
		return;
	}
	if (!queue->head)
	{
		queue->head = queueNode;
		queue->end = queueNode;
		return;
	}
	queue->end->next = queueNode;
	queue->end = queueNode;
}

QueueNode* deQueue(Queue* queue)
{
	if (!queue)
	{
		return NULL;
	}
	if (!queue->head)
	{
		return NULL;
	}
	QueueNode* queueNode = queue->head;

	queue->head = queue->head->next;
	return queueNode;
}

int isQueueEmpty(Queue* queue)
{
	if (!queue)
	{
		return 1;
	}
	if (!queue->head)
	{
		return 1;
	}
	return 0;
}

void releaseQueue(Queue* queue){
	if (!queue){
		return;
	}
	QueueNode* temp;
	while (queue->head)
	{
		temp = queue->head;
		queue->head = queue->head->next;
		free(temp);
	}
}