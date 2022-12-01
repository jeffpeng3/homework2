#pragma once 
#include "node.h"
typedef struct _queueNode
{
	Node* value;
	struct _queueNode* next;
} QueueNode;

typedef struct _queue
{
	QueueNode* end;
	QueueNode* head;
} Queue;

void enQueue(Queue* queue, Node* node);

QueueNode* deQueue(Queue* queue);

int isQueueEmpty(Queue* queue);