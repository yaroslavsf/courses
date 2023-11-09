#pragma once
#include <vector>
#include "Sites_worker.h"
/*auto iterator = sites.begin();
		int counter = 0;
		while (counter < id)
		{
			iterator++;
			counter++;
		}*/
class Checker
{
	vector<string> unchecked;
	vector<long> checked;
	SiteWorker requestObj;
	public:
	void pushString(string& str)
	{
		unchecked.push_back(str);
	}
	
	vector<long>& getVectorLong()
	{
		return checked;
	}
	vector<string>& getVectorString()
	{
		return unchecked;
	}




	void ultimateCheck()
	{
		auto begin = unchecked.begin();
		auto end = unchecked.end();

		while (begin < end)
		{
			requestObj.sendRequest(*begin);
			checked.push_back(requestObj.getCode());
			begin++;
		}
	}


};