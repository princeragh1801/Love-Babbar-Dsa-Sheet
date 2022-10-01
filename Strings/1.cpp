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

// Approach - 1
// Take an Auxillary array
// Put all the elements in reverse order
// Again push back all the elements in original one

void reverseString(vector<char>& s) {
    vector<char> str;
    for(int i = s.size()-1; i >= 0; i--){
        str.push_back(s[i]);
    }
    for(int i = 0; i < s.size(); i++){
        s[i] = str[i];
    }
}

// Approach - 2
// Two pointer method
void reverseString(vector<char>& s) {
    int i = 0, j = s.size()-1;
    while(i<j){
        swap(s[i++], s[j--]);
    }
}

// Approach - 3
// Use in built function

void reverseString(vector<char>& s) {
    reverse(s.begin(), s.end());
}
int main()
{
  int t;
  cin>>t;
  while (t--)
  {
    int n;
    cin>>n;
    
  }
  
  return 0;
}
