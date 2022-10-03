//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // arr[] : int input array of integers
    // k : the quadruple sum required

    // Naive Approach
    // Time 0(n^4)
    vector<vector<int>> fourSum(vector<int> &arr, int K)
    {
        // Your code goes here
        int n = arr.size();
        //unordered_set<int> s;
        vector<vector<int>> ans;
        set<vector<int>> st;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n - 3; i++)
        {
            for (int j = i + 1; j < n - 2; j++)
            {
                for (int k = j + 1; k < n - 1; k++)
                {
                    
                    for (int l = k + 1; l < n; l++)
                    {

                        int sum = arr[i] + arr[j] + arr[k] + arr[l];

                        if (sum == K)
                        {
                            vector<int> inner;
                            inner.push_back(arr[i]);
                            inner.push_back(arr[j]);
                            inner.push_back(arr[k]);
                            inner.push_back(arr[l]);
                            sort(inner.begin(), inner.end());
                            st.insert(inner);
                            
                        }
                        else if(sum > K){
                            break;
                        }
                    }
                }
            }
        }
        for(auto it:st){
            ans.push_back(it);
        }
        return ans;
    }


// Time complexity 0(n^3)
vector<vector<int>> fourSum(vector<int> &arr, int K)
{
  // Your code goes here
  int n = arr.size();
  set<vector<int>> st;
  vector<vector<int>> ans;
  sort(arr.begin(), arr.end());
  //debug(arr);
  for(int i = 0; i < n -3; i++){
    for(int j = i+1; j < n-2; j++){
      int k = j+1, l = n-1;
      while(k < l){
        int sum = arr[i]+arr[j]+arr[k]+arr[l];
        // if(arr[i] == 30 && arr[j] == 97){
        //   debug(sum)
        //   debug(K)
        // }
        if(sum == K){
          vector<int> inner;
          inner.push_back(arr[i]);
          inner.push_back(arr[j]);
          inner.push_back(arr[k]);
          inner.push_back(arr[l]);
          // if(st.find(inner) == st.end()){
          //   ans.push_back(inner);
          ////debug(inner)
          // }
          
          st.insert(inner);
          k++;
          l--;
        }
        else if(sum < K){
          k++;
        }
        else{
          l--;
        }
      }
    }
  }
  
  for(auto it:st){
    ans.push_back(it);
    
  }
  sort(ans.begin(), ans.end());
  // fo(i,0,ans.size()){
  //   //debug(ans[i]);
  // }
  return ans;
}
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int>> ans = ob.fourSum(a, k);
        for (auto &v : ans)
        {
            for (int &u : v)
            {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty())
        {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends