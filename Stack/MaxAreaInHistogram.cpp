vector<int> NLLi(vector<int> v){
    int n = v.size();
    vector<int> res;
    stack<int> s;
    for(int i = 0; i < n; i++){
        if(s.empty()){
            res.push_back(-1);
            s.push(i);
        }else{
            while(!s.empty() && v[i] <= v[s.top()]){
                s.pop();
            }
            if(s.empty()){
                res.push_back(-1);
            }else{
                res.push_back(s.top());
            }
            s.push(i);
        }
    }
    return res;
}

vector<int> NLRi(vector<int> v){
    int n = v.size();
    vector<int> res;
    stack<int> s;
    for(int i = n-1; i >= 0; i--){
        if(s.empty()){
            res.push_back(n);
            s.push(i);
        }else{
            while(!s.empty() && v[i] <= v[s.top()]){
                s.pop();
            }
            if(s.empty()){
                res.push_back(n);
            }else{
                res.push_back(s.top());
            }
            s.push(i);
        }
    }
    reverse(res.begin(),res.end());
    return res;
}
int maxAreaUnderHistogram(vector<int> v){
    int n = v.size();
    vector<int> gl = NLLi(v);
    vector<int> gr = NLRi(v);
    int area = v[0];
    for(int i = 0; i < n; i++){
        cout<<v[i]<<endl;
        int l = gr[i] - gl[i] - 1;
        cout<<"L : "<<l<<endl;
        area = max((l * v[i]),area);
        cout<<"Area : "<<area<<endl;
        cout<<"_________________________________________"<<endl;
    }
    return area;
}
