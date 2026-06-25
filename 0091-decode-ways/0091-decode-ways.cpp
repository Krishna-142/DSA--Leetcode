class Solution {
public:
    int solve(int i,string s,int n,vector<int> &dp)
    {
        if(i>=n)
        {
            return 1;
        }
        int x=0;
        if(dp[i]!=-1) return dp[i];
        if(s[i]=='0') return 0;
        if(i<n-1)
        {
            int nxt=10*(s[i]-'0')+(s[i+1]-'0');
            if(nxt>=10 && nxt<=26)
            {
                x+=solve(i+2,s,n,dp);
            }
        }
        x+=solve(i+1,s,n,dp);
        return dp[i]=x;


    }
    int numDecodings(string s) {
        int n=s.size();
        vector<int> dp(n,-1);
        return solve(0,s,n,dp);

    }
};