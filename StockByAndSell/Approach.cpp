#include <iostream>
#include<bits/stdc++.h>
using namespace std;
/*
    Problem Statement:  You are given an array of prices where prices[i] is the price of a given stock on an ith day.You want to maximize your profit by choosing a single day to buy 
                        one stock and choosing a different day in the future to sell that stock. Return the maximum profit you can achieve from this transaction. If you cannot achieve 
                        any profit, return 0.
*/

/*
    Brute Force Approach : We can simply use 2 loops and track every transaction and maintain a variable maxPro to contain the max value among all transactions.
    Time complexity: O(n^2)
*/

int BF(vector<int> &costs){
    int n = costs.size();
    int maxp = INT_MIN;

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(costs[j]>costs[i] && (costs[j]-costs[i])>maxp){
                maxp = costs[j]-costs[i];
            }
        }
    }
    return maxp;
}

/* Optimal Solution : 
    1.Create a variable maxPro and store 0 initially.
    2.Create a variable minPrice and store some larger value(ex: MAX_VALUE) value initially.
    3.Run a for loop from 0 to n.
    4.Update the minPrice if it is greater than the current element of the array
    5.Take the difference of the minPrice with the current element of the array and compare and maintain it in maxPro.
    6.Return the maxPro.
    
    Time complexity: O(n)
*/

int OptimalSoln(vector<int> &costs){
    int n = costs.size();
    int maxP = 0,minP = INT_MAX;
    for(int i=0;i<n;i++){
        if(minP>costs[i]){
            minP=costs[i];
            maxP = costs[i]-minP;
        }
    }
    return maxP;
}


int main() {
    vector<int> arr = {7,1,5,3,6,4};
    int maxPro = OptimalSoln(arr);
    cout << "Max profit is: " << maxPro << endl;
}