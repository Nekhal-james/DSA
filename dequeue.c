
#include <stdio.h>
#define MAX 5

int dq[MAX], front = -1, rear = -1;

void insertFront(int val) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Deque full!\n"); return;
    }
    if (front == -1) front = rear = 0;
    else if (front == 0) front = MAX - 1;
    else front--;
    dq[front] = val;
    printf("%d inserted at front\n", val);
}

void insertRear(int val) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Deque full!\n"); return;
    }
    if (rear == -1) front = rear = 0;
    else if (rear == MAX - 1) rear = 0;
    else rear++;
    dq[rear] = val;
    printf("%d inserted at rear\n", val);
}

void deleteFront() {
    if (front == -1) { printf("Deque empty!\n"); return; }
    printf("%d deleted from front\n", dq[front]);
    if (front == rear) front = rear = -1;
    else if (front == MAX - 1) front = 0;
    else front++;
}

void deleteRear() {
    if (rear == -1) { printf("Deque empty!\n"); return; }
    printf("%d deleted from rear\n", dq[rear]);
    if (front == rear) front = rear = -1;
    else if (rear == 0) rear = MAX - 1;
    else rear--;
}

void display() {
    if (front == -1) { printf("Deque is empty\n"); return; }
    int i = front;
    printf("Deque: ");
    while (1) {
        printf("%d ", dq[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int ch, v;
    do {
        printf("\n1.Insert Front  2.Insert Rear  3.Delete Front  4.Delete Rear  5.Display  6.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        if (ch == 1) { printf("Value: "); scanf("%d", &v); insertFront(v); }
        else if (ch == 2) { printf("Value: "); scanf("%d", &v); insertRear(v); }
        else if (ch == 3) deleteFront();
        else if (ch == 4) deleteRear();
        else if (ch == 5) display();
        else if (ch != 6) printf("Invalid choice!\n");
    } while (ch != 6);
}
