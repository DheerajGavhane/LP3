#include<iostream>
using namespace std;

int partition(int a[],int low,int high)
{
    int pivot=a[high];
    int i=low-1;

    for(int j=low;j<high;j++)
    {
        if(a[j]<pivot)
        {
            i++;
            swap(a[i],a[j]);
        }
    }

    swap(a[i+1],a[high]);

    return i+1;
}

void quickSort(int a[],int low,int high)
{
    if(low<high)
    {
        int pi=partition(a,low,high);

        quickSort(a,low,pi-1);
        quickSort(a,pi+1,high);
    }
}

int main()
{
    int n;

    cout<<"Enter number of elements: ";
    cin>>n;

    int a[n];

    cout<<"Enter elements: ";
    for(int i=0;i<n;i++)
        cin>>a[i];

    quickSort(a,0,n-1);

    cout<<"Sorted array: ";
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";

    return 0;
}
/*
Quick Sort is a sorting algorithm based on the Divide and Conquer technique.
It works in three steps:
1. Choose a pivot: Select an element from the array.
2. Partition: Place smaller elements on the left side of the pivot and larger elements on the right side.
3. Recursion: Apply Quick Sort to the left and right subarrays.

4. Algorithm – Deterministic Quick Sort
1. Start.
2. Select the last element as pivot.
3. Partition the array around the pivot.
4. Place smaller elements before the pivot.
5. Place larger elements after the pivot.
6. Recursively sort the left subarray.
7. Recursively sort the right subarray.
8. Stop when the subarray has zero or one element.
5. Algorithm – Randomized Quick Sort
1. Start.
2. Select a random element as pivot.
3. Swap the selected pivot with the last element.
4. Partition the array around the pivot.
5. Place the pivot in its correct position.
6. Recursively sort the left subarray.
7. Recursively sort the right subarray.
8. Stop when the subarray has zero or one element.
Case	Deterministic Quick Sort	Randomized Quick Sort
Best case	O(n log n)	O(n log n)
Average / Expected case	O(n log n)	O(n log n) expected
*/