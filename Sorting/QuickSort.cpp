#include<iostream>
using namespace std;

int partition(int a[], int l, int r) {
    int p= a[l];  
    int i = l;        
    int j = r;        
    int temp;
   
    while(i < j) {
        while(i <= r && a[i] <=p)
            i++;
        while(j >= l && a[j] >p)
            j--;
        if(i < j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    temp = a[l];
    a[l] = a[j];
    a[j] = temp;
    return j;
}

void QuickSort(int a[], int l, int r) {
    if(l < r) {
        int p = partition(a, l, r);  
        QuickSort(a, l, p - 1);      
        QuickSort(a, p + 1, r);      
    }
}

int main() {
    int n;
    cout<<"CODE BY : KHUSHIMA NEMBANG"<<endl;
    cout << "Enter the no. of elements: ";
    cin >> n;
   
   	int a[n];
    cout << "Enter the elements: "<<endl;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    QuickSort(a, 0, n - 1);
   
    cout << "Sorted array: "<<endl;
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
   
    return 0;
}
