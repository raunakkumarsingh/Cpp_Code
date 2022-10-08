/*
 The idea of Kadane’s algorithm is to maintain a variable max_ending_here that stores the maximum sum 
 contiguous subarray ending at current index and a variable max_so_far stores the maximum sum of contiguous 
 subarray found so far, Everytime there is a positive-sum value in max_ending_here compare it 
 with max_so_far and update max_so_far if it is greater than max_so_far.
 */

// Java program to print largest contiguous array sum

// ALGORITHM

/*
  Initialize the variables max_so_far = INT_MIN and max_ending_here = 0
  Run a for loop form 0 to N-1 and for each index i:
  Add the arr[i] to max_ending_here.
  If  max_so_far is less than max_ending_here then update max_so_far  to max_ending_here.
  If max_ending_here < 0 then update max_ending_here = 0
  Return max_so_far
 */


import java.io.*;
import java.util.*;

public class Kadanes {

	public static void main(String[] args)
	{
		int[] a = { -2, -3, 4, -1, -2, 1, 5, -3 };
		System.out.println("Maximum contiguous sum is "
						+ maxSubArraySum(a));
	}

	// Function Call
	static int maxSubArraySum(int a[])
	{
		int size = a.length;
		int max_so_far = Integer.MIN_VALUE, max_ending_here = 0;

		for (int i = 0; i < size; i++) {
			max_ending_here = max_ending_here + a[i];
			if (max_so_far < max_ending_here)
				max_so_far = max_ending_here;
			if (max_ending_here < 0)
				max_ending_here = 0;
		}
		return max_so_far;
	}
}
//Time Complexity: O(N)
//Auxiliary Space: O(1)

