#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool pda(string s)
{
    stack<char> st;
    st.push('Z');
    bool seenX = false;
    for (int i = 0; i < (int)s.length(); ++i)
    {
        char c = s[i];
        if (!seenX)
        {
            if (c == 'a' || c == 'b')
            {
                st.push(c);
            }
            else if (c == 'X')
            {
                seenX = true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            if (c == 'a' || c == 'b')
            {
                if (st.top() == 'Z')
                    return false;
                if (st.top() != c)
                    return false;
                st.pop();
            }
            else
            {
                return false;
            }
        }
    }
    return (seenX && st.top() == 'Z');
}
int main()
{
    string s;
    cout << "Enter input: ";
    cin >> s;
    if (pda(s))
        cout << "Accepted\n";
    else
        cout << "Rejected\n";
    return 0;
}
