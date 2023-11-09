#pragma once
#include <vector>
#include <iterator>
#include <stdio.h>
#include <iostream>
#include <curl/curl.h>
#include <string.h>
#include "Checker.h"
using namespace std;

class SiteWorker
{

	/*const char* path;*/
	/*FILE* fp;*/
	CURL* curlCtx;
	CURLcode rc;
	long res_code;

public:
	SiteWorker()
		:
		res_code{ 0 }
	{

	}
	static size_t write_data(void* buffer, size_t size, size_t nmemb, void* userp)
	{
		return size * nmemb;
	}
	int sendRequest(string& url)
	{


		curlCtx = curl_easy_init();
		curl_easy_setopt(curlCtx, CURLOPT_URL, url);
		//curl_easy_setopt(curlCtx, CURLOPT_WRITEDATA, fp);
		//curl_easy_setopt(curlCtx, CURLOPT_WRITEFUNCTION, callbackfunction);
		curl_easy_setopt(curlCtx, CURLOPT_WRITEFUNCTION, write_data);
		curl_easy_setopt(curlCtx, CURLOPT_FOLLOWLOCATION, 1);

		rc = curl_easy_perform(curlCtx);
		


		curl_easy_getinfo(curlCtx, CURLINFO_RESPONSE_CODE, &res_code);
		/*if (!((res_code == 200 || res_code == 201) && rc != CURLE_ABORTED_BY_CALLBACK))
		{
			printf("!!! Response code: %d\n", res_code);
			return false;
		}*/

		curl_easy_cleanup(curlCtx);



		return true;
	}

	long getCode() 
	{
		return res_code;
	}
	
	
		/*auto iterator = sites.begin();
		int counter = 0;
		while (counter < id)
		{
			iterator++;
			counter++;
		}*/

	

};