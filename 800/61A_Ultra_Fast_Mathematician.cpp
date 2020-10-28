/*
    Problem Link    :   https://codeforces.com/problemset/problem/61/A
    Contest Link    :   https://codeforces.com/contest/61/problem/A
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
    string a, b;
    cin >> a >> b;
    string v = "";
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] == b[i])
            v += "0";
        else
            v += "1";
    }
    cout << v << endl;
    return 0;
}