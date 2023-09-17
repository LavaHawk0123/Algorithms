// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void markColmat(vector<vector<int>> &mat, int i,int m, int n){
    for(int j=0;j<n;j++){
        if(mat[i][j]!=0){
            mat[i][j] = -1;   
        }
    }
}

vector<vector<int>> zeroMat(vector<vector<int>> &mat,int m, int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if (mat[i][j]==0){
                markColmat(mat,i,m,n);
            }
        }
    }
    return mat;
}

int main(){
    vector<vector<int>> mat = {{1,0,1},{0,1,0},{1,1,1}};
    int n = mat.size(); // No of columns
    int m = mat[0].size(); // No of rows
    vector<vector<int>> ans = zeroMat(mat,m,n);
    for(auto i : ans){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<"\n";
    }
    return 0;
}