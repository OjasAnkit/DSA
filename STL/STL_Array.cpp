#include <iostream>
#include <array>
using namespace std;

int main()
{
    array<int, 5> a = {1, 2, 3, 4}; // this is basically implemented through a fixed size static array.
    // int a[5] = {1, 2, 3, 4};

    int size = a.size();

    for (int i = 0; i < 5; i++)
    {
        // cout << a[i] << " ";
    }

    cout << "Element at 3 index: " << a.at(3) << endl;
    cout << "Empty or not? " << a.empty() << endl;

    // output the front element and the back element
    cout << a.front()<<endl;
    cout << a.back();
}