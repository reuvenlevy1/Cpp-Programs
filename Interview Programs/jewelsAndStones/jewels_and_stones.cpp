/* 771.	Jewels and Stones
* https://leetcode.com/problems/jewels-and-stones/
* 
* @author Reuven
*/

#include <iostream>

class Solution {
public:
	int numJewelsInStones(std::string J, std::string S) {
		int i, j, count = 0;
		std::cout << "Input: J = " << J << ", S = " << S << "\n";
		
		//Loop through characters found in J
		for (i = 0; i < (int)J.size(); ++i) {
			
			//Loop through characters in S and count the matches found
			for (j = 0; j < (int)S.size(); ++j) {
				if (J[i] == S[j]) {
					++count;
				}
			}
		}
		return count;
	}
};

int main() {
	Solution sol;
	auto answer = sol.numJewelsInStones("aA", "aAAbbbb");
	std::cout << "Output: " << answer << "\n\n";
	
	auto answer2 = sol.numJewelsInStones("z", "ZZ");
	std::cout << "Output: " << answer2 << "\n";
}

![program-execution](images/output.png)
