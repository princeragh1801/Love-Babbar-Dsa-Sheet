//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// } Driver Code Ends
class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        // Base case
        if(low >=high){
            return;
        }


        int parIndex = partition(arr, low, high);

        quickSort(arr, low, parIndex-1);
        quickSort(arr, parIndex+1, high);
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
       // Your code here

       int pivot = arr[low];
       int i = low+1;
       int cnt = 0;
       while(i <= high){
            if(arr[i] <= pivot){
                cnt++;
            }
            i++;
       }
       swap(arr[low], arr[low+cnt]);
       i = low;
       int j = high;
       int ans = low+cnt;
       while(i < ans && j > ans){
            if(arr[i] > pivot && arr[j] <= pivot){
                swap(arr[i], arr[j]);
                i++;
                j--;
            }
            else if(arr[i] <= pivot){
                i++;
            }
            else{
                j--;
            }
       }
       return ans;
    }
};


//{ Driver Code Starts.
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
      #ifndef ONLINE_JUDGE
       freopen("input.txt", "r", stdin);
       freopen("error.txt", "w", stderr);
       freopen("output.txt", "w", stdout);
       #endif
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends