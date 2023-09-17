#include <iostream>
#include<bits/stdc++.h>
using namespace std;

/* To generate set of all permutations sorted:
    Brute Force:
    1. Generate all permutations in lexicographical order
    2. Linear Search
    3. Next Node
    Time complexity = O(n!*n)

    Optimisation : 
    for C++ user, using next_permutation(A.begin(),A.end()) will move to the next permutation

    Optimal Solution:
    1. The longer pattern match the better
    2. We will run a loop in such a way that ith element is lesser than all the elements to the right of it
    3. Of the numbers greater than the ith element, we choose the smallest of those elements(still greater than the break element)
    4. The rest of the elements will be placed in sorted order
    Note:
    [5 4 3 2 1] - edge case - reverse it
    [1 2 3 4 | 5] - worst case - lexicographically smallest

    Now the implementation : 
    1. Move to next index until a[i]<a[i+1] and then break
    2. swap the ith element with the smallest of the (n-i) elements of the array 
    3. Reverse the (n-i) elements in ascending order from the break point
    4. Result will be the next permutation
*/


vector<int> nextPermutation(vector<int> &lst){
    int ind = -1;
    int n = lst.size();
    for(int i=n-2;i>=0;i--){
        if(lst[i]<lst[i+1]){
            ind=i;
            break;
        }
    }
    if(ind==-1){
        reverse(lst.begin(),lst.end());
        return lst;
    }
    for(int i=n-1;i>ind;i--){
        if(lst[i]>lst[ind]){
            swap(lst[i],lst[ind]);
            break;
        }
    }
    reverse(lst.begin()+ind,lst.end());
    return lst;
}

int main()
{
    vector<int> A = {2, 1, 5, 4, 3, 0, 0};
    vector<int> ans = nextPermutation(A);

    cout << "The next permutation is: [";
    for (auto it : ans) {
        cout << it << " ";
    }
    cout << "]n";
    return 0;
}