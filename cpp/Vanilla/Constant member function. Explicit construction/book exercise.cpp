#include <iostream>
#include <cstring>
using namespace std;
void setString(char*& destination, const char* string)
{
	delete[] destination;
	if (string)
	{
		size_t len = strlen(string) + 1;
		destination = new char[len];
		strcpy_s(destination, len, string);
	}
	else
	{
		destination = nullptr;
	}
}
void cpy(char*& destination, const char* string)
{
	if(string)
	strcpy_s(destination, strlen(string) + 1, string);
}
class Book
{
private:
	char* name;
	char* author;
	char* publish;
	int year;
	int pages;
public:
	//конструкторы
	explicit Book(const char* name, const char* author, const char* publish, int year, int pages)
		:
		name{ (name) ? new char[strlen(name) + 1] : nullptr },
		author{ (author) ? new char[strlen(author) + 1] : nullptr },
		publish{ (publish) ? new char[strlen(publish) + 1] : nullptr },
		year{ year },
		pages{ pages }
	{
		cpy(this->name, name);
		cpy(this->author, author);
		cpy(this->publish, publish);
	}
	explicit Book() : Book(nullptr, nullptr, nullptr, 0, 0) {}
	Book(const Book& source)
		:
		name{ source.name ? new char[strlen(source.name) + 1] : nullptr},
		author{ source.author ? new char[strlen(source.author) + 1] : nullptr },
		publish{ source.publish? new char[strlen(source.publish) + 1] : nullptr }
	{
		if (source.name)
			cpy(this->name, source.name);
		if (source.author)
			cpy(this->author, source.author);
		if (source.publish)
			cpy(this->publish, source.publish);
		year = source.year;
		publish = source.publish;
	}
	//сеттеры и геттеры
	void setName(const char* name) { setString(this->name, name); }
	void setAuthor(const char* author) { setString(this->author, author); }
	void setPublish(const char* publish) { setString(this->publish, publish); }
	void setYear(const int x) { year = x; }
	void setPages(const int x) { pages = x; }

	const char* getName() const { return name; }
	const char* getAuthor() const { return author; }
	const char* getPublish() const { return publish; }
	const int getYear() const { return year; }
	const int getPages() const { return pages; }
	//
	void display()
	{
			if (name)
				cout << getName();
			else
				cout << "null";
			cout << endl;
			if (author)
				cout << getAuthor();
			else
				cout << "null";
			cout << endl;
			if (publish)
				cout << getPublish();
			else
				cout << "null";
			cout << endl;
			cout << year << endl << pages << endl;
	}
	//деструктор
	~Book()
	{
		delete[] name;
		delete[] author;
		delete[] publish;
	}
};


int main()
{
	Book ex1[2];
	for (int i = 0; i < 2; i++)
	{
		ex1[i].setName("name");
		ex1[i].setAuthor("author");
		ex1[i].setPublish("publish");
		ex1[i].setYear(1991);
		ex1[i].setPages(0);
	}
	const char* buf = "author";
	cout << "searching by author\n";
	for (int i = 0; i < 2; i++)
	{
		if (buf)
		if (strcmp(buf, ex1[i].getAuthor()) == 0)
			ex1[i].display();
	}
	buf = "publish";
	cout << "searching by publish\n";
	for (int i = 0; i < 2; i++)
	{
		if (buf)
		if (strcmp(buf, ex1[i].getPublish()) == 0)
			ex1[i].display();
	}

	int year(1990);
	cout << "searching by year\n";
	for (int i = 0; i < 2; i++)
	{
		if (ex1[i].getYear() > year)
			ex1[i].display();
	}
	return 0;
}