#include <iostream>
#include <string>
#include <iterator>
#include <fstream>
#include <cstdio>
using namespace std;
class FileWorker
{
	string path;
	string buf;
	string bufFile;
	ifstream file_out;
public:
	FileWorker()
		:
		path{"null"},
		buf{""},
		bufFile{""}
	{}
	~FileWorker() {}
	void setFilePath(const string &path)
	{
		this->path = path;
		file_out.open(path, ios::out | ios::in);
	}

	void searchStr(const string & substring)
	{
		int count = 0;
		file_out.seekg(0);
		while (!file_out.eof())
		{
			file_out >> buf;
			if (buf == substring)
			{
				count++;
			}
		}
		cout << substring << ": " << count;
	}

	void replaceStr(string& toReplace, string& replaced)
	{
		ofstream file_in;
		file_in.open("tmp.txt", ios::in | ios::trunc);
		int i = 0;
		file_out.seekg(0);
		while (!file_out.eof())
		{
			if (i != 0)
			{
				file_in << ' ';
			}
			file_out >> buf;
			if (buf == replaced)
			{
				buf = toReplace;
			}
			file_in << buf;
			i++;
		}
		file_in.close();
		file_out.close();
		const char* prevFile = path.c_str();
		if(remove(prevFile))
		{
			cout << "error\n";
		}
		rename("tmp.txt", prevFile);
		
		file_out.open(path, ios::out | ios::in);
		
	
	}
		
	void showFile()
	{
		file_out.seekg(0);
		while (!file_out.eof())
		{
			file_out >> buf;
			cout << buf << ' ';
		}
	}

	void reverseFile()
	{
		ofstream file_in;
		file_in.open("tmp.txt", ios::in | ios::trunc);
		int i = 0;
		file_out.seekg(0);
		while (!file_out.eof())
		{
			if (i != 0)
			{
				file_in << ' ';
			}
			file_out >> buf;
			int count = 0;
			while (count < buf.size()/2)
			{
				swap(buf[count], buf[buf.size() - count-1]);
				count++;
			}
			file_in << buf;
			i++;
		}
		file_in.close();
		file_out.close();
		const char* prevFile = path.c_str();
		if (remove(prevFile))
		{
			cout << "error\n";
		}
		rename("tmp.txt", prevFile);

		file_out.open(path, ios::out | ios::in);
		
	}

	void showInterface()
	{
		int choose = 3;
		string buf;
		string toReplace;
		string replaced;
		cout << "choose an option:\n 1 - find the string in a file\n2 - replace some string in a file\n3 - show the file\n4 - reverse the file\n";
		cin >> choose;
		switch (choose)
		{
		case 1:
			cout << "enter the string(substring) you want to find\n";
			getline(cin, buf);
			searchStr(buf);
			break;
		case 2:
			cout << "enter the word you want to replace\n";
			getline(cin, replaced);
			cout << "enter the word you want to replace on\n";
			getline(cin, toReplace);
			replaceStr(toReplace, replaced);
			break;
		case 3:
			showFile();
			break;
		case 4:
			reverseFile();
			break;
				
		}
	}

};
int main()
{
	FileWorker file_obj;
	file_obj.setFilePath("file.txt");
	file_obj.showInterface();
	cout << endl;
	/*file_obj.searchStr("moon");*/
	/*;
	file_obj.replaceStr(toReplace, replaced);*/
	
	
	return 0;
}