#include <iostream>
#include<bits/stdc++.h>
using namespace std;
/*
    Problem Statement:  Given an integer array arr, find the contiguous subarray (containing at least one number) which
                        has the largest sum and returns its sum and prints the subarray.
*/

/* Contiguous subarray with the greatest sum: Kadane's Algorithm
    Brute Force: We use 3 loops and find all the permutations 
    Loop 1 : i -> 0 to n-1 : Start index of subarray
    Loop 2 : j -> i to n-1 : End index of subarray
    Loop 3 : k -> i to j   : Sum of the selected subarray
    Time Complexity : O(n^3)
*/

int KadaneBF(vector<int> &arr){
    int n = arr.size();
    int maxsum=INT_MIN,sum=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            sum=0;
            for(int k=i;k<=j;k++){
                sum+=arr[k];
            }
            maxsum = max(maxsum,sum); 
        }
    }
    return maxsum;
}
/* 
    Better Approach : 
    1. Since the next subarray just needs to add arr[j] to subset sum of arr[i....j-1], we use a pointer to the jth element and eliminate loop 3.
    2. Sum(arr[i….j]) = (sum(arr[i….j-1]) + arr[j])
    Time Complexity : O(n^2)

*/
int KadaneBetter(vector<int> &arr){
    int n = arr.size();
    int maxsum=INT_MIN,sum=0;
    for(int i=0;i<n;i++){
        sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            maxsum = max(maxsum,sum); 
        }
    }
    return maxsum;
}
/* 
    Optimal Solution : 
    1. Keep iterating from 0 to n-1
    2. Add the ith element to sum
    3. If sum<0, lets sum=0 
    4. if sum>max => max=sum
    4. return the max
    Time Complexity : O(n)
*/
int KadaneOptimal(vector<int> &arr){
    int n = arr.size();
    int maxsum=INT_MIN,sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum>maxsum){
            maxsum=sum;
        }
        if(sum<0){
            sum=0;
        }
    }
    return maxsum;
}
// Implementation to print subarray
int KadaneBetterGetSubarray(vector<int> &arr){
    int n = arr.size();
    int maxsum=INT_MIN,sum=0;
    int start=0, ansStart=-1,ansEnd=-1;
    for(int i=0;i<n;i++){
        if(sum==0) start=i;
        sum+=arr[i];
        if(sum>maxsum){
            maxsum=sum;
            ansStart= start;
            ansEnd = i;
        }
        if(sum<0){
            sum=0;
        }
    }
    cout << "The subarray is: [";
    for (int i = ansStart; i <= ansEnd; i++) {
        cout << arr[i] << " ";
    }
    cout << "]n";

    return maxsum;
}
int main()
{
    vector<int> arr = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
    int maxSum = KadaneBetterGetSubarray(arr);
    cout << "The maximum subarray sum is: " << maxSum << endl;
    return 0;
}