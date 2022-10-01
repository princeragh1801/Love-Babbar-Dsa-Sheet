// Move All The negative to right of the array

#include <bits/stdc++.h>
using namespace std;

// Approach - 1
// Take an Auxillary array of same size
// fist push all positive elements in
// after push all the negative elements in it
// Time Complexity 0(n)
// Space Complexity 0(n)
// Order maintained
void moveToRight(int arr[], int n){
    int aux[n];
    int k = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] >= 0){
            aux[k++] = arr[i];
        }
    }
    for(int i = 0; i < n; i++){
        if(arr[i] < 0){
            aux[k++] = arr[i];
        }
    }
    for(int i = 0; i < n; i++){
        arr[i] = aux[i];
    }
    
}

// Approach - 2
// sort the array and reverse it
// Order Not maintained
// Time Complexity 0(nlogn)
// No extra space required

void moveToRight2(int arr[], int n){
    sort(arr, arr+n);
    int i = 0, j = n-1;
    while(i < j){
        swap(arr[i++], arr[j--]);
    }
    
}

// Approach - 3
// take to interger positive = 0, negative = n-1
// increment +ve till negative
// decrement -ve till postive 
// swap
// Time Complexity 0(logn)
// No extra space required
// Order not maintained
void moveToRight3(int arr[], int n){
    int pos = 0, neg = n-1;
    while(pos < neg){
        if(arr[pos] < 0 && arr[neg] >= 0){
            swap(arr[pos++], arr[neg--]);
        }
        else if(arr[pos] >= 0){
            pos++;
        }
        else if(arr[neg] < 0){
            neg--;
        }
    }
    
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    moveToRight3(arr, n);
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
