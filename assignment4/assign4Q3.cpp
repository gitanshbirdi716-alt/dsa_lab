#include<iostream>
#include <queue>
using namespace std;
queue<int> q;
void res(queue <int> &q){
	if(q.size()%2!=0) {
printf("Cannnot interleave.\n"); 
return;
}
int halfsize= q.size()/2;
queue<int>half;
for(int i=0;i<halfsize;i++){
	half.push(q.front());
	q.pop();
}
while(!half.empty()){
	q.push(half.front());
	half.pop();
	q.push(q.front());
	q.pop();
}
}
void display(queue<int>q){
	while(!q.empty()){
	cout<<q.front()<<endl;
	q.pop();}
}

int main(){
	queue<int> q;
	q.push(4);
	q.push(7);
	q.push(11);
	q.push(20);	
	q.push(5);
	q.push(9);
	res(q);
display(q);
	return 0;
}
