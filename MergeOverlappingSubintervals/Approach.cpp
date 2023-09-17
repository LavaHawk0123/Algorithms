#include <iostream>
#include<bits/stdc++.h>
using namespace std;
/*
    Problem Statement:  Given an array of intervals, merge all the overlapping intervals and return an array of non-overlapping intervals.

/*
    Brute Force Approach:

    1.First, we will group the closer intervals by sorting the given array of intervals(if it is not already sorted).
    2.After that, we will select one interval at a time using a loop(say i) and insert it into our answer list(if the answer list is empty or the current interval cannot be merged with the 
        last interval of the answer list). While traversing and inserting we will skip the intervals that lie in the last inserted interval of our answer list.
    3.Now, for each interval arr[i], using another loop (say j) we are going to check the rest of the intervals(i.e. From index i+1 to n-1) if they can be merged with the selected interval.
    4.Inside loop j, we will continue to merge all the intervals that lie in the selected interval. 
        4.1 How to check if the current interval can be merged with the selected interval:
            We will compare the current interval’s start with the end of the selected interval. If the start is smaller or equal to the end, we can conclude the current interval can be a part 
            of the selected interval. So, we will update the selected interval’s end with the maximum(current interval’s end, selected interval’s end) in the answer list(not in the original 
            array).
    5.We will break out of loop j, from the first element that cannot be a part of the selected interval.
        4.4 How to check if the current interval is not a part of the selected interval:
            We will compare the current interval’s start with the end of the selected interval. If the start is greater than the end, we can conclude the current interval cannot be a part of 
            the selected interval.
    6.Finally, we will return the answer list.
    Time complexity:  O(N*logN) + O(2*N), where N = the size of the given array.
    Space Complexity: O(N)
*/

vector<vector<int>> mergeIntervalsBF(vector<vector<int>> &arr){
    int n = arr.size();
    sort(arr.begin(),arr.end());
    vector<vector<int>> ans;
    for(int i=0;i<n;i++){
        int start = arr[i][0];
        int end = arr[i][1];
        // Skip all merged intervals
        if(!ans.empty() && end<=ans.back()[1]){
            continue;
        }
        for(int j=i+1;j<n;j++){
            // Check if merge is possible
            if(arr[j][0]<=end){
                end = max(end, arr[j][1]);
            }
            else{
                break;
            }
        }
        ans.push_back({start,end});
    }
    return ans;
}

vector<vector<int>> mergeIntervalsOptimal(vector<vector<int>> &arr){
    int n = arr.size();
    sort(arr.begin(),arr.end());
    vector<vector<int>> ans;
    for(int i=0;i>n;i++){
        int start = arr[i][0];
        int end = arr[i][1];

        if(!ans.empty() && end<=ans.back()[1]){
            continue;
        }
        for(int j=i+1;j<n;j++){
            if(arr[j][0]<=end){
                end = max(end,arr[j][1]);
            }
            else{
                break;
            }
        }
        ans.push_back({start,end});
    }
    return ans;
}
int main()
{
    vector<vector<int>> arr = {{1, 3}, {8, 10}, {2, 6}, {15, 18}};
    vector<vector<int>> ans = mergeIntervalsOptimal(arr);
    cout << "The merged intervals are: " << "\n";
    for (auto it : ans) {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;
    return 0;
}
