// Box Stacking Problem: 

// Given a set of n rectangular 3-D boxes, we want to create a stack of boxes with maximum height.

/* Constraints:
 1. A Box can be placed on top of another box if and only if the depth and width of the upper box are smaller than that of lower box.
 2. Rotations of boxes such that width is smaller than depth is allowed. 
 3. We can have 2 different rotations of a box as part of maximum height stack.
 */

/*
    Main idea is to convert the problem in such a form that LIS (longest Increasing Subsequence) can be applied.)
    => First we generate all 3 possible rotations for all the boxes available. For the sake of simplicity we take depth strictly greater than width.
    => Then we sort all the above generated boxes in non-increasing order of base area.
    => Now the problem becomes same as LIS having the following substructure (optimal) property:
    MaxStackHeight(i)= {max(MaxStackHeight(j)) + height(i)}
    Where width(j) > width(i) and depth(j) > depth(i) and i>j.
    And, MaxStackHeight(i)=height(i), if no such j exists.

    We return max(MaxStackHeight(i)) for  0 < i < n.
*/ 

// DP Implementation
#include<iostream>
#include<algorithm>
using namespace std;

//  Making a structure to store attributes of a box.
struct Box
{
 // To keep the solution simple, we always keep depth >= width
int height, width, depth;
};



// Comparator function for sorting
int compare (const void *a, const void * b)
{
    return ( (*(Box *)b).depth * (*(Box *)b).width ) -
           ( (*(Box *)a).depth * (*(Box *)a).width );
}
 

int maxStackHeight( Box arr[], int n )
{
//  Create an array of all 3 rotations of given boxes, thus the size becomes 3 times the original, i.e. 3xn
Box possibleRotations[3*n];
int index = 0;
for (int i = 0; i < n; i++)
{
	// Original Rotation
	possibleRotations[index].height = arr[i].height;
	possibleRotations[index].depth = max(arr[i].depth, arr[i].width);
	possibleRotations[index].width = min(arr[i].depth, arr[i].width);
	index++;

	// Rotation 1
	possibleRotations[index].height = arr[i].width;
	possibleRotations[index].depth = max(arr[i].height, arr[i].depth);
	possibleRotations[index].width = min(arr[i].height, arr[i].depth);
	index++;

	// Rotation 2
	possibleRotations[index].height = arr[i].depth;
	possibleRotations[index].depth = max(arr[i].height, arr[i].width);
	possibleRotations[index].width = min(arr[i].height, arr[i].width);
	index++;
}

// Thus the number of boxes is 3n now.
n = 3*n;

//  Sorting the array 'possibleRotations[]' in decreasing order of base area 
qsort (possibleRotations, n, sizeof(possibleRotations[0]), compare);


//  Initializing the MaxStackHeight values for all indexes with values as MaxStackHeight[i] => Maximum possible Stack Height with box i on top 
int MaxStackHeight[n];
for (int i = 0; i < n; i++ )
	MaxStackHeight[i] = possibleRotations[i].height;

//   Bottom up approach to find the optimized MaxStackHeight value
for (int i = 1; i < n; i++ )
	for (int j = 0; j < i; j++ )
		if ( possibleRotations[i].width < possibleRotations[j].width &&
			possibleRotations[i].depth < possibleRotations[j].depth &&
			MaxStackHeight[i] < MaxStackHeight[j] + possibleRotations[i].height
			)
		{
			MaxStackHeight[i] = MaxStackHeight[j] + possibleRotations[i].height;
		}


// Returning maximum of all MaxStackHeight values 

return *max_element(MaxStackHeight,MaxStackHeight+n);
}

int main()
{
Box arr[] = { {4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32} };
int n = sizeof(arr)/sizeof(arr[0]);

cout<<"The maximum possible height of stack is "<<maxStackHeight (arr, n)<<endl;

return 0;
}
