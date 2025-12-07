#include <iostream>
#include <stack>
using namespace std;

bool pda(string w)
{
    stack<char> st;
    st.push('Z');
    int i = 0;
    while (i < w.length() && w[i] == 'a')
    {
        st.push('X');
        i++;
    }
    if (i == 0 || w[i] != 'b')
        return false;
    while (i < w.length() && w[i] == 'b')
    {
        if (st.top() != 'X')
            return false;
        st.pop();
        i++;
    }
    return (i == w.length() && st.top() == 'Z');
}

int main()
{
    string w;
    cout << "Enter string: ";
    cin >> w;
    if (pda(w))
        cout << "Accepted\n";
    else
        cout << "Rejected\n";
    return 0;
}