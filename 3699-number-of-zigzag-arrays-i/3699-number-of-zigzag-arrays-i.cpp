class Solution {
public:
    long long M=1e9+7;

    int zigZagArrays(int n, int l, int r) {
        int m=r-l+1;
        
        if(m<2) return 0;
        vector<vector<int>> prev(m+1,vector<int>(2,0));
        vector<vector<int>> curr(m+1,vector<int>(2,0));
        for(int i=1;i<=m;i++)
        {
            prev[i][0]=i-1;
            prev[i][1]=m-i;
        }
        for(int i=3;i<=n;i++)
        {
            vector<long long> prefi(m+1,0);
            vector<long long> prefd(m+1,0);
            for(int j=1;j<=m;j++)
            {
                prefi[j]=(prefi[j-1]+prev[j][0])%M;
                prefd[j]=(prefd[j-1]+prev[j][1])%M;
            }
            for(int j=1;j<=m;j++)
            {
                curr[j][0]=prefd[j-1];
                curr[j][1]=(prefi[m]-prefi[j]+M)%M;
            }
            prev=curr;

        }
        long long ans=0;
        for(int i=1;i<=m;i++)
        {
            ans=(ans+prev[i][0]+prev[i][1])%M;

        }
        return (int)ans;


    }
};