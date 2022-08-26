#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int prodArray(vector<ll> v, ll index)
{
    if (index == v.size())
        return 1;
    else
        return v[index] * prodArray(v, index + 1);
}

int main()
{
    vector<ll> v;
    ll x;
    cin >> x;
    while (x--)
    {
        ll y;
        cin >> y;
        v.push_back(y);
    }
    cout << prodArray(v, 0) << endl;
}