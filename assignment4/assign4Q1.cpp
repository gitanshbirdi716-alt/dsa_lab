#include<iostream>
using namespace std;
#define SIZE 5
int queue[SIZE];
int front=-1;
int rear=-1;
bool isfull(){
	return rear==SIZE-1;
}
bool isempty(){
	return front==-1;
}
void enqueue(int val){
	if(isfull()) cout<<"Queue already full."<<endl;
	if(front==-1)front=0;
	rear++;
	queue[rear]=val;
}
void dequeue(){
	if(front==-1) cout<<"Queue is empty."<<endl;
	front++;
}
void display(){
	for(int i=front;i<=rear;i++){
	cout<<queue[i];}
	cout<<endl;
}
void peek(){
	if (front==-1) cout<<"queue is empty.";
	else cout<<"First element is:"<<queue[front]<<endl;
}
 main(){
cout<<"MENU:\n";
cout<<"1.ENQUEUE\n2.DEQUEUE\n3.CHECK IF EMPTY\n4.CHECK IF FULL\n5.DISPLAY\n6.PEEK\n7.EXIT"<<endl;
int choice;
int val;

while(1){
		cout<<"Enter choice:";
        cin>>choice;
	switch(choice){
	
		case 1: 
		cout<<"Enter value to add:";
		cin>>val;
		enqueue(val);
		break;
		
		case 2: 
		dequeue();
		break;
		
		case 3: 
		if(isempty())
		cout<<"Queue is empty"<<endl;
		else 	cout<<"Queue is not empty"<<endl;
		break;
		
		case 4:
			if(isfull())
		cout<<"Queue is full"<<endl;
		else 	cout<<"Queue is not full"<<endl;
		break;

		case 5:
		display();
		break;
		case 6:
			
		peek();
		break;
		
		case 7:
		return 0;							
	}
}
}
