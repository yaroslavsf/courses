#include <iostream>
#include <map>
#include <string>
#include <iterator>
#include <fstream>
using namespace std;
class Dict
{
	map <string,int> dict;
	fstream stream_obj;
	string buf;
	int max = 0;
	string maxStr;
public:
	Dict() {}
	~Dict() {}

	void setPath(const string& path)
	{
		stream_obj.open(path, ios::in | ios::out);
	}

	void analyze()
	{
		stream_obj.seekg(0);
		while (!stream_obj.eof())
		{
			stream_obj >> buf;
			dict[buf]++;
		}
	}

	void showInfo()
	{
		auto begin = dict.begin();
		auto end = dict.end();
		
		while (begin != end)
		{
			if ((*begin).second > max)
			{
				max = (*begin).second;
				maxStr = (*begin).first;
			}
			begin++;
		}
		cout << "The most frequent word: " << maxStr << ' ' << max << endl;

		auto begin2 = dict.begin();
		while (begin2 != end)
		{
			cout << (*begin2).first << ' ' << (*begin2).second << endl;
			begin2++;
		}
	}

	void saveInfoToFile(const string& filename)
	{
		stream_obj.close();

		stream_obj.open(filename, ios::in | ios::trunc | ios::out);
		auto begin = dict.begin();
		auto end = dict.end();
		stream_obj << "The most frequent word: " << maxStr << ' ' << max << endl;
		while (begin != end)
		{
			stream_obj << (*begin).first << ' ' << (*begin).second << endl;
			begin++;
		}
		
		
	}

};

int main()
{
	Dict dictionary;
	dictionary.setPath("file.txt");
	dictionary.analyze();
	dictionary.showInfo();
	dictionary.saveInfoToFile("newFile.txt");
	return 0;
}