//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:   

        // Approach -1
        // Brute Force Approach
        // Take three Nested Loops
        // Compare the elements
        // check if it is already in vector or not before storing
        // Store them in vector
        // return vector 

        vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            //code here.
            vector<int> v;
            int last = INT_MIN;
            for(int i = 0; i < n1; i++){
                for(int j = 0; j < n2; j++){
                    for(int k = 0; k < n3; k++){
                        if(A[i] == B[j] && B[j] == C[k]){
                            if(last != A[i]){
                                v.push_back(A[i]);
                                last = A[i];
                            }
                            
                        }
                    }
                }
            }

            if(v.size() == 0){
                return {-1};
            }
            return v;
        }

        // Approach - 2
        // Use Hashset insert elements
        // Check whether the element is common in array or not
        // if common push it to vector
        // return vector
        // Time Complexity  O(n1 + n2 + n3)
        // Space Complexity O(n1 + n2 + n3)


        vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            //code here.
            vector<int> v;
            unordered_set<int> s1;
            unordered_set<int> s2;
            unordered_set<int> s3;
            for(int i = 0; i < n1; i++){
                s1.insert(A[i]);
            }
            for(int i = 0; i < n2; i++){
                s2.insert(B[i]);
            }
            for(int i = 0; i < n3; i++){
                s3.insert(C[i]);
            }
            for(auto it : s1){
                if((s2.find(it) != s2.end()) && (s3.find(it) != s3.end())){
                    v.push_back(it);
                }
            }
            if(v.size() == 0){
                return {-1};
            }
            return v;
        }


        // Approach - 3
        // Best Approach to solve this problem
        // Take three pointers
        //Check if Elements equal or not
        // Check if common element is our last or not
        // push to ans
        // return ans
        // Time Complexity  O(min(n1, n2, n3))
        // No extra space is required
        vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3){
            vector<int> ans;
            int i = 0, j = 0, k = 0;
            int last = INT_MIN;
            while(i < n1 && j < n2 && k < n3){
                if(A[i] == B[j] && B[j] == C[k]){
                    if(last != A[i]){
                        ans.push_back(A[i]);
                        last = A[i];
                    }
                    i++, j++, k++;
                }
                if(A[i] < B[j] || A[i] < C[k]){
                    i++;
                }
                else if(B[j] < A[i] || B[j] < C[k]){
                    j++;
                }
                else if(C[k] < A[i] || C[k] < B[j]){
                    k++;
                }
                
            }

            if(ans.size() == 0){
                return {-1};
            }
            return ans;

        }
};

//{ Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; 
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];
        
        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];
        
        Solution ob;
        
        vector <int> res = ob.commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0) 
            cout << -1;
        for (int i = 0; i < res.size (); i++) 
            cout << res[i] << " "; 
        cout << endl;
    }
}
// } Driver Code Ends