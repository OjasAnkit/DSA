#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
    int n;

    cin >> n;

    if (n <= 0)
        cout << "false" << endl;

    else if (n == 1)
        cout << "true" << endl;

    int check;
    int numberOf1bits = 0;

    for (int i = n; i != 0; i = i >> 1)
    {
        check = i & 0;
        cout << check << endl;
        if (check != i)
        {
            numberOf1bits++;
        }
        // cout<< numberOf1bits;
    }
    if (numberOf1bits == 1)
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}
