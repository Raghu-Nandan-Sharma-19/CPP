#include<bits/stdc++.h>
using namespace std;
// Function to check if mid raised to the power of n is equal to, less than, or greater than m.
// Returns 1 if mid^n == m, 2 if mid^n > m, and 0 otherwise.
int func(int mid, int n, int m) {
  long long ans = 1; // Initialize ans as 1 to store the result of mid raised to the power of n.
  for(int i=1; i<=n; i++) { // Loop through each exponent from 1 to n.
    ans = ans*mid; // Update ans by multiplying it with mid in each iteration.
    if(ans > m) return 2; // If ans exceeds m, return 2 (indicating mid^n > m).
  }
  if(ans == m) return 1; // If ans equals m, return 1 (indicating mid^n == m).
  return 0; // If neither of the above conditions is satisfied, return 0 (indicating mid^n < m).
}

// Function to find the nth root of m using binary search.
int NthRoot(int n, int m) {
  int low = 1, high = m, ans = -1; // Initialize low as 1, high as m, and ans as -1.
  while(low <= high) { // Binary search loop until low is less than or equal to high.
    int mid = (low+high)/2; // Calculate the middle value.
    int value = func(mid, n, m); // Check the value of mid raised to the power of n compared to m using the func() function.
    if(value == 0) { // If mid^n < m, adjust the search range to the right.
      low = mid+1;
    } else if(value == 2) { // If mid^n > m, adjust the search range to the left.
      high = mid-1;
    } else { // If mid^n == m, return mid as the nth root.
      return mid;
    }
  }
  return -1; // If nth root is not found within the given range, return -1.
}
int main() {
    int n, m;
    cout<<"Enter n : "<<endl;
    cin>>n;
    cout<<"Enter m : "<<endl;
    cin>>m;
    cout<<n<<" Th root of "<<m<<" is : "<<NthRoot(n, m)<<endl;
    return 0;
}