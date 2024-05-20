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
        count += checkForOverlappingA(v, start +);

    if (start + 1 < v.size() - 3)

        return count;
}

int main()
{
    vector<char> v = {'a', 'a', 'a', 'a', 'a', 'a', 'a'};

    cout << "Number of overlapping aaa in vector is : " << checkForOverlappingA(v, 0) << endl;

    cout << "Number of non-overlapping aaa in vector is : " << checkForA(v, 0) << endl;

    return 0;
}