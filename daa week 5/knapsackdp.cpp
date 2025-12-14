#include <iostream>
using namespace std;

int dp[20][20];
int w[20], v[20];
int a, b;

int main()
{
    cin >> a;
    cin >> b;

    for (int i = 1; i <= a; i++)
        cin >> w[i];

    for (int i = 1; i <= a; i++)
        cin >> v[i];

    for (int i = 0; i <= a; i++)
    {
        for (int j = 0; j <= b; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (w[i] <= j)
                dp[i][j] = max(dp[i-1][j],
                               v[i] + dp[i-1][j-w[i]]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    cout << dp[a][b];
}
