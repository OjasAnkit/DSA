#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countOfStudents(vector<int> &arr, int mid)
{
    int pagesHolding = 0;
    int numberOfStudents = 1;
    int i;

    for (i = 0; i < arr.size(); i++)
    {
        if (pagesHolding + arr[i] > mid)
        {
            numberOfStudents += 1;
            pagesHolding = arr[i];
        }
        else
        {
            pagesHolding += arr[i];
        }
    }

    return numberOfStudents;
}

int findPages(vector<int> &arr, int n, int m)
{
    int start = *max_element(arr.begin(), arr.end());
    int end = 0;
    int ans = -1, mid;

    for (int i = 0; i < n; i++)
    {
        end += arr[i];
    }

    if (m > n)
        return -1;

    while (start <= end)
    {
        mid = start + (end - start) / 2;

        int numberOfStudents = countOfStudents(arr, mid);

        if (numberOfStudents == m)
        {
            ans = mid;
            end = mid - 1;
        }
        else if (numberOfStudents > m)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return start;
}

int main()
{
    vector<int> arr = {8, 6, 10, 3, 2, 7, 10};
    int n = 7;
    int m = 7;

    int result = findPages(arr, n, m);
    cout << "Result: " << result << endl;

    return 0;
}
