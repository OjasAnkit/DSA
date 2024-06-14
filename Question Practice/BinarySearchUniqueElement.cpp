#include <iostream>
#include <vector>
using namespace std;

int findUnique(vector<int> v)
{
    int low = 0, high = v.size() - 1;
    int mid = low + (high - low) / 2;

    while (low <= high)
    {
        if ((v[mid] != v[mid + 1]) && (v[mid] != v[mid - 1]))
            return v[mid];
        else
        {
            if (v[mid] == v[mid + 1])
            {
                if ((high - (mid + 2) + 1) % 2 == 0)
                {
                    high = mid - 1;
                }
                else
                    low = mid + 2;
            }
            else
            {
                if (((mid - 2) - low + 1) % 2 == 0)
                {
                    low = mid + 1;
                }
                else
                    high = mid - 2;
            }
        }
        mid = low + (high - low) / 2;
    }
}

int findUniqueAlt(vector<int> v)
{
    int low = 0, high = v.size() - 1;
    int mid = low + (high - low) / 2;

    while (low <= high)
    {
        if ((v[mid] != v[mid + 1]) && (v[mid] != v[mid - 1]))
            return v[mid];
        else if (v[mid] == v[mid + 1]) // checking if it is the first occurence of the number. If it is and the index is even, then we can remove the low till mid - 1 part, and can move our low to mid + 2. If the index of first occurence is odd we move our high to mid - 1
        {
            if (mid % 2 == 0)
                low = mid + 2;
            else
                high = mid - 1;
        }
        else // in case it is the 2nd occurence, we do the same checks with mid - 1 index and make the necessary changes in a similar way
        {
            if ((mid - 1) % 2 == 0)
                low = mid + 1;
            else
                high = mid - 2;
        }
        mid = low + (high - low) / 2;
    }
}

int main()
{
    vector<int> v = {9, 9, 32, 32, 3, 5, 5, 6, 6, 7, 7, 9, 9, 11, 11, 14, 14, -1, -1, 55, 55};
    cout << "Unique int: " << findUnique(v) << endl;
    cout << "Unique int Alt: " << findUniqueAlt(v);
}