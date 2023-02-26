#include "Queue.h"

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

QueueEntry *NewQueueEntry(uint32_t data) {
	QueueEntry *queue_entry = (QueueEntry *)malloc(sizeof(QueueEntry));
	queue_entry->next = NULL;
	queue_entry->data = data;
	return queue_entry;
}

void DeleteQueueEntry(QueueEntry *queue_entry) {
	free(queue_entry->next);
	free(queue_entry);
}

Queue *NewQueue() {
	Queue *queue = (Queue *)malloc(sizeof(Queue));
	return queue;
}

void *Enqueue(Queue *queue, uint32_t data) {
	QueueEntry *queue_entry = NewQueueEntry(data);
	if(queue->head == NULL) {
		queue->head = queue_entry;
		queue->tail = queue_entry;
	} else {
		queue->tail->next = queue_entry;
		queue->tail = queue_entry;
	}
	return queue;
}

void Dequeue(Queue *queue) {
	if(queue->head == NULL) {
		perror("queue is empty\n");
		exit(1);
	}
	QueueEntry *queue_entry = queue->head;
	queue->head = queue->head->next;
	if(queue->head == NULL) {
		queue->tail = NULL;
	}
	free(queue_entry);
}

void DeleteQueue(Queue *queue) {
	free(queue);
}
