// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Approach - 1
    int smallestSubWithSum(int arr[], int n, int x)
    {
        // Your code goes here
        int minLength = n + 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                int s = 0;
                for (int k = i; k <= j; k++)
                {
                    s += arr[k];
                }
                if (s > x)
                {
                    minLength = min(minLength, j - i + 1);
                }
            }
        }
        return minLength;
    }

    // Approach -2
    int smallestSubWithSum(int arr[], int n, int x)
    {
        // Your code goes here
        int minLength = n + 1;
        for (int i = 0; i < n; i++)
        {
            int s = 0;
            for (int j = i; j < n; j++)
            {
                s += arr[j];
                if (s > x)
                {
                    minLength = min(minLength, j - i + 1);
                }
            }
        }
        return minLength;
    }

    // Approach - 3
    int smallestSubWithSum(int arr[], int n, int x)
    {
        // Your code goes here
        int minLength = n + 1, i = 0;
        int currSum = 0;
        int low = 0;
        while(i < n)
        {
            currSum += arr[i];
            if(currSum > x){
                minLength = min(minLength, (i - low));
                while(currSum > x){
                    currSum -= arr[low++];
                    minLength = min(minLength, (i - low));
                }
            }
            i++;
        }
        return minLength;
    }
};

// { Driver Code Starts.

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        cout << obj.smallestSubWithSum(a, n, x) << endl;
    }
    return 0;
} // } Driver Code Ends