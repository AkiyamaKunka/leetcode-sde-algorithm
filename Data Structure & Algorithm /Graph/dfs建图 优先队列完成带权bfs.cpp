/**
 * // This is the GridMaster's API interface.
 * // You should not implement it, or speculate about its implementation
 * class GridMaster {
 *   public:
 *     bool canMove(char direction);
 *     int move(char direction);
 *     boolean isTarget();
 * };
 */
class Solution {
    //https://leetcode-cn.com/problems/minimum-path-cost-in-a-hidden-grid/
    char nd[4] = {'U','D','L','R'};
    char anti_nd[4] = {'D', 'U', 'R', 'L'};
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};
    int map[200][200] = {0}; // with cost, 0 means blocked
    int tx, ty;
    bool find = false; // means the target exist
    void dfs(int x, int y, GridMaster& master){
        if(master.isTarget()){
            tx = x;
            ty = y;
            find = true;
        }
        for(int i = 0; i < 4; i++){
            int _x = x + dx[i];
            int _y = y + dy[i];
            if(master.canMove(nd[i]) && map[_x][_y] == 0){
                map[_x][_y] = master.move(nd[i]);
                dfs(_x, _y, master);
                master.move(anti_nd[i]);
            }
        }
    }
    class Node{
    public :
        int x;
        int y;
        int v;
        Node(){};
        Node(int _x, int _y, int _v){
            x = _x; y = _y; v = _v;
        }
    };
    struct CMP{
        bool operator () (Node& a, Node& b){
            return a.v > b.v; // decending, which means mimnum heap
        }
    };

public:
    int findShortestPath(GridMaster &master) {
        map[100][100] = 0;
        if(master.isTarget()) return 0;
        dfs(100, 100, master);
        if(!find) return -1;
        priority_queue<Node, vector<Node>, CMP> q;
        int vis[200][200] = {0}; // 0: not visited yet
        q.push(Node(100, 100, 0));
        vis[100][100] = 1; // visit the start point
        while(!q.empty()){
            Node node = q.top();
            q.pop();
            for(int i = 0; i < 4; i++){
                int _x = node.x + dx[i];
                int _y = node.y + dy[i];
                if(_x < 0 || _y < 0 || _x >= 200 || _y >= 200 || vis[_x][_y] || !map[_x][_y] )
                    continue;
                if(_x == tx && _y == ty){
                    return node.v + map[_x][_y];
                }
                vis[_x][_y] = 1;
                q.push(Node(_x, _y, node.v + map[_x][_y]));
            }
        }
        return 0;
    }
};