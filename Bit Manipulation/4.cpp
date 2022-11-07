//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:

    // all number occurs twice while only two numbers occurs one's
    // hashmap approach
    // time 0(n)
    // space 0(n)

    vector<int> singleNumber1(vector<int> nums) 
    {
        // Code here.
        vector<int> ans;
        map<int, int> mp;
        for(auto it : nums){
            mp[it]++;
        }
        for(auto it : mp){
            if(it.second == 1){
                ans.push_back(it.first);
            }
        }
        return ans;
    }


    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        vector<int> ans;
        int xxory = 0;
        for(auto it: nums){
            xxory = xxory^it;
        }

        int rmsbm = xxory & -xxory;
        int x = 0, y = 0;
        for(auto it : nums){
            if((rmsbm&it) == 0){
                x = x^it;
            }
            else{
                y = y^it;
            }
        }
        ans.push_back(min(x,y));
        ans.push_back(max(x, y));
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
      #ifndef ONLINE_JUDGE
       freopen("input.txt", "r", stdin);
       freopen("error.txt", "w", stderr);
       freopen("output.txt", "w", stdout);
       #endif
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends