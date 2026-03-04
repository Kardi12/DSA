#include<iostream>
using namespace std;

void Hepify(int a[],int n,int i){
	int l=2*i; //left child
	int r=2*i+1; //right child
	int largest=i;
	if(l<=n && a[l]>a[largest]){
		largest=l;
	}
	if(r<=n && a[r]>a[largest]){
		largest= r;
	}
	if(largest!=i){
		int temp=a[i];
		a[i]=a[largest];
		a[largest]=temp;
		Hepify(a,n,largest);
	}
	
}

void BuildHeap(int a[],int n){
	for(int i=n/2;i>=1;i--){
		Hepify(a,n,i);
	}
}

void HeapSort(int a[],int n){
	BuildHeap(a,n);
	for(int i=n;i>=2;i--){
		int temp=a[1];
		a[1]=a[i];
		a[i]=temp;
		Hepify(a,i-1,1);
	}
}

int main(){
	int n;
	cout<<"Enter the no.of elements: ";
	cin>>n;
	int a[n+1];
	cout<<"Enter the elements: "<<endl;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	HeapSort(a,n);
	cout<<"Sorted array: "<<endl;
	for(int i=1;i<=n;i++){
		cout<<a[i]<<" ";	
	}
return 0;
}
