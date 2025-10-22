#include <stdio.h>
#define SIZE 5
int q[SIZE],front=-1,rear=-1;
void enqueue(int val) {
    if ((front==0 && rear==SIZE-1) || (rear+1)%SIZE == front) {
        printf("Queue is full!\n");
        return;
    }
    if (front == -1) front = rear = 0;
    else rear = (rear + 1)%SIZE;
    q[rear] = val;
    printf("%d enqueued\n", val);
}
void dequeue(){
    if(front==-1){
        printf("Queue is empty!!\n");
        return;
    }
    printf("%d dequeued",q[front]);
    if(front==rear){
        front=rear=-1;
   
    }
    else {
        front = (front + 1) % SIZE;
    }


}
void display() {
    if (front == -1) {
        printf("Queue is empty!\n");
        return;
    }
    int i = front;
    printf("Queue: ");
    while (1) {
        printf("%d ", q[i]);
        if (i == rear){
            break;
        }
        i = (i + 1) % SIZE;
    }
    printf("\n");
}
void peek(){
    printf("Front element: %d ",q[front]);
}

int main() {
    int ch, v;
    do {
        printf("\n1.Enqueue  2.Dequeue  3.Display  4.Peek  5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        if (ch == 1) { printf("Value: "); scanf("%d", &v); enqueue(v); }
        else if (ch == 2) dequeue();
        else if (ch == 3) display();
        else if (ch == 4) peek();
        else if (ch != 5) printf("Invalid choice!\n");
        } while (ch != 5);
}

 
