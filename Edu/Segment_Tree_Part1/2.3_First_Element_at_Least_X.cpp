/*
  Problem Link    :   https://codeforces.com/edu/course/2/lesson/4/2/practice/contest/273278/problem/C
  Contest Link    :   https://codeforces.com/edu/course/2/lesson/4/2/practice
  Status          :   Accepted

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2

  Copyright       :   Study and Solve. :) 
*/

#include <bits/stdc++.h>
using namespace std;

struct segtree
{
    int size;
    vector<int> values;

    int Neutral = INT_MIN;

    int merge(int a, int b)
    {
        return max(a, b);
    }

    int single(int v)
    {
        return v;
    }

    void init(int n)
    {
        size = 1;
        while (size < n)
            size *= 2;
        values.resize(2 * size);
    }

    void build(vector<int> &a, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            if (lx < (int)a.size())
            {
                values[x] = single(a[lx]);
            }
            return;
        }
        int m = (lx + rx) / 2;
        build(a, 2 * x + 1, lx, m);
        build(a, 2 * x + 2, m, rx);
        values[x] = merge(values[2 * x + 1], values[2 * x + 2]);
    }

    void build(vector<int> &a)
    {
        build(a, 0, 0, size);
    }

    void set(int i, int v, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            values[x] = single(v);
            return;
        }

        int m = (lx + rx) / 2;
        if (i < m)
        {
            set(i, v, 2 * x + 1, lx, m);
        }
        else
        {
            set(i, v, 2 * x + 2, m, rx);
        }
        values[x] = merge(values[2 * x + 1], values[2 * x + 2]);
    }

    void set(int i, int v)
    {
        set(i, v, 0, 0, size);
    }

    int Calc(int l, int r, int x, int lx, int rx)
    {
        if (l >= rx || r <= lx)
            return Neutral;
        if (l <= lx && r >= rx)
            return values[x];
        int m = (rx + lx) / 2;
        int s1 = Calc(l, r, 2 * x + 1, lx, m);
        int s2 = Calc(l, r, 2 * x + 2, m, rx);
        return merge(s1, s2);
    }

    int Calc(int l, int r)
    {
        return Calc(l, r, 0, 0, size);
    }

    int find(int k, int x, int lx, int rx)
    {
        if (rx - lx == 1)
            return lx;
        int m = (lx + rx) / 2;
        int sl = values[2 * x + 1];
        if (k < sl)
        {
            return find(k, 2 * x + 1, lx, m);
        }
        else
        {
            return find(k - sl, 2 * x + 2, m, rx);
        }
    }

    int find(int k)
    {
        return find(k, 0, 0, size);
    }

    int first_above(int v, int x, int lx, int rx)
    {
        if (values[x] < v)
            return -1;
        if (rx - lx == 1)
            return lx;
        int m = (lx + rx) / 2;
        int res = first_above(v, 2 * x + 1, lx, m);
        if (res == -1)
        {
            res = first_above(v, 2 * x + 2, m, rx);
        }
        return res;
    }

    int first_above(int v)
    {
        return first_above(v, 0, 0, size);
    }
};

int main()
{
    int n, m;
    cin >> n >> m;

    segtree st;
    st.init(n);

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    st.build(a);
    while (m--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int i, v;
            cin >> i >> v;
            st.set(i, v);
        }
        else
        {
            int x;
            cin >> x;
            cout << st.first_above(x) << endl;
        }
    }
    return 0;
}