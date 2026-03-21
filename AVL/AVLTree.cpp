#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* left;
		Node* right;
		int height;
		
		Node(int val){
			data=val;
			left=right=NULL;
			height=1;
		}
};

class AVL{
	public:
		int getHeight(Node* n){
			if(n==NULL){
				return 0;
			}
			return n->height;
		}
		
		int getBalance(Node* n){
			if(n==NULL){
				return 0;
			}
			return getHeight(n->left)-getHeight(n->right);
		}
		
		Node* rightRotate(Node* y){
			Node* x=y->left;
			Node* T2=x->right;
			
			x->right=y;
			y->left=T2;
			
			y->height=max(getHeight(y->left),getHeight(y->right))+1;
			x->height=max(getHeight(x->left),getHeight(x->right))+1;
		return x;
		}
		
		Node* leftRotate(Node* x){
			Node* y=x->right;
			Node* T2=y->left;
			
			y->left=x;
			x->right=T2;
			
			x->height=max(getHeight(x->left),getHeight(x->right))+1;
			y->height=max(getHeight(y->left),getHeight(y->right))+1;
			
		return y;
		}
		
		Node* insert(Node* node,int key){
			if(node==NULL)
				return new Node(key);
				
			if(key<node->data)
				node->left=insert(node->left,key);
				
			else if(key>node->data)
			    node->right=insert(node->right,key);
			else
			   return node;
			   
			  node->height=1+max(getHeight(node->left),getHeight(node->right));
			  
			  int balance=getBalance(node);
			  
			  //LL case
			  if(balance>1 && key<node->left->data)
			     return rightRotate(node);
				 
			  //RR case
			  if(balance<-1 && key<node->right->data)
			     return leftRotate(node);
				 
			  //LR case		
			  if(balance>1 && key>node->left->data)	{
			  	     node->left=leftRotate(node->left);
			    	 return rightRotate(node);
			  }
			  
			  //Rl case
			    if(balance<-1 && key<node->right->data){
			    	node->right=rightRotate(node->right);
			    	return leftRotate(node);
				}
				return node;
		}
		void inorder(Node* root){
			if(root!=NULL){
				inorder(root->left);
				cout<<root->data<<" ";
				inorder(root->right);
			}
		}
};

int main(){
	AVL tree;
	Node* root=NULL;
	
	root=tree.insert(root,10);
	root=tree.insert(root,20);
	root=tree.insert(root,30);
	root=tree.insert(root,40);
	root=tree.insert(root,50);
	root=tree.insert(root,25);
	cout<<"CODE BY : Khushima Nembang"<<endl;
	
	cout<<"\n---------AVL TREE--------------\n";-
	cout<<"Inorder traversal: ";
	tree.inorder(root);
return 0;
}
