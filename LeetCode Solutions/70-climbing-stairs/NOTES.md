memoization
​
```
class Solution {
public:
int fn(int index,int n,vector<int> &dp){
if(index > n) return 0;
if(index == n) return 1;
if(dp[index] != 0) return dp[index];
int ans = 0;
ans += fn(index+1,n,dp);
ans += fn(index+2,n,dp);
return dp[index] = ans;
}
int climbStairs(int n) {
vector<int> dp(n+1,0);
return fn(0,n,dp);
}
};
```