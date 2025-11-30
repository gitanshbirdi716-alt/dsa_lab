#include<iostream>
using namespace std;
int main(){
	//bubble sort
	int n,i,j;
	int arr[]={64, 34, 25, 12, 22, 11, 90};
	n=sizeof(arr)/sizeof(arr[0]);
	for(i=0;i<n-1;i++){
	for(j=0;j<n-i-1;j++){
		int temp;
		if(arr[j]>arr[j+1]){
			temp=arr[j];
			arr[j]=arr[j+1];
			arr[j+1]=temp;
		}
	}
	
}
for(i=0;i<n;i++)
cout<<" "<<arr[i];
	return 0;
}
