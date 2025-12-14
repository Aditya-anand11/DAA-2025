#include <iostream>
#include <climits>
using namespace std;

int g[20][20];
int dp[20][1 << 20];
int a;

int f(int i, int m)
{
    if (m == (1 << a) - 1)
        return g[i][0];

    if (dp[i][m] != -1)
        return dp[i][m];

    int c = INT_MAX;

    for (int j = 0; j < a; j++)
    {
        if (!(m & (1 << j)))
            c = min(c, g[i][j] + f(j, m | (1 << j)));
    }

    return dp[i][m] = c;
}

int main()
{
    cin >> a;

    for (int i = 0; i < a; i++)
        for (int j = 0; j < a; j++)
            cin >> g[i][j];

    for (int i = 0; i < a; i++)
        for (int j = 0; j < (1 << a); j++)
            dp[i][j] = -1;

    cout << f(0, 1);
}
