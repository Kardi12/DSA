#include<iostream>
using namespace std;

void merge(int a[], int left, int mid, int right) {
    int n1 = mid - left + 1;  
    int n2 = right - mid;      
    int L[100], R[100];

    for(int i = 0; i < n1; i++)
        L[i] = a[left + i];
    for(int j = 0; j < n2; j++)
        R[j] = a[mid + 1 + j];
    int i = 0;    
    int j = 0;    
    int k = left;  
   
    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        } else {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while(i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }
    while(j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }
}

void MergeSort(int a[], int left, int right) {
    if(left < right) {
        int mid = left + (right - left) / 2;  
        MergeSort(a, left, mid);
        MergeSort(a, mid + 1, right);
        merge(a, left, mid, right);
    }
}

int main() {
    int n;
    cout<<"CODE BY: KHUSHIMA NEMBANG"<<endl;
    cout << "Enter the no. of elements: ";
    cin >> n;
    
    int a[n];
    cout << "Enter the elements: "<<endl;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    MergeSort(a, 0, n - 1);
   
    cout << "Sorted array: "<<endl;
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
   
    return 0;
}
