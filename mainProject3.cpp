/**
* James Kaiser
* hp0106rn
* Due: 02/12/2024
* Professor Dr Jie Mieschner
*
* Project 3 - kSmallest Algorithm Implementation

* @file mainProject3.cpp

* This file contains the two functions and a main program. 
* Included is a kSmallest function, partition function, and a tester program which will test three cases.
* The three cases tested are kth Small is in S1, kth Small is the pivot, and kth Small is in S2.
*/

#include <iostream>
using namespace std;

/**
* Partition Function, this function will partition an Array and return the index of the partition
*
* @param anArray, the array that will be partitioned
* @param first, type integer, that is the first integer in the array
* @param last, type integer, that is the last integer in the array
* @return the index of the array partition is returned
*
*/

int partition(int *anArray, int first, int last)
{
	int pivot = anArray[first];
	int fromLeft = first + 1;
	int fromRight = last;
	
	bool done = false;
	while(!done)
	{
		while(fromLeft <= last && anArray[fromLeft] <= pivot)
			fromLeft++;
		
		while(fromRight >= first && anArray[fromRight] > pivot)
			fromRight--;
		
		if(fromLeft < fromRight)
		{
			swap(anArray[fromLeft], anArray[fromRight]);
			fromLeft++;
			fromRight--;
		}
		else
			done = true;
		
	}
	
	swap(anArray[first], anArray[fromRight]);
	return fromRight;

}

/**
* kSmall Function, this function will return the kSmallest value in anArray[first ... last]
*
* @param kth, which is the smallest value that can be found
* @param anArray, the array that will be search to find kth
* @param first, the index of the first element
* @param last, the index of the last element
* @return the kth small value is returned, (kth).
*
*/

int kSmall(int kth, int *anArray, int first, int last)
{
	/** BASE CASE HANDLING */
	
	if(first == last)
	{
		return anArray[first];
	}
	
	int pivotIndex = partition(anArray, first, last); 				// choose a pivot value p from anArray[first...last]
	int p = pivotIndex - first + 1;
	
	if(kth < p)
		return kSmall(kth, anArray, first, pivotIndex - 1);
	else if(kth == p)
		return anArray[pivotIndex];
	else
		return kSmall(kth - p, anArray, pivotIndex + 1, last);
}

int main()
{
	int length;
	
	cout << "How many integers do you need to enter? ";
	cin >> length;
	
	int *anArray = new int[length];
	cout << "------------------------------------------------" << endl;
	cout << "Please enter " << length << " integers." << endl;
	
	for(int i = 0; i < length; i++)
		cin >> anArray[i];
	
	int pIndex = partition(anArray, 0, length - 1);
	cout << "------------------------------------------------" << endl;
	cout << "The pivot is " << pIndex + 1 << endl;
	
	int kth;
	cout << "------------------------------------------------" << endl;
	cout << "Here is your partitioned array ";
	for(int i = 0; i < length; i++)
		cout << anArray[i] << " ";
	
	cout << endl;
	
	cout << "------------------------------------------------" << endl;
	cout << "Enter the index (k) you would like to test: " << endl;
	cin >> kth;
	cout << "------------------------------------------------" << endl;

	int n = length;
	int p = kSmall(kth, anArray, 0, n - 1);
	
	cout << "The " << kth << " (st/nd/rd/th) smallest element is " << p << endl;
	cout << "------------------------------------------------" << endl;

	if(p == anArray[pIndex])
	{
		cout << "The kth element " << p << " is the pivot" << endl;
	}
	else if(kth < anArray[pIndex])
	{
		cout << "The kth element " << p << " is in S1" << endl;
	}
	else
	{
		cout << "The kth element " << p << " is in S2" << endl;
	}
	
	return 0;
	
	delete[] anArray;
	
}