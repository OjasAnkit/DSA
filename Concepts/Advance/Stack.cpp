#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

string removeAnyTwoAdjacent(string v)
{
    stack<char> s;

    for (int i = 0; i < v.size(); i++)
    {
        if (s.empty())
            s.push(v[i]);
        else
        {
            char ch = s.top();
            if (ch == v[i])
                s.pop();
            else
                s.push(v[i]);
        }
    }

    string ans(s.size(), 'a'); // defining answer string

    int index = s.size() - 1;

    while (!s.empty())
    {
        ans[index] = s.top();
        s.pop();
        index--;
    }

    return ans;
}

bool isBalancedString(string s)
{
    stack<char> st;

    for (int i = 0; i < s.length(); i++)
    {
        // checking for opening braces and pushing in stack
        if ((s[i] == '{') || (s[i] == '(') || (s[i] == '['))
        {
            // cout << s[i] << endl;
            st.push(s[i]);
        }
        else
        {
            // edge case where if the first char is closing return false
            if (st.empty())
                return false;
            else
            {
                char ch = st.top();
                if (ch == '[')
                    ch = ']';
                else if (ch == '{')
                    ch = '}';
                else if (ch == '(')
                    ch = ')';
                else
                    return false;
                // cout << s[i] << endl;
                if (ch == s[i])
                    st.pop();
                else
                    return false;
            }
        }
    }

    if (st.empty())
        return true;

    return false;
}

int main()
{
    string v = "aannnccbbbds";
    string ans = removeAnyTwoAdjacent(v);

    cout << ans;
    // string s = "[]{(({}))}[]()";
    // string s = ")[()[]{}]{}";
    // cout << isBalancedString(s);

    return 0;
}

//     The functions associated with stack are:
// empty() – Returns whether the stack is empty – Time Complexity : O(1)
// size() – Returns the size of the stack – Time Complexity : O(1)
// top() – Returns a reference to the top most element of the stack – Time Complexity : O(1)
// push(g) – Adds the element ‘g’ at the top of the stack – Time Complexity : O(1)
// pop() – Deletes the most recent entered element of the stack – Time Complexity : O(1)

// Practical examples of stack:
// 1. Undo redo: Undo redo operations are performed using stack, undo -> removes top most element. Redo -> adds the operation back to stack
// 2. Moving forward / backward in a browser page -> implemented through stack, going backward -> pop going forward -> push

// Adapters - one data structure implementes using some other ds, e.g., linked list as stack, linked list as queue etc.
// 1. LinkedList as stack: for LL to be a stack we have to implement LIFO. To perform this simply add the elements from the beginning and remove them from beginning as well. Both will be O(1) if done from beginning, if you add and remove from last both will be O(n) instead.