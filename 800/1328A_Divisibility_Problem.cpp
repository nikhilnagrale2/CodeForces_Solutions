/*
    Problem Link    :   https://codeforces.com/problemset/problem/1328/A
    Contest Link    :   https://codeforces.com/contest/1328/problem/A
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
        long long a, b;
        cin >> a >> b;
        if (a % b == 0)
            cout << 0 << endl;
        else
        {
            cout << b - a % b << endl;
        }
    }
    return 0;
}