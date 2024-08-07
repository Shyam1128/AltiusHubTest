#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n; // size of an array
    int k;
    cin >> k; // no. of times the array has to be rotated
    k%=n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    if(k==0){
        cout << "No Rotation" << endl;
        for(int i=0;i<n;i++){
            cout << arr[i] << " ";
        }
        cout << endl;
        return 0;
    }
    cout << "Rotation Required" << endl;
    k = k%n;// since k can be bigger than the size of an array adjust it with the modulus
    //reverse(begin(arr),end(arr));
    //reverse(begin(arr),begin(arr)+k);
    //reverse(begin(arr)+k,end(arr));
    /*The above implemenation is using STL or inbuilt Libraries in Cpp*/
    for(int i=0;i<n/2;i++){
        int temp = arr[i];
        arr[i] = arr[n-i-1];
        arr[n-i-1] = temp;
    }
    int fp = 0,sp=k-1;
    while(fp < sp){
        int temp = arr[fp];
        arr[fp] = arr[sp];
        arr[sp] = temp;
        fp++;
        sp--;
    }
    fp = k,sp=n-1;
    while(fp < sp){
        int temp = arr[fp];
        arr[fp] = arr[sp];
        arr[sp] = temp;
        fp++;
        sp--;
    }
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
}

/*               INTITUION*              
     1) Edge Cases that has to be considerd : 
     your k can be greater than the given size of the array that is (k>=n)
     but as we know the rotation can repeat at certain intervals to be more 
     precise it will repeat at every multiple of k times 
     i.e : 
     if k is the no. of times that has to be rotated then 
     every 2*k , 3*k , 4*k and so on... will have same rotation to it is better
     to adjust k in terms of modulus in order to compute

    2) Now Let's say the array is [1,2,3,4,5] and k = 2 that is rotation
       then the resulantat array will look like [4 ,5 ,1 ,2 ,3]
       but do develop an intution from the above code we can see the manipulation
       to be as : 
       if we reveset he array we can say the array as [5,4,3,2,1]
       now we want [4,5] to be at the start 2 position but in the reversed array 
       they are already reversed [5,4] so we will first rotate the array
       by k times here initially and now we want [1,2,3] as the rest of the part
       but it is also is in reversed order so we can just make sure that we will reverse
       the next half of the array or the next [k+1,n-1] position.
       in this order we will get our array as [4,5,1,2,3].

     Time Complexity -> O(n) + O(k) + O(n-k+1) => O(n)
     Space Complexity -> O(1) // as we are not using any addition space here 
*/
