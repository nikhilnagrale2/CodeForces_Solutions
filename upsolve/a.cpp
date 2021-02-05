/*
  Problem Link    :   https://codeforces.com/problemset/problem/1/A
  Contest Link    :   https://codeforces.com/contest/1/problem/A
  Status          :   Accepted

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2

  Copyright       :   Study and Solve. :) 
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;

        cout << (int)((int)(a ^ (int)(a & b)) + (b ^ (int)(a & b))) << endl;
    }

    return 0;
}