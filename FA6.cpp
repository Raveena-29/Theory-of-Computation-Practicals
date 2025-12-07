#include <iostream>
using namespace std;

bool L1_accepts(string w)
{
    if (w.length() == 0)
    {
        return false;
    }

    return w[w.length() - 1] == 'a';
}

bool L2_accepts(string w)
{
    if (w.length() == 0)
    {
        return false;
    }

    return w[w.length() - 1] == 'b';
}

bool unionFA(string w)
{
    return L1_accepts(w) || L2_accepts(w);
}

bool intersectionFA(string w)
{
    return L1_accepts(w) && L2_accepts(w);
}

bool concatFA(string w)
{
    for (int i = 0; i <= w.length(); i++)
    {
        string x = w.substr(0, i);
        string y = w.substr(i);
        if (L1_accepts(x) && L2_accepts(y))
            return true;
    }
    return false;
}
int main()
{
    string w;
    cout << "ENTER STRING : ";
    cin >> w;

    cout << "\nL1 accepts? " << (L1_accepts(w) ? "YES" : "NO") << endl;
    cout << "L2 accepts? " << (L2_accepts(w) ? "YES" : "NO") << endl;
    cout << "\nUnion: " << (unionFA(w) ? "ACCEPTED" : "REJECTED") << endl;
    cout << "Intersection: " << (intersectionFA(w) ? "ACCEPTED" : "REJECTED") << endl;
    cout << "Concatenation L1L2: " << (concatFA(w) ? "ACCEPTED" : "REJECTED") << endl;

    return 0;
}