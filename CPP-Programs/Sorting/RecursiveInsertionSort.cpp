#include<bits/stdc++.h>
using namespace std;
void display(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void insertionSort(int arr[], int i, int n) {
    if(i==n) return;
    int j=i;
    while(j>0 && arr[j-1]>arr[j]) {
        swap(arr[j-1], arr[j]);
        j--;
    }
    insertionSort(arr, i+1, n);
}
int main() {
    int arr[1000], n;
    cout<<"Enter the size of array : "<<endl;
    cin>>n;
    cout<<"Enter "<<n<<" elements : "<<endl;
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    cout<<"The array before insertion sort is : "<<endl;
    display(arr, n);
    cout<<"The array after insertion sort is : "<<endl;
    insertionSort(arr, 0,  n);
    display(arr, n);
    return 0;
}