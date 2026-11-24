class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        stack<pair<int, int>> dfs;
        int maximumArea = 0;
        int currentArea = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    grid[i][j] = 2;
                    dfs.push({i,j});
                    currentArea++;
                }
                while(!dfs.empty()){
                    pair<int, int> top = dfs.top();
                    dfs.pop();
                    if((top.first - 1 != -1) and grid[top.first - 1][top.second] == 1){
                        grid[top.first - 1][top.second] = 2;
                        dfs.push({top.first - 1, top.second});
                        currentArea++;
                    }
                    if((top.second - 1 != -1) and grid[top.first][top.second - 1] == 1){
                        grid[top.first][top.second - 1] = 2;
                        dfs.push({top.first, top.second - 1});
                        currentArea++;
                    }
                    if((top.first + 1 != grid.size()) and grid[top.first + 1][top.second] == 1){
                        grid[top.first + 1][top.second] = 2;
                        dfs.push({top.first + 1, top.second});
                        currentArea++;
                    }
                    if((top.second + 1 != grid[0].size()) and grid[top.first][top.second + 1] == 1){
                        grid[top.first][top.second + 1] = 2;
                        dfs.push({top.first, top.second + 1});
                        currentArea++;
                    }
                }
                maximumArea = (maximumArea < currentArea) ? currentArea : maximumArea;
                currentArea = 0;
            }
        }
        return maximumArea;
    }
};
