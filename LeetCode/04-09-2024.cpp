// Walking Robot Simulation
class Solution {
public:
Solution()
    {
        ios_base::sync_with_stdio(false); 
        cin.tie(NULL); 
        cout.tie(NULL);
        
    }
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string> obstacleSet;
        for (auto& obstacle : obstacles) {
            obstacleSet.insert(to_string(obstacle[0]) + "," + to_string(obstacle[1]));
        }

        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // North, East, South, West
        int x = 0, y = 0, dir = 0, maxDist = 0;
        
        for (int command : commands) {
            if (command == -1) { // Turn right
                dir = (dir + 1) % 4;
            } else if (command == -2) { // Turn left
                dir = (dir + 3) % 4;
            } else { // Move forward
                for (int step = 0; step < command; ++step) {
                    int nx = x + directions[dir][0];
                    int ny = y + directions[dir][1];
                    if (obstacleSet.find(to_string(nx) + "," + to_string(ny)) == obstacleSet.end()) {
                        x = nx;
                        y = ny;
                        maxDist = max(maxDist, x * x + y * y);
                    } else {
                        break;
                    }
                }
            }
        }

        return maxDist;
    }
};
