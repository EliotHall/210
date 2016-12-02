#include <iostream>

using namespace std;

int main()
{
    int a[2][2];
    int temp[2][2];
    int temp2[2][2];
    int b[2][2] = {{1,2},{3,4}};
    int c[2][2] = {{5,6},{7,8}};

    for (int i=0; i<2; i++)
    {
        for (int j = 0; j<2; j++)
        {
            //Remember to set the array you are putting the output into
            //to 0, otherwise, bad stuff will happen!! O.O
            a[i][j] = 0;
            temp[i][j] = 0;
            temp2[i][j] = 0;
            for (int k = 0; k<2; k++)
            {
                temp[i][j] += b[i][k] * c[k][j];
            }
        }
    }

    for (int i = 0; i<2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            temp2[i][j] = b[i][j] + c[i][j];
        }
    }

    for (int i = 0; i<2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            temp2[i][j] = temp2[i][j] * 2;
        }
    }

    for (int i = 0; i<2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            a[i][j] = temp[i][j] - temp2[i][j];
        }
    }
    //Just to print the output array
    for (int i=0; i<2; i++)
    {
        for (int j=0; j<2; j++)
        {
            cout << " " << a[i][j];
            if (j == 1)
                cout << endl;
        }
    }
    return 0;
}
