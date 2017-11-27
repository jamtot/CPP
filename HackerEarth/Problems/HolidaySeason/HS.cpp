#include <iostream>
#include <string>
/*#include <vector>
#include <map>

Author: Jonathan Morris
	Holiday Season
	ttps ://www.hackerearth.com/practice/algorithms/searching/linear-search/practice-problems/algorithm/holiday-season-ab957deb/
*/

using namespace std;


int main()
{
	int n, count=0;
	std::cin >> n;
	std::string str;
	std::cin >> str;
	/*map<char, vector<int>> charCount;
	map<char, vector<int>>::iterator cIter;
	vector<char> keys;
	for (int i = 0; i < n; i++){
		char c = str[i];
		charCount[c].push_back(i);
		keys.push_back(c);
	}
	
	for (cIter = charCount.begin(); cIter != charCount.end(); cIter++) {
		cout << cIter->first << " = " << cIter->second.size() << endl;	
	}*/

	for (int a = 0; a < n; a++){
		for (int b = a + 1; b < n; b++) {
			for (int c = b + 1; c < n; c++) {
				for (int d = c + 1; d < n; d++) {
					if (str[a] == str[c] && str[b] == str[d])
						count++;
				}
			}
		}

	}
	std::cout << count;
	system("PAUSE");
	return 0;
}

