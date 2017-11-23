//author Jonathan Morris
/* 
https://www.hackerearth.com/practice/algorithms/searching/linear-search/practice-problems/algorithm/square-transaction-20/
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int t,q;
	string input;

	cin >> t;

	// a vector to take t daily transaction amounts
	vector<int> trans;
	vector<int>::iterator transIter;
	int x, sum=0;
	for (int i = 0; i < t; i++)
	{// sums the daily transactions as it goes
		cin >> x;
		sum += x;
		trans.push_back(sum);
	}

	cin >> q;

	//a vector to take in q queries
	vector<int> queries;
	vector<int>::iterator qIt;

	int query;
	for (int i = 0; i < q; i++)
	{
		cin >> query;
		queries.push_back(query);
	}
	
	// a nested for loop that takes each query and finds what day 
	// an amount is reached, or prints -1 if amount is not reached
	int i;
	for (qIt = queries.begin(); qIt != queries.end(); qIt++)
	{
		i = 1;
		bool notFound = true;
		for (transIter = trans.begin(); transIter != trans.end(); transIter++, i++)
		{
			if (*transIter >= *qIt)
			{
				cout << i << endl;
				notFound = false;
				break;
			}
		}
		if (notFound) cout << -1 << endl;
	}
}

