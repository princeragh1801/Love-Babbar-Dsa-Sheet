//{ Driver Code Starts
//Initial Template for C++
// Rotate an array cyclically
#include <bits/stdc++.h>
using namespace std;
#define fo(i, a, b) for(int i = a; i < b; i++)

void rotate(int arr[], int n);

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int a[n] , i;
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        rotate(a, n);
        for (i = 0; i < n; i++)
            printf("%d ", a[i]);
        printf("\n");
    }
        return 0;
}

// } Driver Code Ends


//User function Template for C++

// Rotate an array one
// Approach - 1
// Take an auxillary array
// Time Complexity 0(n)
// Space complexity 0(n)
void rotate(int arr[], int n){
    int temp[n];
    int j = 0;
    fo(i, 1,n){
        temp[j++] = arr[i];
    }
    temp[j] = arr[0];
    fo(i, 0, n){
        arr[i]=temp[i];
    } 
}

// Approach - 2
// Take a variable temp = arr[n-1]
// shift elements
// arr[0] = temp
// Time Complexity 0(n)
void rotate(int arr[], int n)
{
    int temp = arr[n-1];
    for(int i = n-1; i > 0; i--){
        arr[i] = arr[i-1];
    }
    arr[0] = temp;
}