#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
using namespace std;
class Direct
{
	fstream stream_obj;
	class Contact
	{
		string name;
		string owner;
		string phone;
		string address;
		string hobby;
	public:
		Contact()
			:
		name{ "null" },
		owner{ "null" },
		phone{ "null" },
		address{ "null" },
		hobby{ "null" }
		{}
		~Contact(){}

		//set methdods
		void setName(const string & name)
		{
			this->name = name;
		}
		void setOwner(const string& owner)
		{
			this->owner = owner;
		}
		void setPhone(const string& phone)
		{
			this->phone = phone;
		}
		void setAddress(const string& address)
		{
			this->address = address;
		}
		void setHobby(const string& hobby)
		{
			this->hobby = hobby;
		}

		//get methods
		const string& getName() const
		{
			return name;
		}
		const string& getOwner() const
		{
			return owner;
		}
		const string& getPhone() const
		{
			return phone;
		}
		const string& getAddress() const
		{
			return address;
		}
		const string& getHobby() const
		{
			return hobby;
		}
	};
	vector<Contact> contacts;
	Contact temp;
	public:

	Direct()
	{
		stream_obj.open("file.txt", ios::app | ios::out);
	}
	~Direct() {}

	void addContact(const string &name, const string& owner, const string& phone, const string& address, const string& hobby)
	{
		temp.setName(name);
		temp.setOwner(owner);
		temp.setPhone(phone);
		temp.setAddress(address);
		temp.setHobby(hobby);
		contacts.push_back(temp);
	}

	void saveToFile()
	{
		auto begin = contacts.begin();
		auto end = contacts.end();
		while (begin != end)
		{
			stream_obj << (*begin).getName() << ' ' << (*begin).getOwner() << ' ' 
				<< (*begin).getPhone() << ' ' << (*begin).getAddress() << ' ' << (*begin).getHobby() << "\n\n";
			begin++;
		}
	}

	void showDirect()
	{
		auto begin = contacts.begin();
		auto end = contacts.end();
		while (begin != end)
		{
			cout << (*begin).getName() << ' ' << (*begin).getOwner() << ' '
				<< (*begin).getPhone() << ' ' << (*begin).getAddress() << ' ' << (*begin).getHobby() << "\n\n";
			begin++;
		}
	}
	
	
	void searchByOwner(const string& str)
	{
		auto begin = contacts.begin();
		auto end = contacts.end();
		while (begin != end)
		{
			if (str == (*begin).getOwner())
			{
				cout << (*begin).getName() << ' ' << (*begin).getOwner() << ' '
					<< (*begin).getPhone() << ' ' << (*begin).getAddress() << ' ' << (*begin).getHobby() << "\n\n";
			}
			begin++;
		}
	}

	void searchByPhone(const string& str)
	{
		auto begin = contacts.begin();
		auto end = contacts.end();
		while (begin != end)
		{
			if (str == (*begin).getPhone())
			{
				cout << (*begin).getName() << ' ' << (*begin).getOwner() << ' '
					<< (*begin).getPhone() << ' ' << (*begin).getAddress() << ' ' << (*begin).getHobby() << "\n\n";
			}
			begin++;
		}
	}

	void searchByName(const string& str)
	{
		auto begin = contacts.begin();
		auto end = contacts.end();
		while (begin != end)
		{
			if (str == (*begin).getName())
			{
				cout << (*begin).getName() << ' ' << (*begin).getOwner() << ' '
					<< (*begin).getPhone() << ' ' << (*begin).getAddress() << ' ' << (*begin).getHobby() << "\n\n";
			}
			begin++;
		}
	}

	void searchByHobby(const string& str)
	{
		auto begin = contacts.begin();
		auto end = contacts.end();
		while (begin != end)
		{
			if (str == (*begin).getHobby())
			{
				cout << (*begin).getName() << ' ' << (*begin).getOwner() << ' '
					<< (*begin).getPhone() << ' ' << (*begin).getAddress() << ' ' << (*begin).getHobby() << "\n\n";
			}
			begin++;
		}
	}



};
int main()
{
	Direct direct;
	direct.addContact("firma", "vasya", "+999990000", "ul.qwe", "risovat'");
	direct.addContact("predpriatie", "venya", "+3333333333", "ul.zxc", "tancevat'");
	direct.saveToFile();
	direct.showDirect();
	direct.searchByHobby("tancevat'");
	return 0;
}