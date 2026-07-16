class Solution {
public:
    long long gcdl(long long a, long long b) { 
        while(b!=0)
            {
                long long r=a%b;
                a=b;
                b=r;
            }
        return a;
    }
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        long long tmp=nums[0];
        vector<long long> preg(n,0);
        for(int i=0;i<n;i++)
            {
                if(nums[i]>tmp) tmp=nums[i];
                preg[i]=gcdl((long long)nums[i],tmp);
            }
        sort(preg.begin(),preg.end());
        long long sm=0;
        for(int i=0;i<n/2;i++)
            {
                sm+=gcd(preg[i],preg[n-i-1]);
            }
        return sm;
    }
};