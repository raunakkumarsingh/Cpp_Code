//Solution in C++
#include <bits/stdc++.h>//importing all header files at once
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);//THIS FOR ONE'S IOS SPACING, MEANT TO MAKE YOUR CODE BIT FASTER, USEFUL IN COMPETITIVE PROGRAMMING

    int n;//n denotes the size of the intger array
    cin >> n;
    int arr[n];

    int min = 0;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < (n - 1); i++)//We loop from 0 to n-2(i.e <(n-1)) because in the next loop we have i+1, the last index will be n-1( keep in mind for overflow)
    {
        min = i;//we consider the the first index element to be minimum, so storing first index as min
        for (int j = (i + 1); j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j; //we loop in the remaining elements of the array to find out what is the minimum element among them
            }
        }
        if (min != i)//if the minimum element after the given index is the not the same element, we swap two numbers
        {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
    //The process will continue, and we get  gradually start to get sorted array(from the beginning) 
    cout << endl;
  //Printing the required sorted array
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}