//{ Driver Code Starts
//Initial function template for C++
// Kth Smallest/Largest
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function

    // Approach - 1
    // First thing that i was thinking about is that find the maximum element set it to -1 till k times(if array doesn't contain negative elements only when i will do this)
    // Time Complexity Worst Case 0(n^2)
    int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        int kthSmall;
        while(k--){
            int lar = INT_MIN;
            int in = 0;
            for(int i = l; i < r; i++){
                if(arr[i] > lar){
                    in = i;
                    lar = arr[i];
                }
            }
            arr[in] = -1;
            kthSmall = lar;
        }
        return kthSmall;
    }

    // Approach - 2
    // Sort the array and return arr[r-k]
    // Time Complexity 0(nlogn)
    int kthSmallest1(int arr[], int l, int r, int k) {
        //code here
        sort(arr+l, arr+r);
        return arr[r-k];
    }

    // Approach - 3
    // If We can use extra space then and elements and different/same(it take different approach)
    // Use set or map 
    // Put all the element into map/ get the element
    int kthSmallest2(int arr[], int l, int r, int k) {
        //code here
        set<int> s;
        for(int i = l; i < r; i++){
            s.insert(arr[i]);
        }
        int x = 0;
        for(auto it : s){
            if(r-k == x){
                return it;
            }
            x++;
        }
        s.clear();
        return -1;
    }
};

//{ Driver Code Starts.
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends