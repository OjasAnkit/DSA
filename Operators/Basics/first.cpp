#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
    unsigned int a, i;
    cin >> a;

    int digits = 0;

        for (i = a; i != 0; (i = i >> 1))
    {
        cout << i << endl;
        cout << "Inside";
        if (i & 1 == 1)
            digits++;

        //   i = i >> 1;
    }

    cout << "Hamming Weight value is: " << digits << endl;

    return 0;
}
