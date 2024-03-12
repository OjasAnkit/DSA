#include <iostream>

using namespace std;

void printArray(int a[][4], int row, int column)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void largestRowSum(int a[][4], int row, int column)
{
    int sum = 0, maxiSum = INT_MIN, rowNum = -1;

    for (int i = 0; i < row; i++)
    {
        sum = 0;

        for (int j = 0; j < column; j++)
        {
            sum += a[i][j];
        }

        if (sum >= maxiSum)
        {
            maxiSum = sum;
            rowNum = i + 1;
        }
    }

    cout << "Largest Row Sum is : " << sum << " at the Row Number : " << rowNum;
}

void columnSum(int a[3][4], int row, int column)
{
    int sum = 0;

    for (int i = 0; i < 4; i++)
    {
        sum = 0;

        for (int j = 0; j < 3; j++)
        {
            sum += a[j][i];
        }

        cout << "Sum of Column " << i + 1 << " is: " << sum << endl;
    }
}

int main()
{

    int a[3][4];

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 4; j++)
        {
            cin >> a[i][j];
        }

    printArray(a, 3, 4);
    largestRowSum(a, 3, 4);

    return 0;
}