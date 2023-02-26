#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct QueueEntry {
	struct QueueEntry *next;
	uint32_t data;
} QueueEntry;

typedef struct Queue {
	QueueEntry *head;
	QueueEntry *tail;
} Queue;

QueueEntry *NewQueueEntry(uint32_t data);

void DeleteQueueEntry(QueueEntry *queue_entry);

Queue *NewQueue();

void *Enqueue(Queue *queue, uint32_t data);

void Dequeue(Queue *queue);

void DeleteQueue(Queue *queue);
