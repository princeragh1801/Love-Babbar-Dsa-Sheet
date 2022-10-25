//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:

        // Time complexity 0(n^2)
        // Space 0(26)
		string FirstNonRepeating1(string A){
		    
            unordered_map<char, int> st;
            string ans = "";
            int n = A.length();
            for(int i = 0; i < n; i++){
                st[A[i]]++;
                int flag = 0;
                for(int j = 0; j <= i; j++){
                    if(st[A[j]] == 1){
                        flag = 1;
                        ans+= A[j];
                        break;
                    }
                }
                if(flag == 0){
                    ans += '#';
                }
                
            }
            return ans;
            
		}


		string FirstNonRepeating(string A){
		    
            queue<char> q;
            int count[26] = {0};
            string ans = "";
            for(auto it : A){
                int x = it - 97;
                q.push(it);
                count[x]++;
                char c = q.front();
                x = c-97;
                if(count[x] == 1){
                    ans += c;
                }
                else{
                    while(!q.empty() && count[x] > 1){
                        q.pop();
                        c = q.front();
                        x = c-97;
                    }
                    if(q.empty()){
                        ans += '#';

                    }
                    else{
                        ans += c;
                    }
                }
            }
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
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends