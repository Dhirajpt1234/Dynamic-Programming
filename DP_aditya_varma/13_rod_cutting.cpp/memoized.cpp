#include <bits/stdc++.h>
using namespace std;

int main()    
{

    return 0;
}
// User function Template for C++

class Solution{
  public:
    int solve(vector<int> &len , int price[] , int l , int n ,  vector<vector<int>>& dp){
        
        if(l == 0 || n == 0 ) return 0;
        
        if(dp[n][l] != -1) return dp[n][l];
        if(len[n-1] <= l){
            return dp[n][l] = max(  price[n-1] + solve( len , price , l - len[n-1] , n , dp) ,
                        solve(len , price , l , n-1 ,dp)
                );
        }else{
            return dp[n][l] = solve(len , price , l , n-1 ,dp);
        }
           
    }
    
    int cutRod(int price[], int n) {
        //code here
        vector<int> len(n , 0);
        for(int i = 0 ; i < n ; i++) len[i] = i+1;
        
        vector<vector<int>> dp(n+1 , vector<int> (n+1 , -1));
        
        return solve(len , price , n , n , dp);
        
    }
};
