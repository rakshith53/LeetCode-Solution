/*
// Definition for a Node.
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
*/

class Solution {
public:
    unordered_map<Node*,Node*> m;
    Node* cloneGraph(Node* node) {
    
        //bfs---------------------------------------------
        // if(!node) return node;
        // queue<Node*> q;
        // q.push(node);
        // m[node] = new Node(node->val);;
        // Node* cur;
        // while(!q.empty()){
        //     cur = q.front();
        //     q.pop();
        //     for(Node* n:cur->neighbors){
        //         if(m.find(n)==m.end()){
        //             m[n] = new Node(n->val);
        //             q.push(n);
        //         }
        //         m[cur]->neighbors.push_back(m[n]);
        //     }
        // }
        // return m[node];
        
        
        
        //dfs--------------------------------------------------
        if(!node) return NULL;
        if(m.find(node)!=m.end()) return m[node];
        m[node] = new Node(node->val);
        for(Node* i:node->neighbors) 
            m[node]->neighbors.push_back(cloneGraph(i));
        return m[node];
    }
};
