class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& wts) {
        int n=words.size();
        string ans="";
        for(int i=0;i<n;i++)
        {
            int x=0;
            for(char c:words[i])
            {
                x+=wts[c-'a'];
            }
            x=x%26;
            ans+=('a'+(26-1-x));
        }
        return ans;
    }
};