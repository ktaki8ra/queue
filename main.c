#include <stdio.h>

#include "Queue.h"

int main() {
	Queue *queue = NewQueue();

	Enqueue(queue, 10);
	Enqueue(queue, 20);
	Enqueue(queue, 30);
	Enqueue(queue, 40);
	Enqueue(queue, 50);
	Enqueue(queue, 60);
	Enqueue(queue, 70);

	Dequeue(queue);
	Dequeue(queue);
	Dequeue(queue);

	printf("queue->head->data: %d\n", queue->head->data);
	printf("queue->head->next->data: %d\n", queue->head->next->data);
	printf("queue->head->next->next->data: %d\n", queue->head->next->next->data);

	DeleteQueue(queue);

	return 0;
}
