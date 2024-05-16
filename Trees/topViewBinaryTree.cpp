class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    void solve(Node *node,int x, map<int, int> &m){
        queue<pair<Node*, int>>q;
        q.push({node,x});
        int min = 0, max = 0;
        while(!q.empty()){
            Node* n = q.front().first;
            if(n->left){
                int   x = q.front().second;
                x = x - 1;
                q.push({n->left,x});
                // int y = y - 1;
                if(x < min) m.insert({x,n->left->data});
                min = x < min ? x : min;
                max = x > max ? x : max;
            }
            if(n->right){
                int   x = q.front().second;
                x = x + 1;
                q.push({n->right,x});
                // int y = y + 1;
                if(x > max) m.insert({x,n->right->data});
                min = x < min ? x : min;
                max = x > max ? x : max;
            }
            q.pop();
        }
        // cout<<min<<" : "<<max;
    }
    
    vector<int> topView(Node *root)
    {
        //Your code here
        vector<int>res;
        map<int, int> m;
        m.insert({0,root->data});
        // res.push_back(root->data);
        solve(root,0,m);
        for(auto i : m){
            res.push_back(i.second);
        }
        return res;
    }

};


//approach 2
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    void solve(Node *node,int x, map<int, int> &m){
        queue<pair<Node*, int>>q;
        q.push({node,x});
        int min = 0, max = 0;
        while(!q.empty()){
            Node* n = q.front().first;
            int hd = q.front().second;
            if(!m[hd]){
                m[hd] = n->data;
            }
            if(n->left){
                q.push({n->left,hd-1});
            }
            if(n->right){
                q.push({n->right,hd+1});
            }
            q.pop();
        }
        // cout<<min<<" : "<<max;
    }
    
    vector<int> topView(Node *root)
    {
        //Your code here
        vector<int>res;
        map<int, int> m;
        // m.insert({0,root->data});
        // res.push_back(root->data);
        solve(root,0,m);
        for(auto i : m){
            res.push_back(i.second);
        }
        return res;
    }

};
