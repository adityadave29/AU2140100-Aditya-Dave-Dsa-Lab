#include <bits/stdc++.h>
using namespace std;

int** arr;  
int row;
int col;

class question1{
    public:
    int getRow(int row);
    int getCol(int col);
    void printArray(int row, int col);
    int **clearArray(int row, int col, int value);
    int **getArray(int row, int col);
    int getItem(int row, int col, int i1, int i2);
    int **setitem(int row, int col, int i1, int i2, int value);
};




int question1::getRow(int row)
{
    int roww = row;
    return roww;
}

int getCol(int col)
{
    int coll = col;
    return coll;
}

void question1:: printArray(int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int** question1::clearArray(int row, int col, int value)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            arr[i][j] = value;
        }
    }
    return arr;
}

int ** question1::getArray(int row, int col)
{
    int **arr = new int *[row];
    for (int i = 0; i < row; i++)
    {
        arr[i] = new int[col];
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
        }
    }
    return arr;
}

int  question1::getItem(int row, int col, int i1, int i2)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i == i1 - 1 && j == i2 - 1)
            {
                return arr[i][j];
                break;
            }
        }
    }
}

int ** question1::setitem(int row, int col, int i1, int i2, int value)
{
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            if (i == i1 && j == i2)
            {
                arr[i - 1][j - 1] = value;
                break;
            }
        }
    }
    return arr;
}

int main()
{
    cin >> row;
    cin >> col;
    question1 myobj;
    arr = myobj.getArray(row, col);
    // arr = myobj.getArray(row, col);
    cout << endl;
    // myobj.printArray(row, col);
    int c = myobj.getItem(row, col, 1, 1);
    cout << c << endl;
    // arr = myobj.setitem(row, col,1,1,2);
    // myobj.printArray(row, col);
    // int rowww = myobj.getRow(row);
    // int rowww = myobj.getCol(col);
    // cout << rowww << endl;
    // cout << rowww << endl;
    // arr = myobj.clearArray(row, col, 3);
    // myobj.printArray(row, col);
    return 0;
}