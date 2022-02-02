int dp[100];
    int step(int n){
        if(n<=0)return 0;
        if(n==1)return 1;
        if(n==2)return 2;
        if(dp[n]!=-1)return dp[n];
        return dp[n] = step(n-1) + step(n-2);
    }
    int climbStairs(int n) {
        memset(dp, -1, sizeof(dp));
        return step(n);
    }
