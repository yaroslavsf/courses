#include <iostream>
#include <string.h>
#include <ctime>
#include <cstdlib>
using namespace std;
class Queue
{
	int* Wait;
	int MaxQueueLength;
	int QueueLength;
public:
	Queue(int m = 10);
	Queue(const Queue& source);
	~Queue();
	void Add(int c);
	int Extract();
	void Clear();
	bool IsEmpty();
	bool IsFull();

	int GetCount();
	void Show();
};

void Queue::Show() {
	cout << "\n-----------------------------------\n";
	for (int i = 0; i < QueueLength; i++) {
		cout << Wait[i] << " ";
	}
	cout << "\n-----------------------------------\n";
}
Queue::~Queue()
{
	//удаление очереди
	delete[]Wait;
}
Queue::Queue(int m)
{
	//получаем размер
	MaxQueueLength = m;
	//создаем очередь
	Wait = new int[MaxQueueLength];
	//Изначально очередь пуста
	QueueLength = 0;
}
Queue::Queue(const Queue& source)
	:
	Wait{new int[source.MaxQueueLength]},
	MaxQueueLength{source.MaxQueueLength},
	QueueLength{source.QueueLength}
{
	for (int i = 0; i < source.QueueLength; i++)
	{
		this->Wait[i] = source.Wait[i];
	}
}
void Queue::Clear()
{
	QueueLength = 0;
}
bool Queue::IsEmpty()
{
	return QueueLength == 0;
}
bool Queue::IsFull()
{
	return QueueLength == MaxQueueLength;
}
int Queue::GetCount()
{
	return QueueLength;
}
void Queue::Add(int c)
{
	if (!IsFull())
		Wait[QueueLength++] = c;
}
int Queue::Extract()
{
	if (!IsEmpty()) {
		int temp = Wait[0];
		for (int i = 1; i < QueueLength; i++)
			Wait[i - 1] = Wait[i];
		QueueLength--;
		return temp;
	}
	else 
		return -1;
}
int main()
{
	srand(time(NULL));
	Queue q1;
	for (;!q1.IsFull();)
	{
		q1.Add(rand() % ('Z' - 'A' + 1) + 'A');
	}

	Queue q2(q1), q3(q1);
	int n = rand()%(1-1+1)-1;
	for (int i = 0; i < n; i++)
	{
		q1.Extract();
	}
	n = rand() % (1 - 1 + 1) - 1;
	for (int i = 0; i < n; i++)
	{
		q2.Extract();
	}
	n = rand() % (1 - 1 + 1) - 1;
	for (int i = 0; i < n; i++)
	{
		q3.Extract();
	}

	q1.Show();
	q2.Show();
	q3.Show();
	return 0;
}