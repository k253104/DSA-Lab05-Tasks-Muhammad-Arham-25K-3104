#include<iostream>
using namespace std;

class Stack {
    int top;
    int items[100];

public:

    Stack() {
        top=-1;
    }

    bool isEmpty() {
        return top<0;
    }

    bool push(int x) {
        if (top>=99) {
            return false;
        }

        items[++top] = x;
        return true;
    }

    int pop() {
        if (isEmpty()) {
            return -1;
        }

        return items[top--];
    }
};


class MyQueue {
    Stack incoming;
    Stack outgoing;

public:

    void enqueue(int x) {
        incoming.push(x);
    }

    int dequeue() {
        if (outgoing.isEmpty()) {

            while (!incoming.isEmpty()) {
                outgoing.push(incoming.pop());
            }
        }

        return outgoing.pop();
    }
};


int main() {

    MyQueue q;

    q.enqueue(1);   
    q.enqueue(2);   

    cout << "Dequeued: " << q.dequeue() << endl;

    q.enqueue(3);   

    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;

    return 0;
}