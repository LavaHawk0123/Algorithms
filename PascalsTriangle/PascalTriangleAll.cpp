// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

/* Given a row number R and column number C, the element is (R-1)C(C-1)*/

long long int nCr(int n, int r){
    long long int res=0;
    for(int i=0;i<r;i++){
        res = (res*(n-i))/(i+1);
    }
    return res;
}

/* The Nth row will always have N elements
    brute force will be :
    for(i=0;i<n;i++){
        nCr(n-1,i-1);
    }
    Time complexity = O(n*r)

    Optimised approach:
    the nth row is:
    for(i=1;i<n;i++){
        ans = (ans*(n-i))/i;
        std::cout<< ans;
    }
*/

vector<int> printNthRow(int n){
    vector<int> templist;
    for(int i=1;i<n;i++){
        ans = (ans*(n-i))/i;
        templist.push_back(ans);
        std::cout<< ans;
    }
    return templist;
}
/* Brute Force approach for getting the entire triangle T(n) = O(n^3)*/
vector<vector<int>> getPascalTriangle(int n){
    vector<vector<int>> ans;
    for(int rows=0;rows<n;rows++){
        int templist[n] = {0};
        for(int col=1,col<rows;col++){
            templist.push_back(nCr(rows-1,col-1));
        }
        ans.push_back(templist);
    }
    return ans;
}
/* Optimal approach for getting the entire triangle T(n) = O(n^2)*/
vector<vector<int>> PascalsOptimal(int n){
    vector<vector<int>> ans;
    for(int rows=0;rows<n;rows++){
        ans.push_back(printNthRow(row));
    }
    return ans;
}

int main(){
    return 0;
}