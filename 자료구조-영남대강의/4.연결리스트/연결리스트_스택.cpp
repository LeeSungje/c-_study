#include<iostream>

using namespace std;

class Node{
	public:
		int data;
		Node* nextNode;
		
		Node(int data);
		~Node();
};

Node::Node(int data){
	this->data = data;
	this->nextNode = NULL;
}

Node::~Node(){
	
}


class Stack{
	public:
		Node* topNode;
		int length;
		
		Stack();
		~Stack();
		
		void push(int data);
		void pop();
		int getLength();
		void printStack();
};

Stack::Stack(){
	this->topNode = NULL;
	this->length = 0;
}

Stack::~Stack(){
	Node* top = this->topNode;
	
	while(top){
		Node* tmp = top;
		top = top->nextNode;
		delete tmp;
	}
}

void Stack::push(int data){
	if(this->topNode == NULL){
		this->topNode = new Node(data);
	}
	else{
		Node* tmp = this->topNode;
		this->topNode = new Node(data);
		this->topNode->nextNode = tmp;
	}
	this->length++;
	
	cout << "push: " << data << endl;
}

void Stack::pop(){
	if(this->topNode==NULL){
		cout << "stack is empty" << endl;
	}
	else{
		int data = this->topNode->data; 
		Node* tmp = this->topNode;
		this->topNode = tmp->nextNode;
		delete tmp;
		
		this->length--;
		
		cout << "pop: " << data << endl;
	}
}

int Stack::getLength(){
	return length;
}

void Stack::printStack(){
	Node* tmp = this->topNode;
	while(tmp){
		cout << tmp->data << ", ";
		tmp = tmp->nextNode;
	}
	delete tmp;
}


int main(){
	
	Stack stack;
	
	stack.push(1);
	stack.push(2);
	stack.push(3);
	
	cout << "length : " << stack.getLength() << endl;
	
	cout << "print stack : " ;
	stack.printStack();
	cout << endl;
	
	stack.pop();
	stack.pop();
	stack.push(4);
	stack.pop();
	
	cout << "length : " << stack.getLength() << endl;
	cout << "print stack : " ;
	stack.printStack();
	cout << endl;
	
	return 0;
}








