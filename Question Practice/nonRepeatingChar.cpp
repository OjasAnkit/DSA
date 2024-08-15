#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;
string FirstNonRepeatingNotWorking(string A)
{
    // Code here
    unordered_map<char, int> hm;
    queue<char> q;
    string ans;
    char lastUnique;

    if (A.size() == 1)
        return A;
    /*
        aabbbdeefghdiijj
        a#b##ddddddfffff
    */
    else
    {
        ans = A.at(0);
        hm[A.at(0)] = 1;
        lastUnique = A.at(0);
        q.push(lastUnique);
    }

    for (int i = 1; i < A.size(); i++)
    {
        // read each char
        char ele = A.at(i);

        // ele not in hash map
        if (hm.find(ele) == hm.end())
        {
            hm[ele] = 1;
            q.push(ele);

            if (lastUnique == '#')
            {
                ans += ele;
                lastUnique = ele;
            }

            else
                ans += lastUnique;
        }

        // ele in hash map
        else
        {
            hm[ele]++;

            if (lastUnique == '#')
                ans += '#';

            else if (lastUnique == ele)
            {
                if (!q.empty())
                {
                    q.pop();

                    if (!q.empty())
                    {
                        char newUnique = q.front();

                        if (hm[newUnique] == 1)
                        {
                            ans += newUnique;
                            lastUnique = newUnique;
                        }

                        else
                        {
                            while (hm[q.front()] != 1 && !q.empty())
                                q.pop();

                            if (q.empty())
                            {
                                ans += '#';
                                lastUnique = '#';
                            }

                            else
                            {
                                ans += q.front();
                                lastUnique = q.front();
                            }
                        }
                    }

                    else
                    {
                        ans += '#';
                        lastUnique = '#';
                    }
                }

                else
                {
                    ans += '#';
                    lastUnique = '#';
                }
            }

            else
                ans += lastUnique;
        }
    }

    return ans;
}

string FirstNonRepeating(string A)

{
    // Code here
    unordered_map<char, int> hm;
    queue<char> q;
    string ans;

    for (int i = 0; i < A.size(); i++)
    {
        // read each char
        char ele = A.at(i);

        q.push(ele);
        // ele not in hash map
        if (hm.find(ele) == hm.end())
        {
            hm[ele] = 1;
        }

        // ele in hash map
        else
        {
            hm[ele]++;
        }

        // getting element appearing only once
        while (!q.empty() && hm[q.front()] != 1)
        {
            q.pop();
        }

        if (!q.empty())
            ans += q.front();
        else
            ans += '#';
    }

    return ans;
}
int main()
{
    string g = "mxnwcngncfwinfrnngoaecedfzdvmdbronyaexqytvqaezppeqnffetizrpfwssmulhlzvrkddwhlwwiwqkdqwisaznvymgbpzxifrysiqmaammogfludhiobpmdstopvddbafjqhxawujkscqjxxlqeoeqpqzeiedhvrtlrgijqybpiritpcqylhavoasaqzuiof";

    cout << FirstNonRepeating(g);

    return 0;
}
