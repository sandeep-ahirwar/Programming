#include <iostream>
using namespace std;
#define ll long long

ll sum(int arr[], int i, int j)
{
    if (arr[i] < 0)
        return 0;
    ll sum = 0;
    while (i < j)
    {
        sum += arr[i];
        if (sum < 0)
            return 0;
        i++;
    }
    return sum;
}

ll solve(int arr[], int n)
{
    long ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            ans += sum(arr, i, j);
        }
    }
    return ans;
}

int main()
{
    int t, x = 0;
    cin >> t;
    while (x < t)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        ll ans = solve(arr, n);
        cout << "Case #" << x + 1 << ": " << ans << endl;
        x++;
    }
    return 0;
}