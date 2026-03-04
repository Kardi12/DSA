#include <iostream>
using namespace std;

void bubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Last i elements are already in place
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                // Swap a[j] and a[j+1]
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;

	cout<<"---Bubble Sort---"<<endl;
    cout << "Enter number of elements: ";
    cin >> n;

    int a[n];
    cout << "Enter array elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    bubbleSort(a, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}
