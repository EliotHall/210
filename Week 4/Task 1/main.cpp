#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cout << "Numbers available are: ";

    vector <int> numbers;
    int a[] = {1,4,8,13,14,22,39,41,49,50};
    for (int i = 0; i < 10; i ++)
    {
        cout << a[i] << " ";
        numbers.push_back (a[i]);
    }
    cout << endl;

    int lower = 0;
    int higher = numbers.size();
    int position = (lower + higher) / 2;
    int key = 0;
    int key2 = 0;

    cout << "What numbers are you searching between?" << endl << endl;
    cout << "--Please put in two numbers to search between--" << endl;
    cin >> key;
    cin >> key2;

    if (numbers.empty())
    {
        cout << "There are no numbers to search" << endl;
        return 0;
    }
    else
    {
        //Making sure the number in the vector is not one of the keys
        //And not between the two keys.
        while (numbers[position] != key && numbers[position] != key2
        && (numbers[position] < key || numbers[position] > key2)
        && lower <= higher)
        {
            //If it's less than the number you are looking for...
            if (numbers[position] < key)
            {
                //Raise the lowest possible number it could be.
                lower = position + 1;
            }
            else
            {
                //Lower the highest possible number it could be.
                higher = position - 1;
            }
            position = (lower + higher) / 2;
        }
        //If the loop hasn't gone all the way without finding any numbers...
        if (lower <= higher)
        {
            cout << "A number was found. Position: " << position + 1 << endl;
        }
        else
        {
            cout << "A number was not found." << endl;
        }
    }

}

