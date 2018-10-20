#include<bits/stdc++.h>
#include "benchMark.h"
#include "mergeSort_Thread.h"
using namespace std;

//#define MAX 100

#define THREAD_MAX 4
//int a[MAX];

int main(){
	clock_t c1,c2;  // to measure the time 
    
	for(int i=0;i<MAX;i++)
		a[i]=rand() % 100;   // to generate the random numbers
	cout<<"Input numbers:" <<"  ";
	for(int i=0;i<MAX;i++)
		cout << a[i] <<" ";   // print the numbers

	cout << endl;
	c1=clock();
	mergeSort(a,0,MAX-1);
	c2=clock();
	cout << "Sorted numbers:" <<" ";
	for(int i=0;i<MAX;i++)
		cout << a[i] <<" ";

	cout << endl;
	cout << "Time taken: " << (c2 - c1) / (double)CLOCKS_PER_SEC << endl;



	//**********************************************MergeSort_WithTHREADING *********************************************************************

	cout <<endl;
	cout <<"**************************************************************************************************************************************"<<endl;
	cout << "=========================================================  NOW WITH THREADING ======================================================="<<endl;

	for(int i=0;i<MAX;i++)
		a[i]=rand() % 100;   // to generate the random numbers
	cout<<"Input numbers:" <<"  ";
	for(int i=0;i<MAX;i++)
		cout << a[i] <<" ";

	cout << endl;
	
	pthread_t threads[THREAD_MAX];

	//creating the threads
	for(long i=0;i<THREAD_MAX;i++)
		pthread_create(&threads[i],NULL,mergesort,(void*)i);

	c1=clock();

	//joining the threds
	for(int i=0;i<THREAD_MAX;i++)
		pthread_join(threads[i],NULL);

	//merging the final 4 parts
    mergeProcedure(0, (MAX / 2 - 1) / 2, MAX / 2 - 1); // merging the first 2 parts
    mergeProcedure(MAX / 2, MAX/2 + (MAX-1-MAX/2)/2, MAX - 1); // merging the 3rd and 4th parts
    mergeProcedure(0, (MAX - 1)/2, MAX - 1); // now, merging the final two parts



	c2 = clock(); 
  
    // displaying sorted array 
    cout << "Sorted array: "; 
    for (int i = 0; i < MAX; i++) 
        cout << a[i] << " "; 

    cout << endl;
  
    // time taken by merge sort in seconds 
    cout << "Time taken: " << (c2 - c1) / (double)CLOCKS_PER_SEC << endl; 

	return 0;
}