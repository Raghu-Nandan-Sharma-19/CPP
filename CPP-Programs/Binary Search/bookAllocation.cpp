#include<bits/stdc++.h>
using namespace std;
// Function to find the maximum element in a vector
int maxElement(vector<int> &arr) {
    int n = arr.size(), maxi = INT_MIN; // Initialize the maximum element to the minimum possible value
    for(int i=0; i<n; i++) {
        maxi = max(maxi, arr[i]); // Update the maximum element if a larger element is found
    }
    return maxi; // Return the maximum element
}

// Function to find the sum of all elements in a vector
int sumOfElements(vector<int> &arr) {
    int sum = 0, n = arr.size(); // Initialize the sum to zero
    for(int i=0; i<n; i++) {
        sum += arr[i]; // Add each element to the sum
    }
    return sum; // Return the sum of all elements
}

// Function to count the number of students required to read a book with given pages
int countStudents(vector<int> &arr, int pages) {
    int students = 1, pagesStudent = 0, n = arr.size(); // Initialize the number of students and pages read by a student
    for(int i=0; i<n; i++) {
        if(pagesStudent + arr[i] <= pages) {
            pagesStudent += arr[i]; // If current student can read this book, add its pages to the student's count
        } else {
            students++; // If not, increment student count and assign this book's pages to a new student
            pagesStudent = arr[i];
        }
    }
    return students; // Return the total number of students required
}

// Function to find the minimum number of pages a student has to read such that each student gets at least one book and the maximum pages read by a student is minimized
int findPages(vector<int>& arr, int n, int m) {
    if(m > n) return -1; // If number of students is greater than number of books, it's not possible
    int low = maxElement(arr), high = sumOfElements(arr); // Set low to the maximum element and high to the sum of all elements
    while(low <= high) {
        int mid = (low+high)/2; // Calculate the mid value for binary search
        if(countStudents(arr, mid) > m) low = mid+1; // If more students are required, increase the minimum pages read by a student
        else high = mid-1; // Otherwise, try to minimize the maximum pages read by a student
    }
    return low; // Return the minimum number of pages a student has to read
}
int main() {
    vector<int> arr = {25, 46, 28, 49, 24};
    int n = arr.size();
    int m = 4;
    int ans = findPages(arr, n, m);
    cout << "The answer is: " << ans << "\n";
    return 0;
}