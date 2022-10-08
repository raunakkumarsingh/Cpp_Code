
Insertion sort Algorithm Explanation

Defition:
    Insertion Sort is the basic sorting alogoritm , use for small data array sorting.

Working : 
    1) Pick up 1st element from the array then go to next element 
    2) Now compare the 1st and 2nd element of array .
    3) Conditon:

         if 2nd element is smaller than 1st element then , place 2nd element in right side of 1st element 
         else place the 2nd element in left side

    4) this will go until the size of array by using for loop

Points to remember: 
    In this algo , elements are not swapping instead of that they are getting shift by place.

Time Complexity : 
     Best-case : O(n) -- if the array is already sorted
     Worst-case : O(n2)  

Space Complexity : O(n)
    

// Code 
#include<iostream>                  // Header file
#include<bits/stdc++.h>
using namespace std;

int* insertionSort(int *arr , int n)  // insertionSort function which will return the sorted array
{
    for(int i =1 ; i<n ; i++)         // for loop for iterating arr which come in parameter from main function , see carefully for loop is starting from 1 .
    {
        int temp = arr[i];           // taking the 1st element of arr in temp variable , so it will ease the process of comparing
        int j = i-1;                // It's an important to start j with i - 1 because we have to compare the backward element from i until 0th element
        for( ; j >=0 ; j--)        // see here we specifiy the condition that loop should be iterate till the j is grater than 0 , which is satisfying the above line
        {
            if(arr[j] > temp)      // condition for shifting
            {
                arr[j+1] = arr[j];
            }
            else{                   // this could be like this -- (else if (arr[j] < temp) , if this became true than loop will break .
                break;
            }
        }
        arr[j+1] = temp;    // Important to understand --- it will take time so go through this step very consciously .      
                            // while comparing if we find the proper position of element than we will insert that element at [j+1] because ,
                            // basically we are comparing two elements from which i is at constant till the j is greater then 0 , so the j is pointing to all previous elemets 
    }                      // one by one , while doing this comparison if temp find the proper position than we will place it one element ahead of j itself.
  
    return arr;      // return the sorted arr to main function 
}

int main()                          // main function from where the execution of program started
{
    int arr[] = {5 , 2 , 1 , 9 };   // Declaring the array 
    int size = 4;                  // Declaring size of array

    int *ans = new int(size);      // Dynamically creating the array ans of size same to arr size

    ans = insertionSort(arr , size);  // calling the function insertionSort with two parametres one is array and second is size of array

    for(int i =0 ; i< size; i++)   // this for loop is for printing purpose , the sorted array which get stored in ans array will get print by this for loop
                                   // if you want and you cam also create a seperate function for printing purpose of array
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
