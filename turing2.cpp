#include <iostream>
#include <string>
using namespace std;

string incrementTM(string s)
{
    s = "_" + s;
    int i = s.size() - 1;
    while (i >= 0)
    {
        if (s[i] == '0')
        {
            s[i] = '1';
            break;
        }
        else if (s[i] == '1')
        {
            s[i] = '0';
            i--;
        }
        else
        {
            break;
        }
    }
    if (i < 0)
        s = "1" + s.substr(1);
    if (s[0] == '_')
        s = s.substr(1);
    return s;
}
int main()
{
    string s;
    cout << "Enter binary number: ";
    cin >> s;
    cout << "Incremented output: " << incrementTM(s);
    return 0;
}
