#include <stdio.h>
#include <stdlib.h>

/* ── Node ─────────────────────────────────────── */
struct Node {
    int data;
    struct Node* next;
};

/* ── Queue ────────────────────────────────────── */
struct Queue {
    struct Node* front;
    struct Node* rear;
};

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

int isEmpty(struct Queue* q) { return q->front == NULL; }

void enqueue(struct Queue* q, int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = val; n->next = NULL;
    if (q->rear == NULL) { 
	q->front = q->rear = n; 
	return; }
    q->rear->next = n;
    q->rear = n;
}

int dequeue(struct Queue* q) {
    if (isEmpty(q)) { printf("Underflow!\n"); return -1; }
    struct Node* tmp = q->front;
    int val = tmp->data;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(tmp);
    return val;
}

int peek(struct Queue* q) {
    if (isEmpty(q)) { printf("Empty!\n"); return -1; }
    return q->front->data;
}

void display(struct Queue* q) {
    if (isEmpty(q)) { printf("Queue: [empty]\n"); return; }
    printf("Queue (front→rear): ");
    struct Node* cur = q->front;
    while (cur) { printf("%d ", cur->data); cur = cur->next; }
    printf("\n");
}

/* ── Main ─────────────────────────────────────── */
int main() {
    struct Queue* q = createQueue();

    enqueue(q, 10); enqueue(q, 20);
    enqueue(q, 30); enqueue(q, 40);
    display(q);    // 10 20 30 40

    printf("Front: %d\n", peek(q));   // 10
    printf("Dequeue: %d\n", dequeue(q)); // 10
    display(q);    // 20 30 40

    free(q);
    return 0;
}