class Solution {
public:
    typedef pair<long long,int> P;
    bool check(int m,long long k,int n,unordered_map<int,vector<pair<int,int>>>& adj)
    {
        vector<long long> res(n,LLONG_MAX);
        priority_queue<P,vector<P>,greater<P>> pq;
        res[0]=0;
        pq.push({0,0});
        while(!pq.empty())
        {
            long long d=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(d>k) return false;
            if(node==n-1) return true;
            if(res[node]<d) continue;
            for(auto &v:adj[node])
            {
                int ngbr=v.first;
                int cst=v.second;
                if(cst<m) continue;
                if(d+cst<res[ngbr])
                {
                    res[ngbr]=d+cst;
                    pq.push({d+cst,ngbr});
                }
            }
        }
        return false;

    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n=online.size();
        unordered_map<int,vector<pair<int,int>>> adj;
        int l=INT_MAX,r=0;

        for(auto ed:edges)
        {
            int u=ed[0];
            int v=ed[1];
            int cst=ed[2];
            
            if(!online[u] || !online[v]) continue;
            adj[u].push_back({v,cst}); 
            l=min(l,cst);
            r=max(r,cst);
        }
        int ans=-1;
        while(l<=r)
        {
            int m=l+(r-l)/2;
            if(check(m,k,n,adj))
            {
                ans=m;
                l=m+1;

            }
            else
            {
                r=m-1;
            }
        }
        return ans;

    }
};