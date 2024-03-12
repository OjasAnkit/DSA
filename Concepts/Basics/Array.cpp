#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::swap;

void MinMaxOfArray(int a[], int size)
{
    int min = a[0], max = a[0];
    for (int i = 0; i < size; i++)
    {
        if (min > a[i])
        {
            min = a[i];
        }

        if (max < a[i])
        {
            max = a[i];
        }
    }
    cout << endl;
    cout << "Max of Array is : " << max << endl;
    cout << "Min of Array is : " << min << endl;
}

void printArray(int arr[], int size)
{
    cout << endl;
    cout << "Printing Start" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Printing End";
}

void inputArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
}

void sumArray(int arr[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    cout << "Sum of all the elements in the Array is :" << sum;
}

void reverseArray(int arr[], int size)
{
    int endIndex = size - 1;

    for (int startIndex = 0; startIndex < endIndex; startIndex++, endIndex--)
    {
        swap(arr[startIndex], arr[endIndex]);
    }
    printArray(arr, size);
}

void swapAltArray(int arr[], int size)
{
    for (int startIndex = 0; startIndex < size - 1; startIndex += 2)
    {
        swap(arr[startIndex], arr[startIndex + 1]);
    }
    printArray(arr, size);
}

int findUnique(int *arr, int size)
{
    int occurence;
    for (int i = 0; i < size; i++)
    {
        occurence = 0;
        int initialVal = arr[i];
        for (int j = 0; j < size; j++)
        {
            if (arr[j] == initialVal)
            {
                occurence++;
            }
            cout << occurence << endl;
        }
        if (occurence == 1)
            return arr[i];
    }
}

int main()
{
    int size;
    cin >> size;

    int a[1000];

    inputArray(a, size);
    // printArray(a, size);
    // MinMaxOfArray(a, size);
    // sumArray(a, size);
    // reverseArray(a, size);
    // swapAltArray(a, size);
    int unique = findUnique(a, size);
    cout << unique;
    return 0;
}