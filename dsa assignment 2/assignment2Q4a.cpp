#include<iostream>
using namespace std;
int main(){
	int n,i,j;
	char arr[50],str[50];
	cout<<"enter the string you want to enter";
	cin.getline(arr,50);
	cin.getline(str,50);
	//concatenate
	int count=0;
	while(arr[count]!='\0')
	count++;
	int sum=0;
	while(str[sum]!=0)
	sum++;
	int x=sum+count;
	char array[x];
	for(i=0;i<count;i++)
		array[i]=arr[i];
	for(i=count;i<x;i++)
	array[i]=str[i-count];
	for(i=0;i<x;i++)
	cout<<array[i];
	return 0;
}
