#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    string s1 = "argaju", s2 = "RAJ";
    size_t count = 0;

    for (char &c : s1)
    {
        c = toupper(c);
    }

    for (char &c : s2)
    {
        c = toupper(c);
    }

    for (size_t i = 0; i < s2.size(); i++)
    {
        bool found = false;
        for (size_t j = 0; j < s1.size(); j++)
        {
            if (s2[i] == s1[j])
            {
                found = true;
                break;
            }
        }
        if (found)
        {
            count++;
        }
    }

    if (count == s2.size())
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }

    return 0;
}
