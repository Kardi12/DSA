#include<iostream>
using namespace std;

#define size 10

int HashTable[size];

int HashFunction(int key){
	return key%size;
}

void insert(int key){
	int index=HashFunction(key);
	
	//Linear probing
	while(HashTable[index]!=-1){
		index=(index+1)%size;
	}
	HashTable[index]=key;
}


void display(){
	cout<<"Hash Table: "<<endl;
	for(int i=0;i<size;i++){
		cout<<i<<"-->";
		if(HashTable[i]==-1){
			cout<<"Empty";
		}else{
			cout<<HashTable[i];
		}
		cout<<endl;
	}
}


int main(){
	int n,key;
	cout<<"CODE BY : KHUSHIMA NEMBANG"<<endl;
	for(int i=0;i<size;i++){
		HashTable[i]=-1;
	}
	cout<<"Enter the number of elements: ";
	cin>>n;
	
	for(int i=0;i<n;i++){
		cout<<"Enter value: ";
		cin>>key;
		insert(key);
	}
	display();
return 0;
}
