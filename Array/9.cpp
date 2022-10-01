//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:  
        // Approach -1  
        // Common elements in three Array
        
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            //code here.
            int i = 0, j = 0, k = 0;
             vector<int> v;
             unordered_set<int> s;
            while(i < n1 && j < n2 && k < n3){
                if(A[i] == B[j] && B[j] == C[k]){
                    if(s.find(A[i]) == s.end()){
                        s.insert(A[i]);
                        v.push_back(A[i]);
                    }
                    i++;
                    j++;
                    k++;
                }
                else if(B[j] > A[i] && C[k] > A[i]){
                    i++;
                }
                else if(A[j] > B[j] && C[k] > B[j]){
                    j++;
                }
                else if(A[i] > C[k] && B[j] > C[k]){
                    k++;
                }
            }
            s.clear();
            if(v.size() == 0){
                v.push_back(-1);
            }
            return v;
        }
        // Approach 2;
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            //code here.
            vector<int> v;
            set<int> s1;
            for(int i = 0; i < n1; i++){
                s1.insert(A[i]);
            }
            set<int> s2;
            for(int i = 0; i < n2; i++){
                s2.insert(B[i]);
            }
            set<int> s3;
            for(int i = 0; i < n3; i++){
                s3.insert(C[i]);
            }
            for(auto it : s1){
                if(s2.find(it) != s2.end() && s3.find(it) != s3.end()){
                    v.push_back(it);
                }
            }
            if(v.size() == 0){
                v.push_back(-1);
            }
            return v;
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