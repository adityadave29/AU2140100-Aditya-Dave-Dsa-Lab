#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int addup(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    return n + addup(n - 1);
}

int main()
{
    int n;
    cin >> n;
    cout << addup(n) << endl;
    return 0;
}