class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        unordered_map<char,int> hash={{'a',0},{'b',0},{'c',0}};
        int left=0,count=0;
        for(int i=0;i<n;i++)
        {
            hash[s[i]]++;
            while(hash['a'] && hash['b'] && hash['c'])
            {
                count+=(n-i);
                hash[s[left]]--;
                left++;
            }
        }
        return count;
    }
};