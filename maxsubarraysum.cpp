#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n; // size of an array
    vector<int> arr(n); // array declaration
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int maxi = 0,best=0;
    // Kadane's Algorithm with TC of O(n) and SC as O(1)
    for(int i=0;i<n;i++){
         best = max(best+arr[i],arr[i]); 
         /*
            Storing the current possible max sum by including the element
            or else not including the element
            there are two possibilites where current element addition can result lesser sum
            in that case we have to go for the next greater element
            if current addition of the element results in bigger sum then include that element in
            int current best sum
         */
         maxi = max(maxi,best);
         /*
            This maxi variable will store the best possible maximum subarray sum from the
            calculated previous best subarray sum
         */
    }
    cout << maxi << endl; // will be the maximum subarray sum

    /*  
        Time Complexity -> O(N)
        Space Complexity -> O(1)
    */
}