//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:

    //  Brute force Approch 
    // Basically we have to optimise it
    int left(vector<int> arr, int index){
        int target = arr[index];
        int leftWidth = 0;
        for(int i = index-1; i >= 0; i--){
            if(arr[i] < target){
                break;
            }
            leftWidth++;
        }
        return leftWidth;
    }

    int right(vector<int> arr, int index, int n){
        int target = arr[index];
        int rightWidth = 0;
        for(int i = index+1; i < n; i++){
            if(arr[i] < target){
                break;
            }
            rightWidth++;
        }
        return rightWidth;
    }

    int largestArea(vector<int> arr, int n){
        int maxA = 0;
        int curr = 0;
        for(int i = 0; i < n; i++){
            int x = left(arr, i);
            int y = right(arr, i, n);
            int width = x+y+1;
            int length = arr[i];
            curr = width*length;
            maxA = max(maxA, curr);
        }
        return maxA;
    }

    int maxArea2(int M[MAX][MAX], int n, int m) {
        // Your code here
        vector<int> aux(m);
        int maxAr = 0;
        int curr = 0, i, j;
        for(i = 0; i < n; i++){
            for(j = 0; j < m; j++){
                if(M[i][j] == 0){
                    aux[j] = 0;
                }
                else{
                    aux[j] += M[i][j];
                }
            }
            curr = largestArea(aux, m);
            maxAr = max(maxAr, curr);
        }
        return maxAr;
    }

    // Expected Time Complexity : O(n*m)
    // Expected Auixiliary Space : O(m)
    vector<int> nextSmaller(vector<int> arr, int n){
        vector<int> ans(n);
        stack<int> st;
        st.push(-1);
        for(int i = n-1; i >= 0; i--){
            int curr = arr[i];
            // we are finding the index of element which is smaller than curr
            // or we can say that we are finding the right width
            while(st.top() != -1 && arr[st.top()] >= curr){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> prevSmaller(vector<int> arr, int n){
        vector<int> ans(n);
        stack<int> st;
        st.push(-1);
        for(int i = 0; i < n; i++){
            int curr = arr[i];
            // we are finding the index of element which is smaller than curr
            // or we can say that we are finding the left width
            while(st.top() != -1 && arr[st.top()] >= curr){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    int largestArea2(vector<int> arr, int n){
        int maxAr = 0;
        int curr = 0;
        vector<int> next = nextSmaller(arr, n);
        vector<int> prev = prevSmaller(arr, n);
        for(int i = 0; i < n; i++){
            int length = arr[i];
            if(next[i] == -1){
                next[i] = n;
            }
            int width = next[i]-prev[i]-1;
            curr = length*width;
            maxAr = max(curr, maxAr);
        }
        return maxAr;
    }
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        vector<int> aux(m);
        int maxAr = 0;
        int curr = 0, i, j;
        for(i = 0; i < n; i++){
            for(j = 0; j < m; j++){
                if(M[i][j] == 0){
                    aux[j] = 0;
                }
                else{
                    aux[j] += M[i][j];
                }
            }
            curr = largestArea2(aux, m);
            maxAr = max(maxAr, curr);
        }
        return maxAr;
    }
};


//{ Driver Code Starts.
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
      #ifndef ONLINE_JUDGE
       freopen("input.txt", "r", stdin);
       freopen("error.txt", "w", stderr);
       freopen("output.txt", "w", stdout);
       #endif
        int M[MAX][MAX];
        int n, m;
        cin >> n >> m;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    
}

// } Driver Code Ends