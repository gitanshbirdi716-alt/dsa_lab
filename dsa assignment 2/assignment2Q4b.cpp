#include<iostream>
using namespace std;
int main(){
	//reversing string
	int n,i,j;
	char arr[50];
	cout<<"enter string";
	cin.getline(arr,50);
	int sum=0;
	while(arr[sum]!='\0')
	sum++;
	for(i=sum;i>=0;i--)
	cout<<arr[i];
	
	return 0;
}
