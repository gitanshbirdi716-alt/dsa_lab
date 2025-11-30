#include<iostream>
using namespace std;
int main(){
	int i,j;
	char arr[50];
	cout<<"enter the string";
	cin.getline(arr,50);
	for(i=0;arr[i]!='\0';i++){
	if(arr[i]=='a' ||arr[i]=='e' ||arr[i]=='o' ||arr[i]=='u' ||arr[i]=='i'){
		for(j=i;arr[j]!='\0';j++)
		arr[j]=arr[j+1];
	}
	
}
for(i=0;arr[i]!='\0';i++)
cout<<arr[i];
	return 0;
}
