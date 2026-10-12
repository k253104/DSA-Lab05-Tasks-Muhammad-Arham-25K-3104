#include<iostream>
using namespace std;

class Stack {
    int top;
    string items[100];

public:

    Stack() {
        top=-1;
    }

    bool isEmpty() {
        return top<0;
    }

    bool push(string x) {
        if (top>=99) {
            return false;
        }

        items[++top] = x;
        return true;
    }

    string pop() {
        if (isEmpty()) {
            return "";
        }

        return items[top--];
    }
};


class Queue {
    int front;
    int rear;
    string items[100];

public:

    Queue() {
        front=0;
        rear=-1;
    }

    bool isEmpty() {
        return front>rear;
    }

    bool enqueue(string x) {
        if (rear>=99) {
            return false;
        }

        items[++rear] = x;
        return true;
    }

    string dequeue() {
        if (isEmpty()) {
            return "";
        }

        return items[front++];
    }

    int getSize() {
        return rear-front+1;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }

        for (int i=front; i<=rear; i++) {
            cout << items[i] << " ";
        }

        cout << endl;
    }
};


void reverseFirstK(Queue &q, int k) {

    Stack s;

    for (int i=0; i<k; i++) {
        s.push(q.dequeue());
    }

    while (!s.isEmpty()) {
        q.enqueue(s.pop());
    }

    int remaining = q.getSize()-k;

    for (int i=0; i<remaining; i++) {
        q.enqueue(q.dequeue());
    }
}


int main() {

    Queue q;
    q.enqueue("J1");
    q.enqueue("J2");
    q.enqueue("J3");
    q.enqueue("J4");
    q.enqueue("J5");
    q.enqueue("J6");
    q.enqueue("J7");

    cout << "Original Queue: ";
    q.display();

    int k = 3;

    reverseFirstK(q,k);

    cout << "After reversing first " << k << " elements: ";
    q.display();

    return 0;
}