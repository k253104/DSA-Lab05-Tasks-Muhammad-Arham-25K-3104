#include<iostream>
#include<string>
using namespace std;

class Stack{
	int top;
	string items[100];
	public:
	Stack(){
		top = -1;
	}
	
	bool isEmpty(){
		return top<0;
	}
	
	bool isFull(){
		return top >= 99;
		}
		
	bool push(string x){
		if(isFull()){
			return false;
		}
		
		items[++top]=x;
		return true;
	}
	
	string pop(){
		if(isEmpty()){
			return "";
		}
		return items[top--];
	}
	
	string peek(){
		if(isEmpty()){
			return "";
		}
		return items[top];
	}
	
	void clear(){
		top = -1;
	} 
};

class TextEditor{
	string document;
	Stack undoStack;
	Stack redoStack;
	
	public:
		TextEditor(){
			document = "";
		}
		
	void type(string word){
		if (document == ""){
		document = word;
		}
		else 
		document = document + " " + word;
		
		undoStack.push(word);
		redoStack.clear();	
	}
	
	void undo(){
		if(undoStack.isEmpty()){
			return;
		}
		
		redoStack.push(document);
		
		undoStack.pop();
		
		if(undoStack.isEmpty()){
			document = "";
		}    
		else{
			document = undoStack.peek();
		}
	}
	
	void redo(){
		if(redoStack.isEmpty()){
			return;
		}
		
		undoStack.push(document);
		
		document=redoStack.pop();
	}
	
	void print(){
		cout << "Document: " << document << endl;
	}
};

int main(){
	TextEditor editor;
	
	 editor.type("Hello");
    editor.print();

    editor.type("World");
    editor.print();

    editor.undo();
    editor.print();

    editor.redo();
    editor.print();

    editor.undo();
    editor.print();

    editor.type("There");
    editor.print();

    editor.redo();
    editor.print();

    return 0;
}


 