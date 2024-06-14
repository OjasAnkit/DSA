#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int goodIntegers(vector<int> a)
{
    int count = 0;
    std::sort(a.begin(), a.end());
    int lastGoodInteger = a[0] - 1;

    if (a[0] == 0) // edge case, if the 1st element is 0, then it automatically a good integer
        count++;

    for (int i = 1; i < a.size(); i++)
    {
        if (a[i] != a[i - 1]) // checking for first occurence of an element
        {
            if (a[i] == i) // if it is the first occurence, then checking if a[i] has i elements that are smaller than itself. If yes -> good integer
            {
                cout << a[i];
                count++;
                lastGoodInteger = a[i];
            }
        }
        else
        { // if element is not the first occurence, then simply check if the first occurence of that element was a good integer or not, since all the occurences of an element will either be all good or all not good
            if (a[i] == lastGoodInteger)
            {
                cout << a[i];
                count++;
            }
        }
    }
    return count;
}

int main()
{
    vector<int> v = {-4, -4, 2, 2, 5, 5, 5, 5, 8, 8, 8, 10, 17};
    cout << "Good integers count : " << goodIntegers(v);

    return 0;
}