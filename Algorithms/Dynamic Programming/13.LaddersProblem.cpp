#include <bits/stdc++.h>
using namespace std;

int dp[1000] = {};
int LadderRecursive(int n, int k)
{
    if (n == 0)
        return 1;
    int ans = 0;
    for (int i = 1; i <= k; i++)
    {
        if (n - i >= 0)
        {
            ans += LadderRecursive(n - i, k);
        }
    }
    return ans;
}

int LadderTopDownDP(int n, int k)
{
    if (n == 0)
        return 1;

    if (dp[n] != 0)
        return dp[n];
    int ans = 0;
    for (int i = 1; i <= k; i++)
    {
        if (n - i >= 0)
        {
            ans += LadderRecursive(n - i, k);
        }
    }
    return dp[n] = ans;
}

int LadderBottomUpDP(int n, int k)
{
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = 0;
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
                dp[i] += dp[i - j];
        }
    }
    return dp[n];
}

int LadderBottomUpOptimizedDP(int n, int k)  
{
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= k; i++)
        dp[i] = 2 * dp[i - 1];

    for (int i = k + 1; i <= n; i++)
        dp[i] = 2 * dp[i - 1] - dp[i - k - 1];

    return dp[n];
}

int main()
{
    int n, k;
    cin >> n >> k;
    cout << LadderBottomUpOptimizedDP(n, k) << endl;
    return 0;
}