class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n=word.size();
        // set<char> s;
        int cnt=0;
        vector<int> v(26,0);

        for(auto &it:word)
        {
            if(it>='a' && it<='z')
            {
                // s.insert(it);
                if(v[it-'a']==2) v[it-'a']=-1;
                else if(v[it-'a']==-1) continue;
                else v[it-'a']=1;
            }
            else if(it>='A' && it<='Z')
            {
                if(v[it-'A']==1)
                {
                    v[it-'A']=2;
                }
                else if(v[it-'A']==0)
                {
                    v[it-'A']=-1;
                }
            }
        }
        for(int i=0;i<26;i++)
            cnt+=(v[i]==2)?1:0;
        return cnt;
    }
};