#include <iostream>
#include<bits/stdc++.h>
using namespace std;
/*
    Problem Statement:  Given a matrix, your task is to rotate the matrix 90 degrees clockwise.
*/

/*
    Brute Force Approach :  Take another dummy matrix of n*n, and then take the first row of the matrix and put it in the last 
                            column of the dummy matrix, take the second row of the matrix, and put it in the second last column of the matrix and so.
    Time complexity: O(n^2)
    Space Complexity: O(n^2)
*/

/*
    Optimal Approach :  
        Step 1: Transpose the matrix. (transposing means changing columns to rows and rows to columns)
        Step 2: Reverse each row of the matrix.
    Time complexity: O(n^2)
    Space Complexity: O(1)
*/

vector<vector<int>> RotMat(vector<vector<int>> &mat){
    int m = mat.size();         // Rows
    int n = mat[0].size();      // Columns
    for(int i=0;i<m;i++){
        for(int j=0;j<i;j++){
            swap(mat[i][j],mat[j][i]);
        }
    }
    for(int i=0;i<m;i++){
        reverse(mat[i].begin(),mat[i].end());
    }
    return mat;
}

int main() {
    vector < vector < int >> arr;
    arr =  {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    arr = RotMat(arr);
    cout << "Rotated Image" << endl;
    for (int i = 0; i < arr.size(); i++) {
    for (int j = 0; j < arr[0].size(); j++) {
        cout << arr[i][j] << " ";
    }
    cout << "\n";
    }

}