#pragma once
#include <vector>
using namespace std;
class Handler
{
	vector <string> avaiable;
	vector <string> unavaiable;
	vector <string> unknown;
	int avaiable_i;
	int unavaiable_i;
	int unknown_i;
public:

	void handle(vector<long> &codes, vector<string> &sites)
	{
		auto iterator = codes.begin();
		auto end = codes.end();
		
		auto begin_sites = sites.begin();
		
		while (iterator < end)
		{
			if (*iterator >= 200 && *iterator <= 226) 
			{
				avaiable.push_back(*begin_sites);
				avaiable_i++;
			}
			else if (*iterator >= 500 && *iterator <= 526) 
			{
				unavaiable.push_back(*begin_sites);
				unavaiable_i++;
			}
			else
			{
				unknown.push_back(*begin_sites);
				unknown_i++;
			}
			iterator++;
			begin_sites++;
		}
	}

	void output()
	{
		cout << "\nAvaiable sites - " << avaiable_i << endl;
		for (auto string1 : avaiable)
		{
			cout <<  string1 << '\n';
		}

		cout << "\n\nUnavaiable sites - " << unavaiable_i << endl;
		for (auto string2 : unavaiable)
		{
			cout << string2 << '\n';
		}

		cout << "\n\nUnknown sites - " << unknown_i << endl;
		for (auto string3 : unknown)
		{
			cout << string3 << '\n';
		}
	}
};