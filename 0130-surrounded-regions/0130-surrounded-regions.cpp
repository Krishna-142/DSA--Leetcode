class Solution {
public: 
    void dfs(int i,int j,vector<vector<int>>& vis,vector<vector<char>>& board,int n,int m)
    {
        vis[i][j]=1;
        int dx[]={-1,0,1,0};
        int dy[]={0,-1,0,1};
        {
            for(int k=0;k<4;k++)
            {
                int nx=i+dx[k];
                int ny=j+dy[k];
                if(nx>=0 && nx<n && ny>=0 && ny<m && board[nx][ny]=='O' && !vis[nx][ny])
                {
                    dfs(nx,ny,vis,board,n,m);
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            if(!vis[i][0] && board[i][0]=='O')
            {
                 dfs(i,0,vis,board,n,m);
            }
            if(!vis[i][m-1] && board[i][m-1]=='O')
            {
                 dfs(i,m-1,vis,board,n,m);
            }
        }
        for(int j=0;j<m;j++)
        {
            if(!vis[0][j] && board[0][j]=='O')
            {
                 dfs(0,j,vis,board,n,m);
            }
            if(!vis[n-1][j] && board[n-1][j]=='O')
            {
                 dfs(n-1,j,vis,board,n,m);
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && board[i][j]=='O')
                {
                    board[i][j]='X';
                }
            }
        }
    }
};