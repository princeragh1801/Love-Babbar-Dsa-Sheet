//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:

    // approach 1 
    // basically we are substracting dividend by divisor every time until it becomes less than divisor
    long long divide1(long long dividend, long long divisor) 
    {
        //code here
        long long ans = 0;
        int sign = 1;
        // here we are calculating the sign
        if(dividend > 0 && divisor < 0){
            sign = -1;
        }
        else if(dividend < 0 && divisor > 0){
            sign = -1;
        }

        // making both of them positive
        dividend = abs(dividend);
        divisor = abs(divisor);

        // here substracting with divisor
        // and increasing our ans by one each time 
        // at last we get our desired result
        while(dividend >= divisor){
            dividend -= divisor;
            ans++;
        }
        return ans*sign;
    }
    long long divide(long long dividend, long long divisor) 
    {
        //code here

        int sign = 1;
        // here we are calculating the sign
        
        if(dividend > 0 && divisor < 0){
            sign = -1;
        }
        else if(dividend < 0 && divisor > 0){
            sign = -1;
        }
      
        // making both of them positive
        dividend = abs(dividend);
        divisor = abs(divisor);
        if(divisor == 1){
            return dividend*sign;
        }
        
        long long quotient = 0, temp = 0;
        
        // test down from the highest bit and
        // accumulate the tentative value for
        // valid bit
        for (int i = 31; i >= 0; --i) {
        
            if (temp + (divisor << i) <= dividend) {
                temp += divisor << i;
                quotient |= 1LL << i;
            }
        }
        return quotient*sign;
    }
};

//{ Driver Code Starts.
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
      #ifndef ONLINE_JUDGE
       freopen("input.txt", "r", stdin);
       freopen("error.txt", "w", stderr);
       freopen("output.txt", "w", stdout);
       #endif
	int t;
	cin >> t;

	while (t--)
	{

		long long a, b;
		cin >> a >> b;
		
		Solution ob;
		cout << ob.divide(a, b) << "\n";
	}

	return 0;
}

// } Driver Code Ends