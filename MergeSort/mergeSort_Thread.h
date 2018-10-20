#include<bits/stdc++.h>


#ifndef INC_MERGESORT_THREAD_H
#define INC_MERGESORT_THREAD_H
#define MAX 100
extern int a[MAX];

void *mergesort(void*);
void merge_sort(int,int);
void mergeProcedure(int,int,int);

#endif