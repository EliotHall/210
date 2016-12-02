#include <iostream>
#include <string>
#include <sstream>
//Binary!! =D
#include <bitset>
#include <math.h>

using namespace std;

int main()
{
  int64_t num = 1;
  int64_t n;
  string text;
  stringstream stream;

  //cout << bitset<64>(num) << endl;

  //Create the factorial number.
  cin >> n;
//  for (int i = n; i >= 1; i--)
//  {
//      num = i*num;
//
//  }
  //Convert the factorial number into a string.
  //Check from the end inwards how many 0's are trailing using for loop.

//  cout << "The factorial number of " << n << " is " << num << endl;
//  stream << num;
//  text = stream.str();
  int counter = 0;
//
//  for (int i = text.size()-1; i >= 0; i--)
//  {
//
//      if ( text[i] != '0')
//      {
//          cout << "There are " << counter << " trailing 0's" << endl;
//          return counter;
//
//      }
//      else
//      {
//          counter ++;
//      }
//  }

  int p = 1;
  int f;
  do
  {
    f = n/ pow(5,p); // (n)
    counter =+ f; // (n)
    p++; // (n)

  }
  while (f < 0); // (n)
  return counter; // (1)

// O(4n)
}
