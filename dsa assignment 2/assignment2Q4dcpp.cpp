#include<iostream>
using namespace std;
int main(){
	int n,i,j;
	char arr[50];
	cout<<"enter the string";
	cin.getline(arr,50);
	for(i=0;arr[i]!='\0';i++){
	for(j=i+1;arr[j]!='\0';j++){
		if(arr[i]>arr[j]){
			char temp;
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
	    	}
		}
	}
	for(i=0;arr[i]!='\0';i++)
	cout<<arr[i];
	return 0;
}
