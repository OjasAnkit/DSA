#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void binarySearch(int arr[], int size, int key)
{
    int start = 0, mid, end = size - 1;

    while (start <= end)
    {
        mid = (start + end) / 2;

        if (arr[mid] == key)
        {
            cout << endl;
            cout << "Key Found at Index : " << mid;
            return;
        }

        else if (arr[mid] < key)
        {
            start = mid + 1;
        }

        else
        {
            end = mid - 1;
        }
    }

    cout << endl;
    cout << "Key not found!!";
    return;
}

int lastOccurence(int arr[], int n, int k)
{
    int first = -1, last = -1;
    int start = 0, end = n - 1;

    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        if (arr[mid] == k)
        {
            last = mid;
            start = mid + 1;
        }

        else if (arr[mid] > k)
        {
            end = mid - 1;
        }

        else
        {
            start = mid + 1;
        }

        mid = start + (end - start) / 2;
    }
    return last;
}

int firstOccurence(int arr[], int n, int k)
{
    int first = -1, last = -1;
    int start = 0, end = n - 1;

    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        if (arr[mid] == k)
        {
            first = mid;
            end = mid - 1;
        }

        else if (arr[mid] > k)
        {
            end = mid - 1;
        }

        else
        {
            start = mid + 1;
        }

        mid = start + (end - start) / 2;
    }

    return first;
}

int peakIndexInMountainArray(int arr[], int n)
{
    int start = 0, end = n - 1, flag = 1;
    int mid = start + (end - start) / 2;

    while (flag != 0)
    {
        int max = arr[mid];
        // cout << mid << max << endl;

        if (max > arr[mid + 1] && max > arr[mid - 1])
        {
            int ans = mid;
            // cout << ans;
            flag = 0;
            return ans;
        }

        else if (max > arr[mid + 1] && max < arr[mid - 1])
        {
            end = mid - 1;
        }

        else if (max < arr[mid + 1] && max > arr[mid - 1])
        {
            start = mid + 1;
        }

        mid = start + (end - start) / 2;

        if (mid == 0)
        {
            mid = 1;
        }

        else if (mid == n - 1)
        {
            mid = n - 2;
        }
    }

    return -1;
}

int main()
{
    int a[15] = {1, 3, 4, 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 8};
    int b[8] = {1, 3, 4, 6, 7, 8, 4, 3};

    // binarySearch(a, 15, 7);

    /// cout << "First Occurence: " << firstOccurence(a, 15, 7);
    cout << endl;
    // cout << "Last Occurence: " << lastOccurence(a, 15, 7);

    cout << " Mountain Index is : " << peakIndexInMountainArray(b, 8);

    return 0;
}