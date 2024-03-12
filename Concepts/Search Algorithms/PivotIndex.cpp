#include <iostream>

using std::cin;
using std::cout;

int calcSum(int nums[], int n, int s, char ch)
{
    int sum = 0;
    if (ch == 'L')
    {
        for (int i = 0; i < s; i++)
        {
            sum += nums[i];
        }
    }

    else
    {
        for (int i = s + 1; i < n; i++)
        {
            sum += nums[i];
        }
    }

    return sum;
}

// int pivotSumIndex(int arr[], int size)
// {
//     int s = 0, e = size - 1;

//     while (s <= e)
//     {
//         int left_sum = calcSum(arr, size, s, 'L');
//         int right_sum = calcSum(arr, size, s, 'R');

//         if (left_sum == right_sum)
//             return arr[s];

//         else
//             s++;
//     }

//     return -1;
// }

int returnPivot(int arr[], int n)
{
    int s = 0, e = n - 1;
    int mid = s + (e - s) / 2;

    while (s < e)
    {
        if (arr[mid] >= arr[0])
        {
            s = mid + 1;
        }

        else
        {
            e = mid;
        }
        mid = s + (e - s) / 2;
    }

    if (s == n - 1)
        return 0;
    return s;
}

int searchRotated(int arr[], int n, int k)
{
    int s = 0, e = n - 1;
    int pivot = returnPivot(arr, n);

    if (k >= arr[0])
    {
        e = pivot - 1;
    }

    else
    {
        s = pivot;
    }

    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (k == arr[mid])
        {
            return mid;
        }

        else if (k > arr[mid])
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }

        mid = s + (e - s) / 2;
    }

    return -1;
}

int main()
{
    int b[6] = {1, 7, 3, 6, 5, 6};

    int pivot[9] = {
        8,
        9,
        1,
        2,
        3,
        4,
        5,
        6,
        7,
    };

    int test[12] = {
        1,
        2,
        3,
        4,
        5,
        6,
        7,
        8,
        9,
        10,
        11,
        12};

    cout << returnPivot(test, 12);
    // cout << "Pivot Index of array is : " << returnPivot(pivot, 9);
    // cout << "\n Key element found at index : " << searchRotated(pivot, 9, 7);
    return 0;
}