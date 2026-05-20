#include<bits/stdc++.h>
using namespace std; 

class Solution {
public:
    int ladderLength(string begin, string end, vector<string>& dict) {
    
    unordered_set<string> set(dict.begin(), dict.end());
	queue<pair<string,int>> q;

	// init
	q.push({begin, 1});
	set.erase(begin);

	while(!q.empty()){
		auto [word, steps] = q.front();
		q.pop();

		if(word == end) return steps;

		for(int i=0; i<word.size(); i++){
			char org = word[i];

			for(char ch = 'a'; ch <= 'z'; ch++){
				word[i] = ch;

				if(set.find(word) != set.end()){
					q.push({word, steps+1});
					set.erase(word);
				}
			}

			// back to org
			word[i] = org;
		}
	}

	return 0; 
    }
};
