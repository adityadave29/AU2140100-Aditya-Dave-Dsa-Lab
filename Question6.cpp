#include <iostream>
using namespace std;

int Findgcd(int x, int y)
{
    if (y == 0)
        return x;
    else
        return Findgcd(y, x % y);
}

int main()
{
    int num1, num2, hcf;
    cin >> num1 >> num2;
    hcf = Findgcd(num1, num2);
    cout << hcf;
    return 0;
}