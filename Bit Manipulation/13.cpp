//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
        void allsub(string in, string &out, int ind, int n, vector<string> &res){
            if(ind == n){
                if(out.size() != 0){
                    res.push_back(out);
                }
                return;
            }

            // take
            out.push_back(in[ind]);
            allsub(in, out, ind+1, n, res);
            out.pop_back();

            // not take
            allsub(in, out, ind+1, n, res);
        }
		vector<string> AllPossibleStrings(string s){
		    // Code here
            int n = s.length();
            string out;
            vector<string> ans;
            allsub(s, out, 0, n, ans);
            sort(ans.begin(), ans.end());
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
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends