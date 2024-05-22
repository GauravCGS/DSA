class Solution {
  public:
    
    void solve(Node* node,vector<vector<int>> &res,vector<int>v){
        if(!node) return;
        if(!node->left && !node->right){
            v.push_back(node->data);
            res.push_back(v);
            int s = v.size()-1;
            v.erase(v.begin()+s);
            return;
        }
        v.push_back(node->data);
        solve(node->left,res,v);
        solve(node->right,res,v);
    }
    
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<vector<int>>res;
        vector<int> v;
        solve(root, res, v);
        return res;
    }
};
