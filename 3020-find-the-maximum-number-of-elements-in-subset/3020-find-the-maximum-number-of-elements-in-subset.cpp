class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n=nums.size();
        int ind=0;
        sort(nums.begin(),nums.end());
        for(int i:nums)
        {
            if(i==1) ind++;
            else break;
        }
        int ans=1;
        if(ind&1) ans=ind;
        else
        {
            ans=max(ans,ind-1);
        }
        map<long long,int> mpp;
        for(int i=ind;i<n;i++)
        {
            mpp[nums[i]]++;
        }
        for(auto it:mpp)
        {
            long long x=it.first;
            int tmp=1;
            while(mpp[x]>=2 && mpp.find(x*x)!=mpp.end())
            {
                tmp+=2;
                x=x*x;
            }
            ans=max(tmp,ans);
        }
        return ans;

    }
};