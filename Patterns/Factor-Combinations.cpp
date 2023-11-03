// https://www.codingninjas.com/studio/problems/factor-combinations_1232628?leftPanelTabValue=PROBLEM

#include <bits/stdc++.h>

void dfs(int n, int div, vector<int>& curr, vector<vector<int>>& result) {
	if(1 == n && curr.size() > 1) {
		result.push_back(curr);
		return;
	}

	do{
		if(0 == n % div) {
			curr.push_back(div);
			dfs(n / div, div, curr, result);
			curr.pop_back();
		}
	}while(++div <= n);
}

// TC: O(N^logN)
// SC: O(logN)
vector<vector<int>> factorCombinations(int n) {
	vector<vector<int>> result;
	vector<int> curr;
	dfs(n, 2, curr, result);
	return result;
}
