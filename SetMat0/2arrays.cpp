#include <iostream>
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> MatZero2Arrays(vector<vector<int>> &mat, int m, int n){
    int rows[n] = {0};
    int cols[m] = {0};

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]==0){
                rows[i] = 1;
                cols[j] = 1;
            }
        }
    }
    for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(rows[i]==1 || cols[j]==1){
                    mat[i][j] = 0;
                }
            }
    }
    return mat;
}

int main(){
    vector<vector<int>> mat = {{1,0,1},{0,1,0},{1,1,1}};
    int n = mat.size(); // No of columns
    int m = mat[0].size(); // No of rows
    vector<vector<int>> ans = MatZero2Arrays(mat,m,n);
    for(auto i : ans){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<"\n";
    }
    return 0;
}