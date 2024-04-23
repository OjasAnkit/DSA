#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
    int t, n;
    cin >> t;
    while (t > 0)
    {
        cin >> n;

        int a = 1,
            b = 1, c = 1;

        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                a = i;
                break;
            }
        }

        for (int i = a + 1; i * i <= n; i++)
        {
            if (n % (a * i) == 0)
            {
                b = i;
                break;
            }
        }

        // checking if there will be a int value for c = n / (b * a)
        if (n % (b * a) == 0)
            c = n / (b * a);

        if (a != b && a != c && b != c && a != 1 && b != 1 && c != 1)
        {
            cout << "YES" << endl;
            cout << a << " " << b << " " << c << endl;
        }

        else
            cout << "NO" << endl;

        t--;
    }

    return 0;
}
