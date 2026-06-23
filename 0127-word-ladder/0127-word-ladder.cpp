class Solution {
public:
    int ladderLength(string begin, string end, vector<string>& words) {
        int n=words.size();
        queue<pair<string,int>> q;
        unordered_set<string> s(words.begin(),words.end());
        q.push({begin,1});
        s.erase(begin);
        while(!q.empty())
        {
            string word=q.front().first;
            int step=q.front().second;
            q.pop();
            if(word==end) return step;
            for(int i=0;i<word.size();i++)
            {
                char orig=word[i];
                for(char j='a';j<='z';j++)
                {
                    word[i]=j;
                    if(s.find(word)!=s.end())
                    {
                        q.push({word,step+1});
                        s.erase(word);
                    }
                }
                word[i]=orig;
            }
        }
        return 0;
        
    }
};