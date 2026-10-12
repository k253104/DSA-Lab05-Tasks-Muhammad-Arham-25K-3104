#include<iostream>
using namespace std;
class Stack{
	int top;
	int operations[8];
	
	public:
	Stack(){
		top=-1;
	}
	
	bool isEmpty(){
		return top<0  ;
	}
	
	bool isFull(){
		return top >= 7;
	}
	
	bool push(int x){
		if(isFull()){
			return false;
		}
		operations[++top]=x;
		return true;
	}
	
	bool undo(){
		if(isEmpty()){
			return false;
		}
		operations[top--];
		return true;
	}
	
	void displayTop(){
		if (isEmpty()){
			cout<<"Stack is empty!" << endl;
		}
		else{
			cout<<"Current top operation: "<< operations[top] << endl;
		}
	}
	
	void display(){
		if (isEmpty()){
			cout<<"Stack is empty!" << endl;
			return;
		}
		cout<<"Operations from top to bottom:";
		
		for (int i=top ; i>=0; i--){
			cout << operations[i] << " ";
		}
	}
	
	
};

int main(){
	Stack s;
	s.push(12);
	  s.displayTop();
	s.push(25);
	  s.displayTop();
	s.push(17);
	  s.displayTop();
	s.push(31);
	  s.displayTop();
	s.push(44);
	  s.displayTop();
	s.push(19);
	  s.displayTop();
	
	s.undo();
   	s.displayTop();
	s.undo();
	s.displayTop();
	s.undo();
	s.displayTop();
	
	s.push(52);
	  s.displayTop();
	  
	s.undo();
	s.displayTop();
	s.undo();
	s.displayTop();
	
	s.display();
	return 0;
}