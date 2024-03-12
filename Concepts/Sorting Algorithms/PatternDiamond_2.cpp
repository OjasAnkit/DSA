#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void printLowerTriangle(int r, int c, int s)
{
    for (int i = 0; i < s; i++)
    {
        int backslash = 0;
        int forwardslash = 2 * s - (i + 1);
        int o_flag, e_flag;
        for (int j = 0; j < 2 * s * c; j++)
        {
            if (j == backslash + i)
            {
                cout << "\\";
                backslash = backslash + 2 * s;
                e_flag = -1;
                o_flag = 1;
            }

            else if (j == forwardslash)
            {
                cout << "/";
                forwardslash = forwardslash + 2 * s;
                e_flag = 1;
                o_flag = -1;
            }

            else
            {
                if (o_flag == 1)
                    cout << "o";
                else
                    cout << "e";
            }
        }
        cout << endl;
    }
}

void printUpperTriangle(int r, int c, int s)
{

    for (int i = 0; i < s; i++)
    {
        int backslash = s;
        int forwardslash = s;
        int o_flag, e_flag;
        for (int j = 0; j < 2 * s * c; j++)
        {
            if (j == forwardslash - (i + 1))
            {
                cout << "/";
                forwardslash = forwardslash + 2 * s;
                o_flag = 1;
                e_flag = -1;
            }

            else if (j == backslash + i)
            {
                cout << "\\";
                backslash = backslash + 2 * s;
                o_flag = -1;
                e_flag = 1;
            }

            else
            {
                if (o_flag == 1)
                    cout << "o";
                else
                    cout << "e";
            }
        }
        cout << endl;
    }
    printLowerTriangle(r, c, s);
}

int main()
{

    int r, c, s;
    cin >> r >> c >> s;

    for (int i = 0; i < r; i++)
    {
        printUpperTriangle(r, c, s);
    }
    return 0;
}