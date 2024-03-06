#include<bits/stdc++.h>
using namespace std;
void display(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void bubbleSort(int arr[], int n) {
    if(n==1) return;
    for(int j=0; j<=n-2; j++) {
        if(arr[j]>arr[j+1]) {
            swap(arr[j], arr[j+1]);
        }
    }
    bubbleSort(arr, n-1);
}
int main() {
    int arr[1000], n;
    cout<<"Enter the size of the array : "<<endl;
    cin>>n;
    cout<<"Enter "<<n<<" elements : "<<endl;
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    cout<<"The array before bubble sort is : "<<endl;
    display(arr, n);
    cout<<"The array after bubble sort is : "<<endl;
    bubbleSort(arr, n);
    display(arr, n);
    return 0;
}