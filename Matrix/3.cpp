//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

    // Brute force approach 
    // Time 0(n*m)
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
        int row = -1;
        int max1 = 0;
        for(int i = 0; i < n; i++){
            int cnt1 = 0;
            for(int j = 0; j < m; j++){
                if(arr[i][j] == 1){
                    cnt1++;
                }
            }
            if(cnt1 > max1){
                max1 = cnt1;
                row = i;
            }
        }
        return row;
	}



	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
        int row = -1;
        int max1 = 0;
        for(int i = 0; i < n; i++){
            int cnt1 = 0;
            int low = 0, high = m-1, mid;
            int curr = m-1;
            if(arr[i][high] == 1){
                while(low <= high){
                    mid =(low+high)/2;
                    if(arr[i][mid] == 1){
                        high = mid -1;
                        curr = mid;
                    }
                    else if(arr[i][mid] < 1){
                        low = mid+1;
                    }
                }
                cnt1 = m-curr;
                if(cnt1 > max1){
                    max1 = cnt1;
                    row = i;
                }
            }
            else{
                cnt1 = 0;
            }
            
        }
        return row;
	}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends