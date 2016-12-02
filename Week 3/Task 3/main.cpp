#include <iostream>
#include <string>

using namespace std;

string remVowels(string s, int k);

int main()
{
    string s;
    cin >> s;
    int k = 0;
    cout << remVowels(s,k);
}

string remVowels(string s, int k)
{
    char n = s[k]; // k is what will call specific letters
                   // while n compares them to vowels

    if (s.size() != 0 && k <= s.size() - 1) //As long as the string isn't empty
                                            //And we haven't reached the end of the string
    {
        if (n == 'a' || n == 'e' || n == 'i' || n == 'o' || n == 'u' ||
            n == 'A' || n == 'E' || n == 'I' || n == 'O' || n == 'U')
        {
            return remVowels(s,k+1);
        }
        else
        {
            return s[k] + remVowels(s,k+1);
        }
    }
    else
    {
        return "";
    }
}

