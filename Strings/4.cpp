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

int checkRotation1(string str1, string str2){
    str1 += str1;
    int flag = 0;
    int y = 0;
    fo(i,0,str1.length()){
      if(str1[i] == str2[y]){
        y++;
        if(y == str2.length()){
          return 1;
        }
      }
      else{
        y = 0;
      }
    }
    
    return 0;
}


int checkRotation(string str1, string str2){
  if(str1.length() != str2.length()){
    return 0;
  }
  string temp = str1+str1;
    
  return (temp.find(str2) != string::npos);
    
}
int main()
{
  
    string str1, str2;
    str1 = "ABACD";
    str2 = "CDABA";
    //str1+=str1;
    //cout<<str1<<endl;
    cout<<checkRotation(str1, str2)<<endl;
  
  return 0;
}
