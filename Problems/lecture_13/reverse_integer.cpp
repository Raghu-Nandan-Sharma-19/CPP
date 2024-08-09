#include<bits/stdc++.h>
using namespace std;
int main() {
    int num;
    cout<<"Enter a number : ";
    cin>>num;
    int ans = 0, rem;
    
    // checking if the number is not equal to zero
    while (num != 0) {
        // extracting the last digit from the number
        rem = num % 10;
        // dividing the number by 10 and taking out last digit from the number
        num /= 10;
        // if the number is greater than maximum value of integer
        // ans less than minimum value of integer we have to return 0
        if(ans > INT_MAX / 10 || ans < INT_MIN / 10) {
            return 0;
        }
        // doing some calculations and storing the answer in ans variable
        ans = ans * 10 + rem;
    }
    // printing the answer
    cout<<"Number in reverse is : "<<ans<<endl;

    return 0;
}