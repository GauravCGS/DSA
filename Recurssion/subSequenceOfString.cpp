#include <bits/stdc++.h> 

void solve(string ip,int idx,string op,vector<string> &ans){
	if(ip.size() <= idx){
		ans.push_back(op);
		return;
	}
	string op1 = op; // include 
	string op2 = op; // exclude 
	op1.push_back(ip[idx]);
	solve(ip,idx+1,op1,ans);
	solve(ip,idx+1,op2,ans);
}
vector<string> subsequences(string str){
	
	// Write your code here
	vector<string> ans = {};
	solve(str,0,"",ans);
	return ans;
}
