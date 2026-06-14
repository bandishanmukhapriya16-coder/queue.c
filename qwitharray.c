#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Queue variables
int queue[MAX_SIZE];
int front = -1;
int rear  = -1;

// ── Check if Empty ──────────────────────────────────
bool isEmpty() {
    return front == -1;
}

// ── Check if Full ───────────────────────────────────
bool isFull() {
    return rear == MAX_SIZE - 1;
}

// ── Enqueue: Add element at the Rear ───────────────
void enqueue(int value) {
    if (isFull()) {
        printf("Queue Overflow! Cannot enqueue %d\n", value);
        return;
    }
    if (isEmpty()) {
        front = 0;  // Set front on first insertion
    }
    rear++;
    queue[rear] = value;
    printf("Enqueued: %d\n", value);
}

// ── Dequeue: Remove element from the Front ─────────
int dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow! Queue is empty.\n");
        return -1;
    }
    int value = queue[front];
    if (front == rear) {
        // Queue becomes empty after this removal
        front = -1;
        rear  = -1;
    } else {
        front++;
    }
    printf("Dequeued: %d\n", value);
    return value;
}

// ── Peek: View Front element without removing ───────
void peek() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Front element: %d\n", queue[front]);
}

// ── Display all elements ────────────────────────────
void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue [Front -> Rear]: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

// ── Main: Demo ──────────────────────────────────────


int main() {
    int choice, item;

    do {
        printf("\n ┌─────────────────────────────┐\n");
        printf("  │  Queue MENU  with Array │\n");
        printf("  ├─────────────────────────────┤\n");
        printf("  │  1. Enqueue                 │\n");
        printf("  │  2. Dequeue                 │\n");
        printf("  │  3. Peek (Front element)    │\n");
        printf("  │  4. Display                 │\n");
        printf("  │  5. Exit                    │\n");
        printf("  └─────────────────────────────┘\n");
        printf("  Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("  Enter value to Enqueue: ");
                scanf("%d", &item);
                enqueue(item);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("\n  Exiting... Goodbye!\n\n");
                break;

            default:
                printf("\n  [!] Invalid choice. Please enter 1-7.\n");
        }

    } while (choice != 5);

    return 0;
}

