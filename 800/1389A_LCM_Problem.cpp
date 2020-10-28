/*
    Problem Link    :   https://codeforces.com/problemset/problem/1389/A
    Contest Link    :   https://codeforces.com/contest/1389/problem/A
    Status          :   Accepted

    Author          :   Nikhil Nagrale
    Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
    Codechef        :   https://www.codechef.com/users/nikhilnagrale2
    Github          :   https://github.com/nikhilnagrale2

    Copyright       :   Solve it on your own.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int l, r;
        cin >> l >> r;
        if (2 * l > r)
            cout << "-1 "
                 << "-1" << endl;
        else
            cout << l << " " << 2 * l << endl;
    }
    return 0;
}