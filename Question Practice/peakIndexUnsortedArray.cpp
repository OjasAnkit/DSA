// find the peak element in the unsorted array in log n TC -> we have to use B.S
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int returnPeakIndex(vector<int> a)
{
    int len = a.size();

    // checking for edge cases
    if (len == 1)
        return 0;
    if (a[0] > a[1])
        return 0;
    if (a[len - 1] > a[len - 2])
        return len - 1;

    int start = 1;
    int end = len - 2;
    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        // mid is peak element
        if (a[mid] > a[mid - 1] && a[mid] > a[mid + 1])
            return mid;

        // variation 1: all decreasing -> go left
        else if (a[mid] < a[mid - 1] && a[mid] > a[mid + 1])
            end = mid - 1;

        // variation 2: all increasing -> go right
        else if (a[mid] > a[mid - 1] && a[mid] < a[mid + 1])
            start = mid + 1;

        // variation 3: reverse peak -> go either way
        else
            start = mid + 1;

        mid = start + (end - start) / 2;
    }

    return -1;
}

int main()
{
    vector<int> v = {1, 2, 1, 3, 5, 6, 4};
    cout << returnPeakIndex(v);
    return 0;
}
