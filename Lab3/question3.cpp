#include <iostream>
using namespace std;

int **arr;
int row;
int col;
int **xarr;
int **sarr;
class question3
{
public:
    int getRow(int row);
    int getCol(int col);
    void printarray(int row, int col);
    int **scaleby(int row, int col, int value);
    int **getarray(int row, int col);
    int getItem(int row, int col, int i1, int i2);
    int **setitem(int row, int col, int i1, int i2, int value);
    int **transposeMat(int row, int col);
    void clear();
    void transpose();
    void mul(int **sarr);
    void add(int **sarr);
    int **creatematrix();
    void sub(int **sarr);
};

int question3::getRow(int row)
{
    int roww = row;
    return roww;
}

int question3::getCol(int col)
{
    int coll = col;
    return coll;
}

int **question3::getarray(int row, int col)
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
    cout << endl;
    return arr;
}

void question3::printarray(int row, int col)
{
    int size = 0;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            if (arr[i][j] != 0)
                size++;

    int compactMatrix[3][size];
    int k = 0;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            if (arr[i][j] != 0)
            {
                compactMatrix[0][k] = i;
                compactMatrix[1][k] = j;
                compactMatrix[2][k] = arr[i][j];
                k++;
            }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < size; j++)
            cout << compactMatrix[i][j] << " ";

        cout << endl;
    }
    cout << endl;
}

int **question3::scaleby(int row, int col, int value)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] != 0)
            {
                arr[i][j] = value * arr[i][j];
            }
        }
    }
    return arr;
}

int **question3::setitem(int row, int col, int i1, int i2, int value)
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

void question3::clear()
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            arr[i][j] = 0;
        }
    }
}

void question3::transpose()
{
    int **tarr = new int *[col];
    for (int i = 0; i < col; i++)
    {
        tarr[i] = new int[row];
    }

    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            tarr[i][j] = 0;
        }
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            tarr[j][i] = arr[i][j];
        }
    }
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            cout << tarr[i][j] << " ";
        }
        cout << endl;
    }
}

void question3::add(int **sarr)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            xarr[i][j] = sarr[i][j] + arr[i][j];
        }
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << xarr[i][j] << " ";
        }
        cout << endl;
    }
}
int **question3::creatematrix()
{
    sarr = new int *[row];
    for (int i = 0; i < row; i++)
    {
        sarr[i] = new int[col];
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> sarr[i][j];
        }
    }
    return sarr;
}
void question3::sub(int **sarr)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            xarr[i][j] = arr[i][j] - sarr[i][j];
        }
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << xarr[i][j] << " ";
        }
        cout << endl;
    }
}
void question3::mul(int **sarr)
{
    int k = 0;
    for (int i = 0; i < row; i++)
    {

        for (int j = 0; j < col; j++)
        {
            for (int k = 0; k < col; k++)
            {
                xarr[i][j] += arr[i][k] * sarr[k][j];
            }
        }
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << xarr[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    cin >> row;
    cin >> col;
    question3 myobj;
    arr = myobj.getarray(row, col);
    // myobj.printarray(row, col);
    // int r =  myobj.getRow(row);
    // cout << r << endl;
    // int c =  myobj.getCol(col);
    // cout << c << endl;
    // arr =  myobj.scaleby(row,col,3);
    // // myobj.printarray(row, col);
    // // arr = myobj.setitem(row, col, 1, 1, 3);
    myobj.transpose();
    // myobj.printarray(row, col);
    return 0;
}