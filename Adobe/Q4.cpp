// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int n, int arr[])
    {
        // code here
        int sum = 0;
        for(int i = 0; i < n; i++)
            sum += arr[i];
        if(sum % 2 == 1)
            return 0;
            
        vector<vector<bool>> dp(n + 1,vector<bool> (sum + 1,false));
        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= sum; j++){
                if(j == 0)
                    dp[i][j] = true;
                else if(i == 0)
                    dp[i][j] = false;
                else{
                    if(j - arr[i - 1] >= 0)
                        dp[i][j] = dp[i][j] | dp[i - 1][j - arr[i - 1]];
                    dp[i][j] = dp[i][j] | dp[i - 1][j];
                }
            }
        int reqSum = sum / 2;
        return dp[n][reqSum] ? 1 : 0;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends