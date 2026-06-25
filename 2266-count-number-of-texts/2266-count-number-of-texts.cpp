class Solution {
public:
int mod=1e9+7;

    int countTexts(string keys) {
       vector<int>dp(keys.size()+1,-1);
        int n=keys.size();
        dp[n]=1;
        dp[n-1]=1;
        for(int j=n-1;j>=0;j--)
        {
            string temp="";
            char st=keys[j];
            int sum=0;
            int add=0;
            for(int i=j;i<keys.length();i++)
            {
                if(keys[i]==st&&(sum<3||((st=='9'||st=='7')&&sum<4)))
                {
                    sum++;
                    temp+=keys[i];
                    add=(add+dp[i+1])%mod;
                }
                else
                break;
            }
            dp[j]=add;
        }
        return dp[0];
    }
};