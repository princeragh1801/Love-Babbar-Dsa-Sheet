// { Driver Code Starts
//Initial Template for C++
// Reverse an array

#include<bits/stdc++.h>
using namespace std;


string reverseWord(string str);


int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	string s;
	cin >> s;

	// Simple C++ Stl Function
	// reverse(s.begin(), s.end());
	// cout<<s<<endl;
	cout << reverseWord(s) << endl;
	}
	return 0;
	
}

// } Driver Code Ends


//User function Template for C++
// Time Complexity 0(n)
// Space Complexity 0(n)
string reverseWord(string str){
    
  //Your code here
  string str1;
  int i = str.length()-1;
  while(i >= 0){
	str1+=str[i];
	i--;
  }
  return str1;
}

// Optimised Approach
// Time complexity (logn)
// Same Approaches Can be done for Normal Array also
string reverseWord1(string str){
    
  //Your code here
  int i = 0;
  int j = str.length()-1;
  while(i <= j){
	swap(str[i], str[j]);
	i++;
	j--;
  }
  return str;
}