#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i, a, b) for(ll int i = a; i < b; i++)
#define mod 1000000007
#define beg(x) x.begin(), x.end()
#define pb push_back
#define fi first
#define se second
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

// Approach 1
// sort and check
void dupli1(string str){
    sort(str.begin(), str.end());
    string ans= "";
    char prev;
    for(int i = 0; i < str.length()-1; i++){
        if(str[i] == str[i+1] && str[i] != prev){
            cout<<str[i]<<" ";
            prev = str[i];
        }
    }
    cout<<endl;
   
}

// Approach - 2

void dupli(string str){
    unordered_map<char, int> m;
    for(int i = 0; i < str.length(); i++){
        m[str[i]]++;
    }
    for(auto it : m){
        if(it.second >= 2){
            cout<<it.first<<" ";
        }
    }
    cout<<endl;
}
int main()
{
  int t;
  cin>>t;
  while (t--)
  {
    string str;
    cin>>str;
    dupli(str);
    
  }
  
  return 0;
}
