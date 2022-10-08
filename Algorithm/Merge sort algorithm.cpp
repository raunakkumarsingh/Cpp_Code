#include <iostream>//include all header files
using namespace std;
void merge(int *,int, int , int );//declaring merge function for merging the sorted arrays
void merge_sort(int *arr, int low, int high)//
{
    int mid;
    if (low < high){
        //divide the array at mid and sort independently using merge sort
        
        mid=(low+high)/2;
        merge_sort(arr,low,mid);//sort first half recursively
        merge_sort(arr,mid+1,high);//sort second half recursively
        merge(arr,low,high,mid);//to merge sorted arrays in above steps.
    }
}
// Merge sort 
void merge(int *arr, int low, int high, int mid)
{
    int i, j, k, c[50];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high) {//sorting the elements and inserting into c array
        if (arr[i] < arr[j]) {//if element in first array is less than element in right array the place element in right array into c array
            c[k] = arr[i];
            k++;
            i++;
        }
        else  {
            c[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= mid) {//loop till extra element in left array
        c[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high) {//loop till extra element in right array
        c[k] = arr[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)  {//copying elements from  c to arr
         arr[i] = c[i];
    }
}

// read input array and call mergesort
//program execution start from here
int main()
{
    int myarray[30], num;
    cout<<"Enter number of elements to be sorted:";
    cin>>num;
    cout<<"Enter "<<num<<" elements to be sorted:";
    for (int i = 0; i < num; i++) { cin>>myarray[i];// Enter input values
    }
    merge_sort(myarray, 0, num-1);//calling merge sort
    cout<<"Sorted array\n";
    for (int i = 0; i < num; i++)
    {
        cout<<myarray[i]<<"\t"; //we get sorted values
    }
}



