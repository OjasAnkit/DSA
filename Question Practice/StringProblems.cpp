#include <iostream>
#include <string>
#include <vector>

using namespace std;

string replaceSpaces(string &str, string &part)
{

    int len = str.length();

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
            str.erase(i, 1);
            str.insert(i, part);
            cout << "IN\n";
        }
    }

    return str;
}

vector<int> characterMapping(string s1)
{
    vector<int> charCount(26, 0);

    for (int i = 0; i < s1.length(); i++)
    {
        int indexToIncrease = s1[i] - 'a';
        charCount[indexToIncrease]++;
    }

    return charCount;
}

bool checkInclusion(string s1, string s2)
{
    vector<int> charMapping_s1 = characterMapping(s1);
    // cout << s1 << " " << s2;
    cout << s2.length();
    cout << s1.length();

    int len = s2.length() - s1.length();

    cout << len;
    for (int i = 0; i <= s2.length() - s1.length(); i++)
    {
        // cout << "Hello : " << i;
        string window = s2.substr(i, s1.length());
        vector<int> charMapping_window = characterMapping(window);

        if (charMapping_window == charMapping_s1)
            return true;
    }
    return false;
}

int main()
{
    // input : Hi my name is Ojas Ankit
    // que 1 : Ankit Ojas is name my Hi
    // que 2 : iH ym emane si sajO tiknA -> in place reversal of each word without using extra space
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    cout << checkInclusion(s1, s2);

    return 0;
}

// ansiadbiendfdsassadd
// dasasd