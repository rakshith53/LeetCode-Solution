/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

static auto x = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int maxDepth(Node* root) {
        if(!root)  return 0;
        int ans=0,n=root->children.size();
        for(int i=0;i<n;i++)
        {
            ans = max(ans,maxDepth(root->children[i]));
        }
        return ans+1;
    }
};
