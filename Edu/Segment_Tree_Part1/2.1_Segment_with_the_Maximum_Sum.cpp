/*
  Problem Link    :   https://codeforces.com/edu/course/2/lesson/4/2/practice/contest/273278/problem/A
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

struct item
{
    long long seg, pref, suf, sum;
};

struct segtree
{
    int size;
    vector<item> values;

    item Neutral = {0, 0, 0, 0};

    item merge(item a, item b)
    {
        return {
            max({a.seg, b.seg, a.suf + b.pref}),
            max(a.pref, a.sum + b.pref),
            max(b.suf, b.sum + a.suf),
            a.sum + b.sum};
    }

    item single(int v)
    {
        if (v > 0)
        {
            return {v, v, v, v};
        }
        else
        {
            return {0, 0, 0, v};
        }
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

    item Calc(int l, int r, int x, int lx, int rx)
    {
        if (l >= rx || r <= lx)
            return Neutral;
        if (l <= lx && r >= rx)
            return values[x];
        int m = (rx + lx) / 2;
        item s1 = Calc(l, r, 2 * x + 1, lx, m);
        item s2 = Calc(l, r, 2 * x + 2, m, rx);
        return merge(s1, s2);
    }

    item Calc(int l, int r)
    {
        return Calc(l, r, 0, 0, size);
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
    cout << st.Calc(0, n).seg << endl;
    while (m--)
    {
        int i, v;
        cin >> i >> v;
        st.set(i, v);
        cout << st.Calc(0, n).seg << endl;
    }
    return 0;
}