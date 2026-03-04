#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int value){
        data = value;
        left = NULL;
        right = NULL;
    }
};

class BST{
public:
    Node* root;

    BST(){
        root = NULL;
    }

    // Insert node
    Node* insert(Node* root, int value){
        if(root == NULL){
            return new Node(value);
        }

        if(value < root->data){
            root->left = insert(root->left, value);
        }else{
            root->right = insert(root->right, value);
        }

        return root;
    }

    // Search node
    bool search(Node* root, int key){
        if(root == NULL){
            return false;
        }

        if(root->data == key){
            return true;
        }

        if(key < root->data){
            return search(root->left, key);
        }else{
            return search(root->right, key);
        }
    }
};

int main(){

    BST tree;
    int n, value, key;

    cout<<"Enter the number of nodes: ";
    cin>>n;

    cout<<"Enter elements:"<<endl;

    for(int i=0;i<n;i++){
        cin>>value;
        tree.root = tree.insert(tree.root, value);
    }

    cout<<"Enter key element to search: ";
    cin>>key;

    if(tree.search(tree.root, key)){
        cout<<"Key element found in BST";
    }else{
        cout<<"Key element not found in BST";
    }

    return 0;
}
