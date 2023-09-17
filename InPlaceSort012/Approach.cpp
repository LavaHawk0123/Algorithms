#include <iostream>
#include<bits/stdc++.h>
using namespace std;
/*
    Problem Statement:  Given an array consisting of only 0s, 1s, and 2s. Write a program to in-place sort the array without using inbuilt sort functions. 
                        (Expected: Single pass-O(N) and constant space)
*/

/*
    Brute Force Approach : Simply sorting the array would put it in ascending order using bubble sort
*/

vector<int> BruteForce(vector<int> lst){
    int n = lst.size();
    for(int i=0;i<n;i++){
        for(int j=i;j<n-i-1;j++){
            if(lst[j]>lst[j+1]){
                swap(lst[j],lst[j+1]);
            }
        }
    }
    return lst;
}

/* Variation of the dutch national flag algorithm
This algorithm contains 3 pointers i.e. low, mid, and high, and 3 main rules.  The rules are the following:
    1.arr[0….low-1] contains 0. [Extreme left part]
    2.arr[low….mid-1] contains 1.
    3.arr[high+1….n-1] contains 2. [Extreme right part], n = size of the array
arr[mid...high] is the unsorted part of the array
intially:
    arr[0] = low,mid
    arr[n] = high 
Algorithm:
    1.First, we will run a loop that will continue until mid <= high.
    2.There can be three different values of mid pointer i.e. arr[mid]
        2.1 If arr[mid] == 0, we will swap arr[low] and arr[mid] and will increment both low and mid. Now the subarray from index 0 to (low-1) only contains 0.
        2.2 If arr[mid] == 1, we will just increment the mid pointer and then the index (mid-1) will point to 1 as it should according to the rules.
        2.3 If arr[mid] == 2, we will swap arr[mid] and arr[high] and will decrement high. Now the subarray from index high+1 to (n-1) only contains 2. In this step, we will do 
            nothing to the mid-pointer as even after swapping, the subarray from mid to high(after decrementing high) might be unsorted. So, we will check the value of mid again 
            in the next iteration.
    3.Finally, our array should be sorted.
*/

vector<int> DNFAlgo(vector<int> &arr){
    int n = arr.size();
    int low=0,mid=0,high=n;
    for(int i=mid;i<=high;i++){
        if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else if(arr[mid]==2){
            swap(arr[mid],arr[high]);
            high--;
        }
    }
    return arr;
}

int main()
{
    int n = 6;
    vector<int> arr = {0, 2, 1, 2, 0, 1};
    arr = DNFAlgo(arr);
    cout << "After sorting:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}