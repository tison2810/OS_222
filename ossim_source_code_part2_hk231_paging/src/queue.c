// #include <stdio.h>
// #include <stdlib.h>
// #include "queue.h"

// int empty(struct queue_t * q) {
//         if (q == NULL) return 1;
// 	return (q->size == 0);
// }

// void enqueue(struct queue_t * q, struct pcb_t * proc) {
//         /* TODO: put a new process to queue [q] */
// }

// struct pcb_t * dequeue(struct queue_t * q) {
//         /* TODO: return a pcb whose prioprity is the highest
//          * in the queue [q] and remember to remove it from q
//          * */
// 	return NULL;
// }
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t * q) {
	if (q == NULL) return 1;
	return (q->size == 0);
}

void enqueue(struct queue_t * q, struct pcb_t * proc) {
	if (q == NULL || proc == NULL || q->size >= MAX_QUEUE_SIZE) return;
	q->proc[q->size++] = proc;
}

struct pcb_t * dequeue(struct queue_t * q) {
	if (q == NULL || q->size == 0) return NULL;

	struct pcb_t *highest_priority_proc = q->proc[0];
	int highest_priority_index = 0;

	for (int i = 1; i < q->size; i++) {
		if (q->proc[i]->priority > highest_priority_proc->priority) {
			highest_priority_proc = q->proc[i];
			highest_priority_index = i;
		}
	}

	// Shift the remaining processes to fill the gap
	for (int i = highest_priority_index; i < q->size - 1; i++) {
		q->proc[i] = q->proc[i + 1];
	}

	q->size--;
	return highest_priority_proc;
}

