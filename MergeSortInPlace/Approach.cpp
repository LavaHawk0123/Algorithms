#include <iostream>
#include<bits/stdc++.h>
using namespace std;
/*
    Problem Statement:  Given an array of intervals, merge all the overlapping intervals and return an array of non-overlapping intervals.

/*
    Brute Force Approach : Merge Sort(Not In Place)
    Optimal Approach:
        1.We will declare two pointers i.e. left and right. The left pointer will point to the last index of the arr1[](i.e. Basically the maximum element of the array). 
            The right pointer will point to the first index of the arr2[](i.e. Basically the minimum element of the array).
        2.Now, the left pointer will move toward index 0 and the right pointer will move towards the index m-1. While moving the two pointers we will face 2 different cases like the following:
            2.1 If arr1[left] > arr2[right]: In this case, we will swap the elements and move the pointers to the next positions.
            2.2 If arr1[left] <= arr2[right]: In this case, we will stop moving the pointers as arr1[] and arr2[] are containing correct elements.
        3.Thus, after step 2, arr1[] will contain all smaller elements and arr2[] will contain all bigger elements. Finally, we will sort the two arrays.

*/
void mergeInPlce(long long arr1[], long long arr2[], int n, int m){
    int left = n-1;
    int right=0;
    while(left>=0 && right<m){
        if(arr1[left]>arr2[right]){
            swap(arr1[left],arr2[right]);
            left--;
            right++;
        }
    }
    sort(arr1,arr1+n);
    sort(arr2,arr2+m);
    cout<<"Sorted array 1:";
    for(int i=0;i<n;i++){
        cout<<arr1[i]<<" ";
    }
    cout<<"Sorted array 2:";
    for(int i=0;i<m;i++){
        cout<<arr2[i]<<" ";
    }
    cout << endl;
}

int main()
{
    long long arr1[] = {1, 4, 8, 10};
    long long arr2[] = {2, 3, 9};
    int n = 4, m = 3;
    mergeInPlce(arr1, arr2, n, m);
    return 0;
}