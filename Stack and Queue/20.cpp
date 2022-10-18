// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
//User function Template for C++

class Solution{
    
    public:
    vector<int> help_classmate1(vector<int> arr, int n) 
    { 
        // Your code goes here
        vector<int> v;
        int j;
        for(int i = 0; i < n-1; i++)
        {
            for(j = i+1; j < n; j++)
            {
                if(arr[i] > arr[j])
                {
                    v.push_back(arr[j]);
                    break;
                }
            }
            if(j == n)
            {
                v.push_back(-1);
            }
        }
        v.push_back(-1);
        return v;
    } 
    vector<int> help_classmate(vector<int> arr, int n) 
    { 
        // Your code goes here
        stack<pair<int, int>> st;
        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            ans[i] = -1;
            int x = arr[i];
            pair<int, int> p;
            if(st.empty()){
               p.first = arr[i];
               p.second = i;
               st.push(p); 
                continue;
            }

            while(!st.empty() && st.top().first > x){
                ans[st.top().second] = x;
                st.pop();
            }
            p.first = x;
            p.second = i;
            st.push(p);
        }
        
        return ans;
    } 
};

// { Driver Code Starts.

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
		int n;
		cin>>n;
		vector<int> array(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>array[i];
		}
		Solution obj;
		vector<int> result = obj.help_classmate(array,n);
		for (int i = 0; i < n; ++i)
		{
			cout<<result[i]<<" ";
		}
		cout<<"\n";
	}
	return 0; 
}

  // } Driver Code Ends