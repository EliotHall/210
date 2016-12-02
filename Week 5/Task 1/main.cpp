#include <iostream>
#include <vector>

using namespace std;

int AccSubSequence(vector<int> sequence)
{
    int counter = 0;
    int subStart = 0;

    int bestLength = 0;
    int bestStart = 0;

    for (int i = 0; i < sequence.size() - 1; i++)
    {
        cout << "current element: " << sequence[i] << endl;
        cout << "   next element: " << sequence[i+1] << endl;
        counter ++;

        if (sequence[i+1] < sequence[i])
        {
            cout << "Reached the end of an ascending sequence" << endl;
            cout << "Sequence starts at element: " << subStart << endl;
            cout << "Size of sequence is: " << counter << endl;

            if (counter > bestLength)
            {
                bestLength = counter;
                bestStart = subStart;
            }

            counter = 0;
            subStart = i+1;
        }
        cout << endl;
    }
            //Could probably put this in a function...
            //Need to do it once more out of the loop to include that last element
            //If we include it inside the loop it tries to include random numbers
            cout << "Reached the end of an ascending sequence" << endl;
            cout << "Sequence starts at element: " << subStart << endl;
            cout << "Size of sequence is: " << counter << endl;

            if (counter > bestLength)
            {
                bestLength = counter;
                bestStart = subStart;
            }

        cout << endl;

        //iterator to get sub-sequence
   vector<int> result( next(sequence.begin(),bestStart),
                       next(sequence.begin(),bestStart+bestLength) );

    cout << "Output: ";
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << ",";
    }
      //return result;

}

int main()
{
    vector<int> l {1,2,3,4,1,5,1,6,7};

    AccSubSequence( l );

}


