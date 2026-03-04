#include <iostream>
using namespace std;

void selectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min=i;
        
        for (int j = i+1; j < n ; j++) {
            if (a[j] < a[min]) {
                // Swap a[j] and a[j+1]
                min=j;
            }
        }
        int temp=a[i];
        a[i]=a[min];
        a[min]=temp;
    }
}

int main() {
    int n;

	cout<<"---Selection Sort---"<<endl;
    cout << "Enter number of elements: ";
    cin >> n;

    int a[n];
    cout << "Enter array elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    selectionSort(a, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}
