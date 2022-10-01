#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i, a, b) for(ll int i = a; i < b; i++)
#define mod 1000000007
#define pb push_back
#define fi first
#define se second
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl


// Brute force Approach
// Check for all possible pairs
// Max value return at the end
// Time Complexity 0(n^2)
int maxProfit1(vector<int> &prices){
    int maxP = 0;
    int n = prices.size();
    for(int i = 0; i < n-1; i++){
        for(int j = i+1;j < n; j++){
            if(prices[j]-prices[i] > maxP){
                maxP = prices[j]-prices[i];
            }
        }
    }
    return maxP;
}

// Best Approach to solve the problem
// Time Complexity o(n)
// Create 2 variables 
// maxP = 0, cp(costPrice) = prices[0]
// Iterate and comare 
// If we get a value less than or equal to current cp, update cp
// Else update maxP = max(maxP, prices[i]-cp) 
int maxProfit(vector<int> &prices){
    int maxP = 0;
    int n = prices.size();
    int cp = prices[0];
    for(int i = 1; i < n; i++){
        if(prices[i] <= cp){
            cp = prices[i];
        }
        else{
            maxP = max(maxP, prices[i]-cp);
        }
        
    }
    return maxP;
}
int main()
{
  int t;
  cin>>t;
  while (t--)
  {
    int n;
    cin>>n;
    vector<int> prices;
    fo(i,0,n){
        int x;
        cin>>x;
        prices.pb(x);
    }
  }
  
  return 0;
}
