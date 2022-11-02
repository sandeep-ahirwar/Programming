#include <iostream>
using namespace std;

int solve()
{
    int m, n, p;
    cin >> m >> n >> p;
    int scores[m][n];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> scores[i][j];
        }
    }

    int steps = 0;

    for (int i = 0; i < n; i++)
    {
        int temp = scores[p - 1][i];
        for (int j = 0; j < m; j++)
        {
            if (scores[j][i] > temp)
            {
                temp = scores[j][i];
            }
        }
        steps = steps + temp - scores[p - 1][i];
    }
    return steps;
}

int main()
{
    int t;
    int i = 1;
    cin >> t;
    while (t > 0)
    {

        int ans = solve();
        t--;
        cout << "Case #" << i << ": " << ans << endl;
        i++;
    }
}