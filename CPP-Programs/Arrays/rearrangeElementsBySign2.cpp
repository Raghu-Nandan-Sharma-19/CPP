#include<bits/stdc++.h>
using namespace std;
void display(vector<int> arr) {
    for(int i=0; i<arr.size(); i++) {
        cout<<arr[i]<<" ";
    } cout<<endl;
}
// Function to rearrange elements of the array by sign
vector<int> rearrangeBySign(vector<int> arr) {
    int n = arr.size();
    // Define 2 vectors, one for storing positive 
    // and other for negative elements of the array.
    vector<int> pos;
    vector<int> neg;
  
    // Segregate the array into positives and negatives.
    for(int i=0;i<n;i++){
        if(arr[i]>0) pos.push_back(arr[i]);
        else neg.push_back(arr[i]);
    }
  
    // If positives are lesser than the negatives.
    if(pos.size() < neg.size()){
        // First, fill array alternatively till the point 
        // where positives and negatives ar equal in number.
        for(int i=0;i<pos.size();i++){
            arr[2*i] = pos[i];
            arr[2*i+1] = neg[i];
        }
        // Fill the remaining negatives at the end of the array.
        int index = pos.size()*2;
        for(int i = pos.size();i<neg.size();i++){
            arr[index] = neg[i];
            index++;
        }
    }
    // If negatives are lesser than the positives.
    else{
        // First, fill array alternatively till the point 
        // where positives and negatives ar equal in number.
        for(int i=0;i<neg.size();i++){
            arr[2*i] = pos[i];
            arr[2*i+1] = neg[i];
        }
        // Fill the remaining positives at the end of the array.
        int index = neg.size()*2;
        for(int i = neg.size();i<pos.size();i++){
            arr[index] = pos[i];
            index++;
        }
    }
    return arr;
}
int main() {
    int size;
    cout<<"Enter the size of the array : "<<endl;
    cin>>size;
    vector<int> arr;
    cout<<"Enter "<<size<<" elements : "<<endl;
    for(int i=0; i<size; i++) {
        int x;
        cin>>x;
        arr.push_back(x);
    }
    cout<<"The array after rearranging elements by sign is : "<<endl;
    vector<int> ans = rearrangeBySign(arr);
    display(ans);
    return 0;
}