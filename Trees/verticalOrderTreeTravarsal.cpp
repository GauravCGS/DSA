/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*,pair<int, int>>> q;
        map<int, map<int, multiset<int>>> m;
        q.push({root, {0, 0}});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            TreeNode* node = it.first;
            int x = it.second.first;
            int y = it.second.second;
            if(node->left) q.push({node->left, {x-1, y+1}});
            if(node->right) q.push({node->right, {x+1, y+1}});
            m[x][y].insert(node->val);
        }
        vector<vector<int>> res;
        for(auto it : m){
            vector<int> col;
            for(auto jt : it.second){
                col.insert(col.end(), jt.second.begin(), jt.second.end());
            }
            res.push_back(col);
        }
        return res;
    }
};
