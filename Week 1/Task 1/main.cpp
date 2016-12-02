#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;



int main()
{
    srand( time(NULL) ); // (1)

   // For loop to select 8 numbers, then selects a random location using rand
   // and swaps the two elements.
   //int nums[8] = {5,3,8,6,1,9,2,7};
   vector<int> nums = {5,3,-8,69,1,9,2,7}; // (1)
   for (int i = 0; i < nums.size(); i++) // (n)
   {
       cout << nums[i] << " "; // (n)
   }
   cout << endl; //(1)

   int temp, temp2;
   int index, index2;
   for (int i = 0; i < nums.size(); i++) // (n)
   {
       index = rand() % nums.size(); // (n)
       //temp = nums[index];

       index2 = rand() % nums.size(); // (n)
       //temp2 = nums[index2];

       //nums[index] = temp2;
       //nums[index2] = temp;

       swap( nums[index], nums[index2] ); // (n)
   }

   for( int i : nums ) // (n)
    cout << i << " "; // (n)

  /* for (int i = 0; i < nums.size(); i++)
   {
       cout << nums[i] << " ";
   }*/
   return 0; // (1)
}
// O(8n)
