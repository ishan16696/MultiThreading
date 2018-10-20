//Merge Sorting using MultiThreading approach

#include<bits/stdc++.h>
#include "mergeSort_Thread.h"
using namespace std;
int a[MAX];

void mergeProcedure(int p,int q,int r){
	
    // n1 is size of left part and n2 is size  of right part 
    int n1 = q - p+ 1, n2 = r - q;
    int i, j; 

    // temp arrays
    int* left = new int[q - p + 1]; 
    int* right = new int[r - q]; 
  
    // storing values in left part 
    for (i = 0; i < n1; i++) 
        left[i] = a[p+i]; 
  
    // storing values in right part 
    for (i = 0; i < n2; i++) 
        right[i] = a[q+1+i]; 
  
    int k = p; 
    i = j = 0; 
  
    // merge left and right in ascending order 
    while (i < n1 && j < n2) { 
        if (left[i] <= right[j]) 
            a[k++] = left[i++]; 
        else
            a[k++] = right[j++]; 
    } 
  
    // insert remaining values from left 
    while (i < n1) { 
        a[k++] = left[i++]; 
    } 
  
    // insert remaining values from right 
    while (j < n2) { 
        a[k++] = right[j++]; 
    } 


}


void merge_sort(int low,int high){
	int mid=(low+high)/2;
	if(low<high){
	merge_sort(low,mid);
	merge_sort(mid+1,high);
	mergeProcedure(low,mid,high);
}
}

// thread function
void *mergesort(void* arg){
	//int mid;
	long thread_part=(long)arg;

	int low=thread_part*(MAX /4);
	int high=(thread_part+1)*(MAX/4)-1;  // 0 to 24 , 25 to 49 so on

	if(low<high){
	/*	mid=(low+high)/2;
		merge_sort(low,mid);
		merge_sort(mid+1,high);
		mergeProcedure(low,mid,high);
*/
        merge_sort(low,high);
	}
}

