//{ Driver Code Starts
// Sort 0 1 2
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Approach -1
    // Use an Auxillary Array of size 3 {0 1 2}
    // Map all the elements in it 
    // then after push them in original array
    // Time Complexity 0(n)
    // Constant space
    void sort012(int a[], int n)
    {
        int aux[3] = {0, 0, 0};
        for(int i = 0; i < n ; i++){
            aux[a[i]]++;
        }
        int j = 0;
        for(int i = 0; i < 3; i++){
            while(aux[i]--){
                a[j++] = i;
            }
        }
    }

    // Approach - 2
    // Simplly use sort
    void sort012I(int a[], int n)
    {
        sort(a, a+n);
    }

    // Approach - 3
    // Dutch Nation Flag algo
    // Take three integers low = 0, mid = 0, high = n-1
    // if a[mid] = 0 swap with a[low] low++, mid+=
    // if mid = 1 increment mid
    // else swap a[mid] with a[high] high--
    // Time Complexity 0(logn)
    // No extra Space
    void sort012II(int a[], int n)
    {
        int low = 0, high = n-1, mid = 0;
    
        while(mid <= high){
    
            if(a[mid]==0)
                swap(a[mid++], a[low++]);
           
            else if(a[mid]==1)
                 mid++;
    
            else
                swap(a[mid], a[high--]);
        }
    }

    int main()
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }

        cout << endl;
    }
    return 0;
}

// } Driver Code Ends