#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1e5;
ll sz[N];
ll parent[N];
void make(ll n)
{
    sz[n] = 1;
    parent[n] = n;
}
ll find(ll n)
{
    if (parent[n] == n)
        return parent[n];
    else
        return parent[n] = find(parent[n]);
}
void Union(ll a, ll b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        parent[b] = a;
        sz[a] += sz[b];
    }
}
int main()
{
    ll tcg;
    cin >> tcg;
    for (ll k = 1; k <= tcg; k++)
    {
        ll hgh1 = 0, hgh2 = 0;
        ll rad1, rad2;
        ll n;
        ll m;
        cin >> rad1 >> rad2;
        cin >> n;
        vector<ll> d1;
        vector<ll> d2;
        for (ll i = 0; i < n; i++)
        {
            ll x, y;
            cin >> x >> y;
            ll g1 = x * x, g2 = y * y, g3 = (rad1 + rad2);
            ll val1 = g1 + g2;
            ll val2 = g3 * g3;
            if (val1 <= val2)
            {
                d1.push_back(val1);
            }
        }
        cin >> m;
        for (ll i = 0; i < m; i++)
        {
            ll x, y;
            cin >> x >> y;
            ll val1 = x * x + y * y;
            ll val2 = (rad1 + rad2) * (rad1 + rad2);
            if (val1 <= val2)
            {
                d2.push_back(val1);
            }
        }
        sort(d1.begin(), d1.end());
        sort(d2.begin(), d2.end());
        if (d2.size() == 0)
            cout << "Case #" << k << ": " << d1.size() << " " << d2.size() << endl;
        else if (d1.size() == 0)
            cout << "Case #" << k << ": " << d1.size() << " " << d2.size() << endl;
        else
        {
            for (ll i = 0; i < d1.size(); i++)
            {
                int lwd1 = lower_bound(d2.begin(), d2.end(), d1[i]) - d2.begin();
                if (lwd1 == 0)
                    hgh1++;
            }
            for (ll i = 0; i < d2.size(); i++)
            {
                int lwd1 = lower_bound(d1.begin(), d1.end(), d2[i]) - d1.begin();
                if (lwd1 == 0)
                    hgh2++;
            }
            cout << "Case #" << k << ": " << hgh1 << " " << hgh2 << endl;
        }
    }
}