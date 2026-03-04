#include<iostream>
using namespace std;

void shellSort(int a[],int n){
	for(int gap=n/2;gap>0;gap/=2){
		for(int i=gap;i<n;i++){
			int temp=a[i];
			int j=i;
			
			while(j>=gap && a[j-gap]>temp){
				a[j]=a[j-gap];
				j-=gap;
			}
			a[j]=temp;
		}
	}
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
	shellSort(a,n);
	
	cout<<"Sorted array: "<<endl;
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
return 0;
}
