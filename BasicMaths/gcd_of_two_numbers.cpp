#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int GCD(int n1, int n2) {
        while (n1 > 0 && n2 > 0) {
            if (n1 > n2) n1 %= n2;
            n2 %= n1;
        }

        if (n2 == 0) return n1;
        return n2;
    }
};

int main() {
    int n1, n2;
    cin >> n1 >> n2;

    Solution sol;
    cout << sol.GCD(n1, n2) << "\n";

    return 0;
}