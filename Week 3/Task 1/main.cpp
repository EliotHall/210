#include <iostream>
#include <string>
using namespace std;

int main()
{
    string word, temp1, temp2;
    getline( cin, word, '\n' );
    //word = "this is a test";

    cout << ">>" << word << "<<" << endl;

    int stringSize = word.size();
    int wordsize;

    for (int i = word.size() - 1; i >= 0; i--)
    {
        //cout << word[i] << endl;
        if (word[i] == ' ')
        {
            //The word size is the totally string size to the location of i
            //Is -1 because of the element starting at 0 and i starting at 1.
            wordsize = stringSize - i-1;
            //stringSize becomes i, as if the words had been removed from the
            //end of the string.
            stringSize = i;
            //The word starts at i+1 because we don't want the space,
            //wordsize is what measures the size of the word being taken.
            temp1 = word.substr(i + 1, wordsize);
            //The word gets moved to a new string with a space afterwards.
            temp2 += temp1 + " ";
        }
    }
    //Need to have this outside of the loop because there is no space
    //at the start of the string, and the first word would get missed.
    wordsize = stringSize - 1;
    temp1 = word.substr(0, wordsize+1);
    temp2 += temp1;
    cout << "This is the string: " << temp2 << endl;
    //O(4n)
}
