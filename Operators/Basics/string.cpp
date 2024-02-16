#include <iostream>

using namespace std;

void printName(char name[])
{
    for (int i = 0; name[i] != '\0'; i++)
        cout << name[i];
}

int getLength(char name[])
{
    int length;
    for (int i = 0; name[i] != '\0'; i++)
        length++;

    return length;
}

void reverseName(char name[])
{
    int length = getLength(name);
    int low = 0, high = length - 1;

    while (low < high)
    {
        char temp = name[low];
        name[low] = name[high];
        name[high] = temp;

        low++;
        high--;
    }

    printName(name);
}

int main()
{
    char name[20];
    cout << "Enter your name : ";
    cin >> name;

    reverseName(name);
    return 0;
}