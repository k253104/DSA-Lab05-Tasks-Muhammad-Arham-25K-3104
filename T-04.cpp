#include<iostream>
using namespace std;

class Queue {
    int front;
    int rear;
    int items[6];

public:

    Queue() {
        front=-1;
        rear=-1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear+1)%6==front;
    }

    bool enqueue(int x) {
        if (isFull()) {
            cout << "Queue is full" << endl;
            return false;
        }

        if (isEmpty()) {
            front=0;
            rear=0;
        }
        else {
            rear = (rear+1)%6;
        }

        items[rear] = x;
        return true;
    }

    int dequeue() {
        if (isEmpty()) {
            return -1;
        }

        int value = items[front];

        if (front==rear) {
            front=-1;
            rear=-1;
        }
        else {
            front = (front+1)%6;
        }

        return value;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }

        int i=front;

        while (true) {
            cout << items[i] << " ";

            if (i==rear) {
                break;
            }

            i=(i+1)%6;
        }

        cout << endl;
    }

    int getFront() {
        return front;
    }

    int getRear() {
        return rear;
    }
};


int main() {

    Queue q;
    q.enqueue(101);
    q.enqueue(102);
    q.enqueue(103);
    q.enqueue(104);
    q.enqueue(105);
    q.enqueue(106);
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.enqueue(107);
    q.enqueue(108);
    q.enqueue(109);
    q.dequeue();
    q.dequeue();
    q.enqueue(110);
    q.dequeue();
    q.enqueue(111);
    q.enqueue(112);

    cout << "Final passengers in boarding order: ";
    q.display();

    cout << "Final front position: " << q.getFront() << endl;
    cout << "Final rear position: " << q.getRear() << endl;

    return 0;
}