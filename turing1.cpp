#include <iostream>
#include <string>
using namespace std;
bool simulateTM(string s)
{
    s = "_" + s + "_";
    int n = s.size();
    while (true)
    {
        int i = 0;
        while (i < n && s[i] != 'a')
            i++;
        if (i == n)
            break;
        s[i] = 'X';
        i++;
        while (i < n && s[i] != 'b')
        {
            if (s[i] == 'a')
                return false;
            i++;
        }
        if (i == n)
            return false;
        s[i] = 'Y';
        i++;
        while (i < n && s[i] != 'c')
        {
            if (s[i] == 'a' || s[i] == 'b')
                return false;
            i++;
        }
        if (i == n)
            return false;
        s[i] = 'Z';
    }
    for (char c : s)
    {
        if (c == 'a' || c == 'b' || c == 'c')
            return false;
    }
    return true;
}
int main()
{
    string s;
    cout << "Enter string: ";
    cin >> s;
    if (simulateTM(s))
        cout << "Accepted";
    else
        cout << "Rejected";
    return 0;
}
