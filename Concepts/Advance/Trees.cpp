#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;

    Node(int i)
    {
        val = i;
        left = nullptr;
        right = nullptr;
    }
};

void traversal(Node n)
{
}

void assignRight(Node n, Node right)
{
    n.right = right;
}

void assignLeft(Node n, Node left)
{
}

int main()
{
    Node n1(14);
    Node n2(19);
    Node n3(8);
    Node n4(4);
    Node n5(15);
    Node n6(18);
    Node n7(7);
    Node n8(3);
    Node n9(10);

    n1->left = n6;
    n1->right = n2;

    return 0;
}

// 7, 10, 3, 18, 4, 15, 8, 19, 14