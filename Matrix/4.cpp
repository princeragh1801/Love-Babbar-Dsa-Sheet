//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:

    // time 0(R*C)
    // space 0(R*C)
    int median1(vector<vector<int>> &matrix, int R, int C){
        // code here
        vector<int> aux;
        for(int i = 0; i <R; i++){
            for(int j =0; j < C; j++){
                aux.push_back(matrix[i][j]);
            }
        }
        sort(aux.begin(), aux.end());
        int n = aux.size();
        return aux[n/2];
    }

    // in merging time 0(n+m)
    
    vector<int> merging(vector<int> &a, vector<int> &b){
        vector<int> aux;
        int i = 0, j = 0;
        int n = a.size(), m = b.size();
        while(i < n && j < m){
            if(a[i] <= b[j]){
                aux.push_back(a[i]);
                i++;
            }
            else{
                aux.push_back(b[j]);
                j++;
            }
        }
        while(i < n){
            aux.push_back(a[i]);
        }
        while(j < m){
            aux.push_back(b[j]);
        }
        return aux;
    }
    int median2(vector<vector<int>> &matrix, int R, int C){
        // code here
        vector<int> aux;
        int i = 0;
        while(i < R){
            aux = merging(aux, matrix[i]);
            i++;
        }
        int n = aux.size();
        return aux[n/2];
    }


    // Efficient approach
    // Time(logn)for binary search and iterationg through all the rows
    // overall 0(nlog(m))
    int noLesserThanTarget(vector<vector<int>> v, int target){
        int total = 0;
        
        for(int i = 0; i < v.size(); i++){
            int n = v[0].size();
            int low = 0, high = n-1, mid;
            while(low <= high){
                mid = (low+high)/2;
                if(v[i][mid] <= target){
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
            total += low;
        }
        return total;
    }

    // it's basically a binary search


    // overall
    // Expected Time Complexity: O(32(32bit integer) * R(row) * log(C)(column))
    // Expected Auxiliary Space: O(1)
    int median(vector<vector<int>> &matrix, int R, int C){
        // code here
        int low = 0, high = 2000;
        while(low <= high){
            int mid = (low+high)/2;
            int cnt = noLesserThanTarget(matrix, mid);
            if(cnt <= (R*C)/2){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return low;
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
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}
// } Driver Code Ends