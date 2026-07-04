class Solution {
public:
    
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto &ed: roads)
        {
            int u=ed[0];
            int v=ed[1];
            int dis=ed[2];
            adj[u].push_back({v,dis});
            adj[v].push_back({u,dis});
        }
        vector<int> vis(n+1,0);
        queue<int> q;
        q.push(1);
        vis[1]=1;
        int ans=INT_MAX;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto &it:adj[node])
            {
                int ngbr=it.first;
                int dis=it.second;
                ans=min(ans,dis);
                if(!vis[ngbr])
                {
                    vis[ngbr]=1;
                    q.push(ngbr);
                }
            }
        }
        return ans;
        
    }
};