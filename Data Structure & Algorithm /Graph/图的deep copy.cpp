class Solution {
    // 大无语事件
    // 这道题真的让我无语子
    // dfs搜 但是没想到还能这么玩
    // https://leetcode-cn.com/problems/clone-graph/submissions/
    class Node {
    public:
        int val;
        vector<Node*> neighbors;
        Node() {
            val = 0;
            neighbors = vector<Node*>();
        }
        Node(int _val) {
            val = _val;
            neighbors = vector<Node*>();
        }
        Node(int _val, vector<Node*> _neighbors) {
            val = _val;
            neighbors = _neighbors;
        }
    };
public:
    unordered_map<Node*, Node*> visited; // map实现hashmap
    Node* cloneGraph(Node* node) {
        if(node == nullptr)
            return node;
        if(visited.find(node) != visited.end()){ // which means the node is found
            return visited[node];
        }

        Node* clone_node = new Node(node->val);
        visited[node] = clone_node;
        for(auto& neighbor : node->neighbors){
            clone_node->neighbors.emplace_back(cloneGraph(neighbor)); // 这个操作等同于vector下的push_back()
        }
        return clone_node;
    }
};
