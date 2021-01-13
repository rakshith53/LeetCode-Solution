class Solution {
public:
    struct TrieNode{
        vector<TrieNode*> child;
        TrieNode(){
            child.resize(2,NULL);
        }
    };
    TrieNode* root = new TrieNode();
    void build(vector<int>& nums){
        TrieNode* cur;
        int ind;
        for(int tmp:nums){
            cur = root;
            for(int i=31;i>=0;i--){
                ind = ((tmp >> i) & 1);
                if(!cur->child[ind]) cur->child[ind] = new TrieNode();
                cur = cur->child[ind];
            }
        }
    }
    int help(vector<int>& nums){
        TrieNode* cur;
        int ans = INT_MIN, res, ind;
        for(int tmp:nums){
            res = 0;
            cur = root;
            for(int i=31;i>=0;i--){
                ind = ((tmp >> i) & 1) ? 0 : 1;
                if(cur->child[ind]){
                    res<<=1;
                    res|=1;
                    cur = cur->child[ind];
                }
                else{
                    res<<=1;
                    res|=0;
                    cur = cur->child[!ind];
                }
            }
            ans = max(ans,res);
        }
        return ans;
    }
    int findMaximumXOR(vector<int>& nums){
        build(nums);
        return help(nums);
    }
};
