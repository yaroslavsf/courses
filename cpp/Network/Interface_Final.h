#pragma once
#include <iostream>
#include "Checker.h"
#include "Handler.h"
#include <string>
#include <iterator>
using namespace std;


class Interface
{
	Checker checkObj;
	Handler handlObj;
	string sites;
	string buf;

public:
	Interface()
	{

	}


	void SiteWorker_Worker()
	{

		auto begin = sites.begin();
		auto end = sites.end();
		/*buf += "\"";*/
		while (begin < end)
		{
			if (begin == end - 1)
			{
				
				buf += *begin;
				checkObj.pushString(buf);
				/*buf += "\"";*/
				/*cout << buf << ' ';*/
				buf.clear();

			}
			if (*begin == ' ')
			{
				begin++;
			}
			else if (*begin != ',')
			{
				buf += *begin;
				begin++;
			}
			else
			{
				/*buf += "\"";*/
				checkObj.pushString(buf);
				/*cout << buf << ' ';*/
				buf.clear();
				/*buf += "\"";*/
				begin++;
			}
		}

	}

	int menu()
	{
		cout << "\nEnter sites separated by commas\n";
	/*	cin.ignore();*/
		getline(cin,sites);
		SiteWorker_Worker();
		checkObj.ultimateCheck();
		handlObj.handle(checkObj.getVectorLong(), checkObj.getVectorString());
		handlObj.output();
		return 0;
	}
	
	~Interface()
	{

	}
};