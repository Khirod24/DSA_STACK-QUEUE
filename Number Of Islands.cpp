//LEETCODE(200)
void bfs(int row, int col, vector<vector<int>>&visited, vector<vector<char>>&grid){
        int n= grid.size(); //rows
        int m= grid[0].size(); //cols
        queue<pair<int,int>>q;
        visited[row][col]=1;
        q.push({row,col});
        while(!q.empty()){
            int row= q.front().first;
            int col= q.front().second;
            q.pop();
            //traversing neighbours and mark them as land i.e. "1"
            for(int delrow= -1; delrow<=1; delrow++){
                int newrow = row + delrow;
                int newcol = col;
                if(newrow>=0 && newrow<n && newcol>=0 && newcol<m && grid[newrow][newcol]=='1' && !visited[newrow][newcol]){
                        visited[newrow][newcol]=1;
                        q.push({newrow,newcol});
                    }
                }
            for(int delcol=-1; delcol<=1; delcol++){
                int newrow= row;
                int newcol=col+delcol;
                if(newrow>=0 && newrow<n && newcol>=0 && newcol<m && grid[newrow][newcol]=='1' && !visited[newrow][newcol]){
                        visited[newrow][newcol]=1;
                        q.push({newrow,newcol});
                    }
            }
            
            }
            
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n= grid.size(); //rows
        int m= grid[0].size(); //cols
        int count=0;
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int row=0; row<n; row++){
            for(int col=0; col<m; col++){
                if(!visited[row][col] && grid[row][col]=='1'){
                    count++;
                    bfs(row,col,visited,grid);
                }
            }
        }
        return count;
    }

//CODING NINJA
#include <bits/stdc++.h> 
void bfs(int row, int col, vector<vector<int>>&visited, vector<vector<int>>&grid){
        int n= grid.size(); //rows
        int m= grid[0].size(); //cols
        queue<pair<int,int>>q;
        visited[row][col]=1;
        q.push({row,col});
        while(!q.empty()){
            int row= q.front().first;
            int col= q.front().second;
            q.pop();
            //traversing neighbours and mark them as land i.e. "1"
            for(int delrow=-1; delrow<=1; delrow++){
                for(int delcol = -1; delcol<=1; delcol++){
                    int newrow = row + delrow;
                    int newcol = col + delcol;
                    if(newrow>=0 && newrow<n && newcol>=0 && newcol<m && grid[newrow][newcol]==1 && !visited[newrow][newcol]){
                        visited[newrow][newcol]=1;
                        q.push({newrow,newcol});
                    }
                }
            }
        }
    }
    

int numberOfIslands(vector<vector<int>>& grid, int n, int m)
{
    int count=0;
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int row=0; row<n; row++){
            for(int col=0; col<m; col++){
                if(!visited[row][col] && grid[row][col]==1){
                    count++;
                    bfs(row,col,visited,grid);
                }
            }
        }
        return count;

}
