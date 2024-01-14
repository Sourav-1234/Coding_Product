#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

  int dfs(int i,int j,int n,int m,vector<vector<int>> &grid){
      if(i>=0 && i<n && j>=0 && j<m && grid[i][j]==1){
          //marking the states so that we dont have to maintain the visited array.
          grid[i][j]=0;

          //i+1 for the down side of  grid.
          //i-1 for the up  side of the  grid.
          //j-1 to travel left side of the grid.
          //j+1 to travel right side of the grid.
          //Time Complexity T(n)=O(n*n)
          //Space Complexity=O(1)

          return 1+
          dfs(i+1,j,n,m,grid) +dfs(i-1,j,n,m,grid) +dfs(i,j+1,n,m,grid)+dfs(i,j-1,n,m,grid);
      }
      else{
          return 0;
      }
  }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                   area=max(area,dfs(i,j,n,m,grid));
                }
            }
        }
        return area;
    }
};

int main(){
    Solution sol = Solution();

    sol.maxAreaOfIsland({{0,0,1,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,1,1,0,1,0,0,0,0,0,0,0,0},{0,1,0,0,1,1,0,0,1,0,1,0,0},{0,1,0,0,1,1,0,0,1,1,1,0,0},{0,0,0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,0,0,0,0,0,0,1,1,0,0,0,0}});
    return 0;
}