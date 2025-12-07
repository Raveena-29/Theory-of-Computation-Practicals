#include <iostream>
using namespace std;
void state1(string w, int i);
void state2(string w, int i);
void state3(string w, int i);
void state4(string w, int i);

void state1(string w, int i)
{
    cout << "state state1" << endl;
    if (i == w.length())
    {
        cout << "string accepted" << endl;
        return;
    }
    if (w[i] == 'a')
        state2(w, i + 1);
    else
        state4(w, i + 1);
}
void state2(string w, int i)
{
    if (i == w.length())
    {
        cout << "string rejected" << endl;
        return;
    }
    cout << "state state2" << endl;
    if (w[i] == 'a')
        state1(w, i + 1);
    else
        state3(w, i + 1);
}
void state3(string w, int i)
{
    if (i == w.length())
    {
        cout << "string rejected" << endl;
        return;
    }
    cout << "state state3" << endl;
    if (w[i] == 'a')
        state4(w, i + 1);
    else
        state2(w, i + 1);
}
void state4(string w, int i)
{
    if (i == w.length())
    {
        cout << "string rejected" << endl;
        return;
    }
    cout << "state state4" << endl;
    if (w[i] == 'a')
        state3(w, i + 1);
    else
        state1(w, i + 1);
}
int main()
{
    string w;
    cout << "Enter string : ";
    cin >> w;
    state1(w, 0);
}
