class Solution {
public:
    unordered_map<string,int> mpp;
    vector<vector<string>> ans;
    void dfs(string aa,vector<string>& seq,string b)
    {
        if(aa==b)
        {
            ans.push_back(vector<string>(seq.rbegin(), seq.rend()));
            return;
        }
        int stp=mpp[aa];
        for(int i=0;i<aa.size();i++)
            {
                char orig=aa[i];
                for(char j='a';j<='z';j++)
                {
                    aa[i]=j;
                    if(mpp.find(aa)!=mpp.end() && mpp[aa]==stp-1)
                    {
                        seq.push_back(aa);
                        dfs(aa,seq,b);
                        seq.pop_back();
                    }
                }
                aa[i]=orig;
            }
        return ;

    }
    vector<vector<string>> findLadders(string begin, string end, vector<string>& words) {
        
        queue<string> q;
        unordered_set<string> s(words.begin(),words.end());
        q.push({begin});
        mpp[begin]=1;
        int n=begin.size();
        s.erase(begin);
        while(!q.empty())
        {
            string word=q.front();
            q.pop();
            int stp=mpp[word];
            for(int i=0;i<n;i++)
            {
                char orig=word[i];
                for(char j='a';j<='z';j++)
                {
                    word[i]=j;
                    if(s.count(word))
                    {
                        q.push({word});
                        mpp[word]=stp+1;
                        s.erase(word);
                    }
                }
                word[i]=orig;
            }
        }
        if(mpp.find(end)!=mpp.end())
        {
            vector<string> sq;
            sq.push_back(end);
            dfs(end,sq,begin);
        }
        return ans;
    }
};