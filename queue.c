
#include <stdio.h>
#define SIZE 5


int queue[SIZE];
int front = -1, rear = -1;


void enqueue(int val) {
   if (rear == SIZE - 1) {
       printf("Queue is full!\n");
   } else {
       if (front == -1) front = 0;
       rear++;
       queue[rear] = val;
       printf("%d enqueued\n", val);
   }
}


void dequeue() {
   if (front == -1 || front > rear) {
       printf("Queue is empty!\n");
   } else {
       printf("%d dequeued\n", queue[front]);
       front++;
       if (front > rear) front = rear = -1;
   }
}


void display() {
   if (front == -1) {
       printf("Queue is empty!\n");
   } else {
       printf("Queue: ");
       for (int i = front; i <= rear; i++) {
           printf("%d ", queue[i]);
       }
       printf("\n");
   }
}


void peek() {
   if (front == -1) {
       printf("Queue is empty!\n");
   } else {
       printf("Front element: %d\n", queue[front]);
   }
}


int main() {
   int choice, val;


   while (1) {
       printf("\n1.Enqueue 2.Dequeue 3.Display 4.Peek 5.Exit\n");
       printf("Enter choice: ");
       scanf("%d", &choice);


       switch (choice) {
           case 1:
               printf("Enter value: ");
               scanf("%d", &val);
               enqueue(val);
               break;
           case 2:
               dequeue();
               break;
           case 3:
               display();
               break;
           case 4:
               peek();
               break;
           case 5:
               return 0;
           default:
               printf("Invalid choice!\n");
       }
   }
}
