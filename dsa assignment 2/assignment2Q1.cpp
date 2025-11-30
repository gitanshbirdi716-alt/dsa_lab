#include<iostream>
using namespace std;
int main(){
	int n,i,j,x,y,mid,high,low;
	cout<<"how many elements you want to enter";
	cin>>n;
	int arr[n];
	cout<<"enter elements of array";
	for(i=0;i<n;i++)
	cin>>arr[i];
	//sorting it first
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
		if(arr[i]>arr[j]){
			int temp;
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
		}
	}
	cout<<"sorted array :";
	for(i=0;i<n;i++)
	cout<<arr[i]<<"  ";
	//binary search
	cout<<"enter the target value you want to search"<<endl;
	cin>>x;
	high=n-1;
	low=0;
	while(low<=high){
	mid=(low+high)/2;
	if(x==arr[mid]){
	cout<<"target value at position through binary search"<<mid<<endl;
	break;}
	else
	{
		if(arr[mid]>x)
			high=mid-1;
		if(arr[mid]<x)
			low=mid+1;
			else
			cout<<"target not in array through binary search"<<endl;;
		}
	}
//linear search
i=0;
while(i<n){
	if(x==arr[i])
	{cout<<"target at position "<<i<<" through linear search";
	break;}
	else
	i++;
}
if(i==n)
cout<<"target not found in linear search";

	return 0;
}
