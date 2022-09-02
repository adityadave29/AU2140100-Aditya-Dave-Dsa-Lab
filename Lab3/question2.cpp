#include <iostream>
using namespace std;

int **arr;
int row;
int col;

class question2
{
public:
    int getRow(int row);
    int getCol(int col);
    void printArray(int row, int col);
    int **clearArray(int row, int col, int value);
    int **getArray(int row, int col);
    int getItem(int row, int col, int i1, int i2);
    int **setitem(int row, int col, int i1, int i2, int value);
};

int question2::getRow(int row)
{
    int roww = row;
    return roww;
}

int question2::getCol(int col)
{
    int coll = col;
    return coll;
}

int **question2::getArray(int row, int col)
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

void question2::printArray(int row, int col)
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

int **question2::clearArray(int row, int col, int value)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] != 0)
            {
                arr[i][j] = value;
            }
        }
    }
    return arr;
}

int **question2::setitem(int row, int col, int i1, int i2, int value)
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
    question2 myobj;
    arr = myobj.getArray(row, col);
    // myobj.printArray(row, col);
    // int r =  myobj.getRow(row);
    // cout << r << endl;
    // int c =  myobj.getCol(col);
    // cout << c << endl;
    // arr =  myobj.clearArray(row,col,3);
    // myobj.printArray(row, col);
    arr = myobj.setitem(row, col, 1, 1, 3);
    myobj.printArray(row, col);
    return 0;
}
