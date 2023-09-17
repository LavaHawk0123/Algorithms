#include <iostream>
#include<bits/stdc++.h>
using namespace std;
/*
    Problem Statement:  for all i & j < size of array, if i < j then you have to find pair (A[i],A[j]) such that A[j] < A[i].

/*
    Brute Force Approach : Iterate across 2 arrays
    Optimal Approach:
    In order to solve this, we will keep two pointers i and j, where i will point to the first index of a1[] and j will point to the first index of a2[]. Now in each iteration, 
    we will do the following:
        If a1[i] <= a2[j]: These two elements cannot be a pair and so we will move the pointer i to the next position.
    Why we moved the i pointer: 
        We know, that the given arrays are sorted. So, all the elements after the pointer j, should be greater than a2[j]. Now, as a1[i] is smaller or equal to a2[j], it is obvious that 
        a1[i] will be smaller or equal to all the elements after a2[j]. We need a bigger value of a1[i] to make a pair and so we move the i pointer to the next position i.e. next bigger value.
    If a1[i] > a2[j]: 
        These two elements can be a pair and so we will update the count of pairs. Now, here, we should observe that as a1[i] is greater than a2[j], all the elements after a1[i] 
        will also be greater than a2[j] and so, those elements will also make pair with a2[j]. So, the number of pairs added will be n1-i (where n1 = size of a1[ ]). Now, we will move the 
        j pointer to the next position.
*/

int inversionCount(vector<int> arr1,vector<int> arr2,int n){
    int i=0,j=0,count=0;
    sort(arr1.begin(),arr1.begin()+n);
    sort(arr2.begin(),arr2.begin()+n);
    while(i<n && j<n){
        if(arr1[i]<=arr2[j]){
            i++;
        }
        else{
            count+=(n-i);
            j++;
        }
    }
    return count;
}

int main()
{
    vector<int> a = {5, 4, 3, 2, 1};
    vector<int> b = {11, 12, 13, 14, 15};
    int n = 5;
    int cnt = inversionCount(a,b, n);
    cout << "The number of inversions are: "
         << cnt << endl;
    return 0;
}