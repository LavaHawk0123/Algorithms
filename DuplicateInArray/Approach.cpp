#include <iostream>
#include<bits/stdc++.h>
using namespace std;
/*
    Problem Statement:  Given an array of N + 1 size, where each element is between 1 and N. Assuming there is only one duplicate number, your task is to find the duplicate number.

/*
    Brute Force Approach : 
    Optimal Approach:
        

*/

vector<int> DuplicateDetect(vector<int> arr) {
    unordered_set<int> hashTable;
    for(int i=0;i<arr.size();i++) {
        if(hashTable.find(arr[i]) != hashTable.end()) return {i,arr[i]};
        hashTable.insert(arr[i]);
    }
    return {-1,-1};
}


int main() {
    vector<int> A = {2, 1, 15, 4, 3, 15, 0};
    vector<int> res = DuplicateDetect(A);
    if(res[0]!=-1){
        cout<<"Duplicate entry "<<res[1]<<" exists at "<<res[0]<<"\n";
    }
    else cout<<"Duplicate entry does not exist\n";
    return 0;
}
