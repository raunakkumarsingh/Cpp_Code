// Two Pointer Approach 

// Definition :  
//      It is a basic and easy to understand approach .You all are familiar with this  because it has been most used in
//      array specially where there is the need to traverse the array.

//      In most of question you can able to use this two pointer technique like :
//         i)To find the intersection of two array 
//         ii)Pair sum
//         iii)Triplet sum

// Working :
//     1) Traverse the loop till the size of array by using while loop and place the pointer according to our need . 
//     2)  while traversing we will specify the if-else condition

//         condition:
//             if  (i == j ) -- if this condition became true than we will store this i pointer value in new array .       
//             else if (i < j) -- if this cindition is true than we will move i pointer forward by 1.
//             else (i > j) -- if this condition is true than we will move j pointer forward by 1.

//  Time complexity : O(n2) -- depend on many other factor too
//  Space complxity : O(1) -- depend on mant other factor too

// //code 

// Question: To find intersection of 2 array by using two-pointer approach


#include<iostream>    // header file
using namespace std;

int main() {          //main function
 
   int arr1[100];       // initialize first array with max size of 100

   int arr2[100];       // initialize second array with max size of 100
   int n;              // n will hold the size of first array
   int m;              // m will hold the size of first array
   int s;              // s for taking the input in both array first and second
   int i = 0;          // fisrt pointer  
   int j = 0;          // second pointer
 
   cout << "Enter Size of first array :  \n";           // taking size as an input of fisrt array
   cin  >> n;
 
   cout << "Enter elements of first array in sorted manner :  \n";  // taking the input as an element of first array 
 
   for (s = 0; s < n; s++) {
  
      cin >> arr1[s];
  
   }
 
   cout << "Enter Size of second array :  \n";   // taking size as an input of second array
   cin  >> m;
 
   cout << "Enter elements of second array in sorted manner :  \n";  // taking the input as an element of second array 
 
   for (s = 0; s < m; s++) {
  
      cin >> arr2[s];
  
   }
 
 
   while (i <= n && j <= m)   // from here the two -pointer approach started this while loop iterate through both of array till the iand j equal to first and second 
   {                           // array size
  
      if (arr1[i] == arr2[j])   // while traversing both array simultaneously , if i and j pointer value became equal then this condition will execute
      {
   
         cout<<arr1[i] <<" ";   
   
         i++;                  // both pointer will move forward by 1 
         j++;
   
      } 
      else if (arr1[i] < arr2[j]) // if this condition became true than only i pointer will move ahead
      {
   
         i++;
   
      } 
      else     // if both of the upper condition became false than this else condition will get execute and j pointer move ahead
      {
        j++;
      }
   
    }
   return 0;
}
 
