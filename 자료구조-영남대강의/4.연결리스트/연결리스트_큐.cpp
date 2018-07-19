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

class Queue{
	public:
		Node* first;
		Node* last;
		int length;
		
		Queue();
		~Queue();
		
		void inqueue(int data);
		void dequeue();
		
		int getLength();
		void printQue();
};

Queue::Queue(){
	this->first = NULL;
	this->last = NULL;
	this->length = 0;
}

Queue::~Queue(){
	while(this->first){
		Node* tmp = this->first;
		this->first = this->first->nextNode;
		delete tmp;
	}
}

void Queue::inqueue(int data){
	if(this->last == NULL){
		this->first = new Node(data);
		this->last = this->first;
	}
	else{
		this->last->nextNode = new Node(data);
		this->last = this->last->nextNode;
	}
	
	cout << "inqueue : " << data << endl;
	this->length++;
}

void Queue::dequeue(){
	if(this->first==NULL){
		cout << "Queue is empty" << endl;
	}
	else{
		int data = this->first->data;
		Node* tmp = this->first;
		this->first = tmp->nextNode;
		delete tmp;
		
		cout << "dequeue : " << data << endl;
		this->length--;
	}
}

int Queue::getLength(){
	return this->length;
}

void Queue::printQue(){
	Node* tmp = this->first;
	while(tmp){
		cout << tmp->data << ", ";
		tmp = tmp->nextNode;
	}
}


int main(){
	
	Queue queue;
	
	queue.inqueue(1);
	queue.inqueue(2);
	queue.inqueue(3);
	
	cout << "length : " << queue.getLength() << endl;
	
	cout << "print : " ;
	queue.printQue();
	cout<< endl;
	cout<< endl;
	
	queue.dequeue();
	cout << "length : " << queue.getLength() << endl;
	
	cout << "print : " ;
	queue.printQue();
	cout<< endl;
	cout<< endl;
	cout<< endl;
	
	queue.dequeue();
	cout << "length : " << queue.getLength() << endl;
	
	cout << "print : " ;
	queue.printQue();
	cout<< endl;
	cout<< endl;
	cout<< endl;
	
	queue.inqueue(4);
	queue.dequeue();
	
	cout << "length : " << queue.getLength() << endl;
	
	cout << "print : " ;
	queue.printQue();
	cout<< endl;
	
	return 0;
}

