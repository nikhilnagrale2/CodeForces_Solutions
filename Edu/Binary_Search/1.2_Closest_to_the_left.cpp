/*
  Problem Link    :
  https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/B
  Contest Link    :   https://codeforces.com/edu/course/2/lesson/6/1/practice
  Status          :   Accepted

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        int l = -1, r = n;
        while (r > l + 1) {
            int m = (l + r) / 2;
            if (a[m] <= x) {
                l = m;
            } else {
                r = m;
            }
        }
        cout << l + 1 << endl;
    }
    return 0;
}