#include<bits/stdc++.h>
#include "benchMark.h"
using namespace std;

void merge(int a[],int p,int q,int r)
{
 int i, j, k;
    int n1 = q - p + 1;
    int n2 =  r - q;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temporary arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = a[p+i];
    for (j = 0; j < n2; j++)
        R[j] = a[q+1+j];
 
    /* Merge the temp arrays back into a[p..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = p; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            a[k++] = L[i++];
        else
            a[k++] = R[j++];
    }
 
    /* Copy the remaining elements of L[], if there are any */
    while (i < n1)
    {
        a[k++] = L[i++];
    }
 
    /* Copy the remaining elements of R[], if there are any */
    while (j < n2)
    {
        a[k++] = R[j++];
    }
}

void mergeSort(int a[],int low,int high){
		if(low<high){
			int mid=(low+high)/2;
			mergeSort(a,low,mid);
			mergeSort(a,mid+1,high);
			merge(a,low,mid,high);
		}

}

