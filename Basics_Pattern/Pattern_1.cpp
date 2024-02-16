#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int n, j = 1;

    // n = cin.get();

    int spaces = 1;
    int count = 1;

    cin >> n;

    for (int i = 1; i <= n; i++)
    {

        spaces = n - i;

        while (spaces >= 1)
        {
            cout << "  ";
            spaces--;
        }

        j = 1;

        int second_j = i - 1;

        while (j <= i)
        {
            cout << j << " ";
            j++;
        }

        while (second_j >= 1)
        {
            cout << second_j << " ";
            second_j--;
        }

        cout << endl;
    }

    return 0;
}