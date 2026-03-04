#include<iostream>
using namespace std;

int LinearSearch(int a[],int n,int key){
	for(int i=0;i<n;i++){
		if(key==a[i]){
			return i; // found
		}
	}
	return -1; //not found
}

int main(){
	int n;
	cout<<"Enter the no.of elements: ";
	cin>>n;
	int a[n];
	cout<<"Enter the elements: "<<endl;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int key;
	cout<<"Enter the element to search: ";
	cin>>key;
	int res=LinearSearch(a,n,key);
	if(res!=-1){
		cout<<"Element found at index : "<<res<<endl;
	}else{
		cout<<"Element not found"<<endl;
	}
return 0;
}
