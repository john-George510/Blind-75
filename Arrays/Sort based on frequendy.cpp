#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

int main(){
	vector<int> arr = {3,4,4,4,4,5,5,5,2,2,2};
	unordered_map<int, int> freq;
	vector<pair<int, int>> freqArr;
	for(int i = 0; i < arr.size(); i++){
		freq[arr[i]]++;
	}

	printf("map: ");
	for(auto it = freq.begin(); it != freq.end(); it++){
		cout << it->first << " " << it->second << endl;
	}

	for(auto it = freq.begin(); it != freq.end(); it++){
		freqArr.push_back({it->first, it->second});
	}
	
	sort(freqArr.begin(), freqArr.end(), [](pair<int, int> a, pair<int, int> b){
		if(a.second == b.second){
			return a.first < b.first;
		}
		return a.second > b.second;
	});

	printf("Sorted based on frequency: ");
	for(int i = 0; i < freqArr.size(); i++){
		for(int j = 0; j < freqArr[i].second; j++){
			cout << freqArr[i].first << " ";
		}
	}

	cout << true * 5 << endl;




	return 0;
}