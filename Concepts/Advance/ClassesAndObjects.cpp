#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Node
{
public:
    int val;
    float f;
    string s;
    Node *next; // * is used to create a pointer in C++, we are basically creating a variable that will hold the address to another object of the "Node" class

    Node()
    {
        cout << "Inside default constructor:" << endl;
        val = -1;
        f = -1;
    }

    Node(int a, float b)
    {
        cout << "Inside constructor 2:" << endl;
        val = a;
        f = b;
    }

    Node(int a, float b, string str)
    {
        cout << "Inside constructor 1:" << endl;
        val = a;
        f = b;
        s = str;
    }
};

int main()
{

    int temp;
    cin >> temp;
    Node n1(temp, 5);
    cout << n1.val << endl;
    cout << n1.f << endl;
    cout << n1.s << endl;
    return 0;
}
