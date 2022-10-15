#include <bits/stdc++.h>
using namespace std;

void printArr(vector<int> arr)
{
   for (int i = 0; i < arr.size(); i++)
   {
      cout << arr[i] << " ";
   }
}

// Insertion sort is the most adaptive sorting algorithm.

int main()
{
   vector<int> arr = {6, 4, 5, 3, 2, 1};
   int n = arr.size();

   for (int i = 1; i < n; i++) // no need to check 1st element
   {
      int temp = arr[i];
      for (int j = i - 1; j >= 0; j--)
      {
         if (arr[j] > temp)
         {
            swap(arr[j], arr[j + 1]);
         }
         else
         {
            break;
         }
      }
   }
   printArr(arr);
   return 0;
}
