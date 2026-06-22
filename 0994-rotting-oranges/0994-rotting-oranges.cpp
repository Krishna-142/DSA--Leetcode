class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        int vis[n][m];
        for(int r=0;r<n;r++)
        {
            for(int c=0;c<m;c++)
            {
                if(grid[r][c]==2)
                {
                    q.push({{r,c},0});
                    vis[r][c]=2;
                }
                else 
                {
                    vis[r][c]=0;
                }
            }
        }
        int delr[]={-1,0,1,0};
        int delc[]={0,-1,0,1};
        int tm=0;
        while(!q.empty())
        {
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            q.pop();
            tm=max(tm,t);
            for(int i=0;i<4;i++)
            {
                int nr=r+delr[i];
                int nc=c+delc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]!=2 && grid[nr][nc]==1)
                {
                    vis[nr][nc]=2;
                    q.push({{nr,nc},t+1});
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]!=2 && grid[i][j]==1)
                {
                    return -1;
                }
            }
        }
        return tm;
    }
};