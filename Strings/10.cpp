//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    // Approach - 1
    // Use in built stl function

    vector<int> nextPermutation(int N, vector<int> arr){
        // code here
        next_permutation(arr.begin(), arr.end());
        return arr;
    }


    vector<int> nextPermutation(int N, vector<int> arr){
        // code here
        vector<int> ans(arr.begin(), arr.end());
        sort(ans.begin(), ans.end());
        reverse(ans.begin(), ans.end());
        if(ans == arr){
            sort(ans.begin(), ans.end());
            return ans;
        }
        int i = N- 2, j = N-1;
        for(j = N-1; j > 0; j--){
            i = j - 1;
            while(i > 0){
            if(arr[i] < arr[j]){
                //swap(arr[i], arr[j]);
                
                break;
            }
            i--;
        }
        if(i != 0){
            break;
        }
        }
        
        int in = i+1;
        int mark = j;
        while(in <= j){
            if(arr[in] > arr[i]){
                mark = in;
            }
            in++;
        }
        swap(arr[i], arr[mark]);
        sort(arr.begin()+i+1, arr.end());
        return arr;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends