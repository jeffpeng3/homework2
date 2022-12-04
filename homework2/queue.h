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

Node* deQueue(Queue* queue);

int isQueueEmpty(Queue* queue);

void releaseQueue(Queue* queue);