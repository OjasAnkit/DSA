#include <iostream>
#include <vector>

using namespace std;

int calPower(int a, int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return a;

    int temp = calPower(a, n - 1);
    return temp * a;
}

int checkForOverlappingA(vector<char> v, int start)
{
    int count = 0;

    if ((start + 2) > v.size() - 1)
    {
        return 0;
    }

    if (v[start + 1] == 'a' && v[start + 2] == 'a')
    {
        if (v[start] == 'a')
            count++;
    }

    if (start < v.size() - 3)
        count += checkForOverlappingA(v, start + 1);
    return count;
}

int aaa_alt_non_overlapping(vector<char> v, int start)
{
    // base case
    if (start >= v.size() - 2)
        return 0;

    // faith
    // temp = aaa_alt(v, start + 1);
    // cout << temp << endl;

    // smaller problem
    if (v[start] == 'a' && v[start + 1] == 'a' && v[start + 2] == 'a')
    {
        int temp = aaa_alt_non_overlapping(v, start + 3);
        return ++temp;
    }
    else
        return aaa_alt_non_overlapping(v, start + 1);
    ;
}

int checkForA(vector<char> v, int start)
{
    int count = 0;

    if ((start + 2) > v.size() - 1)
    {
        cout << "return 0 for start: " << start << endl;
        return 0;
    }

    if (v[start + 1] == 'a' && v[start + 2] == 'a')
    {
        if (v[start] == 'a')
        {
            count++;
        }
    }
    else
        // count += checkForOverlappingA(v, start +);

        if (start + 1 < v.size() - 3)

            return count;
}

bool checkSort(vector<int> v, int start)
{
    if (start >= v.size() - 2)
        return (v[start] <= v[start + 1]);
    if (checkSort(v, start + 1))
        return (v[start] <= v[start + 1]);
    else
        return false;
}

int firstIndex(vector<int> v, int k, int start)
{
    if (start == v.size() - 1)
    {
        if (v[start] == k)
            return start;
        else
            return -1;
    }

    int temp = firstIndex(v, k, start + 1);

    if (v[start] == k)
        return start;
    else
        return temp;
}

int main()
{
    vector<char> v = {'a', 'a', 'b', 'a', 'a', 'a', 'c', 'c', 'a', 'a', 'a', 'b', 'c', 'a', 'a'};
    vector<int> v1 = {1, 0, 7, 8, 9, 4, 5, 6, 7, 7, 7, 8, 19};
    int k = 19;
    // cout << "Number of overlapping aaa in vector is : " << aaa_alt_non_overlapping(v, 0)<<endl;

    cout << "First Index of " << k << " is: " << firstIndex(v1, k, 0);

    // cout << "Number of non-overlapping aaa in vector is : " << checkForA(v, 0) << endl;

    return 0;
}