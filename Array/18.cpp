#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i, a, b) for (ll int i = a; i < b; i++)
#define mod 1000000007
#define pb push_back
#define fi first
#define se second
#define yes cout << "YES" << endl
#define no cout << "NO" << endl

// int isSorted(vector<int> arr){
//     for(int i = 0; i < arr.size()-1; i++){
//         if(arr[i+1] > arr[i]){
//             return 0;
//         }
//     }
//     return 1;
// }
// void nextPermutation(vector<int>& nums) {
//     if(isSorted(nums)){reverse(nums.begin(), nums.end()); return;}

//     int currMax = 0;
//     int in = 0;
//     for(int i = nums.size()-1; i > 0; i--){
//         int x = nums[i];
//         for(int j = i-1; j >= 0; j--){
//             if(nums[j] < x && j >= currMax){
//                 currMax = j;
//                 in = i;
//                 break;
//             }
//         }
//     }
//     swap(nums[currMax], nums[in]);
//     reverse(nums.begin()+currMax+1, nums.end());
// }

void nextPermutation(vector<int> &nums)
{
    next_permutation(nums.begin(), nums.end());
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
    }

    return 0;
}
