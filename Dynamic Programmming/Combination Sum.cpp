#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void backtrack(vector<int> &candidates, int target, vector<vector<int>> &ans, vector<int> &temp, int start)
{
	if (target < 0)
	{
		return;
	}
	if (target == 0)
	{
		ans.push_back(temp);
		return;
	}
	for (int i = start; i < candidates.size(); i++)
	{
		temp.push_back(candidates[i]);
		backtrack(candidates, target - candidates[i], ans, temp, i);
		temp.pop_back();
	}
	return;
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
	//backtracking
	vector<vector<int>> ans;
	vector<int> temp;
	sort(candidates.begin(), candidates.end());
	backtrack(candidates, target, ans, temp, 0);
	return ans;


	// vector<vector<vector<int>>> ans(target + 1);
	// ans[0].push_back({});

	// for (int i = 1;i<=target;i++){
	// 	for (int num: candidates){
	// 		if (i - num >= 0){
	// 			int len = ans[i-num].size();
	// 			for (int j = 0;j<len;j++){
	// 				vector<int> temp(ans[i-num][j]);
	// 				temp.push_back(num);
	// 				sort(temp.begin(), temp.end());
	// 				//Check if the combination is already present
	// 				if (find(ans[i].begin(), ans[i].end(), temp) == ans[i].end()){
	// 					ans[i].push_back(temp);
	// 				}
	// 			}
	// 		}
	// 	}
	// }
	// return ans[target];

}

int main()
{
	vector<int> candidates = {2, 3, 6, 7};
	int target = 7;
	vector<vector<int>> ans = combinationSum(candidates, target);
	printf("ans: ");
	for (vector<int> v : ans)
	{
		for (int i : v)
		{
			cout << i << " ";
		}
		cout << endl;
	}
	return 0;
}