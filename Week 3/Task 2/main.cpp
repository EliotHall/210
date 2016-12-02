#include <iostream>

using namespace std;

bool checkPrime(int i, int j);

int main()
{
    int i, j;
    cout << "Please enter a number to check if it is a prime number" << endl;
    cin >> i;
    //j is going to be every number below i
    //to check if i can divide with any other number
    j = i - 1;
    return checkPrime(i,j);
}

bool checkPrime(int i, int j)
{
    //Was going to do j != 1, but if you had i as 1 then j would be 0
    //And the code would loop forever...
    if (i <= 1)
    {
        cout << "It's not a prime number!" << endl;
        return false;
    }

    if (j == 1)
    {
        cout << "It's a prime number!" << endl;
        return true;
    }
    else
    {
        if (i % 2 == 0)
        {
            cout << "It's not a prime number!" << endl;
            return false;
        }

        //Checks if it can divide together
        if (i % j == 0)
        {
            cout << "It's not a prime number!" << endl;
            return false;
        }
        else
        {
            cout << "It doesn't divide with " << j << endl;
            cout << "Let's check if it divides with " << j-1 << endl;
            return checkPrime(i,j-1);
        }
    }
}
