#include<iostream>
using namespace std;
int main(){
	int n,i,j,sum,sumarr=0,low,high,mid;
    cout<<"enter number of elements you want to enter";
    cin>>n;
    int arr[n];
    cout<<"enter continuous elements where a single digit is missing from 1 to "<<n+1;
	for(i=0;i<n;i++)
	cin>>arr[i];
	//linear time
	sum=(n+1)*(n+2)/2;
	for(i=0;i<n;i++){
	sumarr+=arr[i];	
	}
	cout<<"the missing number is "<<sum-sumarr<<endl;
	//binary search
	low=0;
	high=n;
	while(low<=high){
	mid=(low+high)/2;
	if(arr[mid]==mid+1){
		low=mid+1;}
	else
	high=mid-1;
}
    cout<<"missing number"<<low+1;
	
	
	
	
	return 0;
}
