/*
Given an array which has two arithmetic sequences and 
one geometric sequence (in any order).
Copy indexes where each sequence starts and ends into an Array and return it.

Note : Each sequence will be of atleast LENGTH 3,and The sequences can be overlapping

Ex : 1, 3, 5, 7, 2, 4, 8, 16 18 20, output is [0, 3, 7, 9, 4, 7]
Ex : 1 ,2, 4, 8, 12, 16, 21, 26     output is [2, 5, 5, 7, 0, 3]
Ex : 10 15 20 30 50 70 100 200 400 800  output is [0, 2, 3, 5, 6, 9]

The final_arr[0], final_arr[1] values in final array  
will be start and end indexes of First A.P in the Original Array

The final_arr[2], final_arr[3] values in final array  
will be start and end indexes of Second A.P 

The final_arr[4], final_arr[5] values in final array  
will be start and end indexes of First  G.P (Only)

Input: Array and Length of Array
Output : New Array which has 6 integers , which denote the (start,end) indexes .

Note : All elements in the array will be part of atleast 1 sequence .
Two A.P cannot start at same index . 

Difficulty : Medium
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int end_index_AP(int *, int, int, int);
int end_index_GP(int *, int, int, int);
int * find_sequences(int *arr, int len){
	//Return final array which has 6indexes [AP1_S,AP1_E,AP2_S,AP2_E,GP1_S,GP2_E]
	if (arr == NULL || len < 6){
		return NULL;
	}

	int *result, index, diff, r, res_ind=0;
	result = (int *)malloc(6 * sizeof(int));
	for (index = 0; index < len-2;){
		diff = arr[index + 1] - arr[index];
		if (arr[index + 1] + diff == arr[index + 2]){
			result[res_ind] = index;
			res_ind++;
			index=end_index_AP(arr, index + 1, diff, len);
			result[res_ind] = index;
			res_ind++;
		}
		else{
			index++;
		}
	}
	for (index = 0; index < len - 2;){
		r = arr[index + 1] / arr[index];
		if (arr[index + 1] * r == arr[index + 2]){
			result[res_ind] = index;
			res_ind++;
			index = end_index_GP(arr, index + 1, r, len);
			result[res_ind] = index;
			res_ind++;
		}
		else{
			index++;
		}
	}
	return result;
}
int end_index_AP(int *a, int ind, int diff, int len){
	for (; ind < len-1; ind++){
		if (a[ind] + diff != a[ind+1]){
			break;
		}
	}
	return ind ;
}
int end_index_GP(int *a, int ind, int r, int len){
	for (; ind < len-1; ind++){
		if (a[ind] * r != a[ind + 1]){
			break;
		}
	}
	return ind ;
}