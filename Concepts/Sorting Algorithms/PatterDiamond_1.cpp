#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void printUpperTriangle(int r, int c, int s)
{
    // printing upper triangle
    for (int j = 0; j < r; j++)
        for (int k = 0; k < c; k++)
        {
            for (int i = 0; i < s; i++)
            {
                for (int j = 0; j < 2 * s; j++)
                {
                    if (j == s - (i + 1))
                    {
                        cout << "/";
                    }

                    else if (j == s + i)
                    {
                        cout << "\\";
                    }

                    else
                    {
                        if (j >= s - i && j <= s + i)
                            cout << "o";

                        else
                            cout << "e";
                    }
                }
                cout << endl;
            }
        }
}
void printLowerTriangle(int r, int c, int s)
{
    // printing lower triangle
    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < 2 * s; j++)
        {
            if (j == i)
            {
                cout << "\\";
            }

            else if (j == (2 * s - (i + 1)))
            {
                cout << "/";
            }

            else
            {
                if (j >= (2 * s - (i + 1)) || j < i)
                    cout << "e";

                else
                    cout << "o";
            }
        }
        cout << endl;
    }
}

int main()
{

    int r, c, s;
    cin >> r >> c >> s;

    return 0;
}