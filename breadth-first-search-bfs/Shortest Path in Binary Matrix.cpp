#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // Edge case: start or end cell is blocked
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return -1;
        }
        
        // Queue stores pair of {path_length, {row, col}}
        queue<pair<int, pair<int, int>>> q;
        q.push({1, {0, 0}});
        grid[0][0] = 1; // Mark start cell as visited
        
        // 8 possible directions for movement
        int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        
        while (!q.empty()) {
            auto [dist, cell] = q.front();
            q.pop();
            int r = cell.first;
            int c = cell.second;
            
            // Reached the bottom-right corner
            if (r == n - 1 && c == n - 1) {
                return dist;
            }
            
            for (int i = 0; i < 8; ++i) {
                int nr = r + dx[i];
                int nc = c + dy[i];
                
                // Check boundaries and if cell is empty (0)
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0) {
                    grid[nr][nc] = 1; // Mark as visited
                    q.push({dist + 1, {nr, nc}});
                }
            }
        }
        return -1;
    }
};
