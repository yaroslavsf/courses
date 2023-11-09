#include <iostream>

namespace QWE
{
	class Queue
	{
	private:
		struct Node
		{
		public:
			int value;
			Node* next;
			Node* prev;
		public:
			Node(int value = 0, Node* next = 0, Node* prev = 0)
				:
				next{ next },
				prev{ prev },
				value{ value }
			{}
		};
		Node* head;
		Node* tail;
		size_t count;


	public:
		//�����������
		Queue()
			:
			head{ 0 },
			tail{ 0 },
			count{ 0 }
		{}

		//����������� �����������
		Queue(const Queue& source)
		{
			Node* temp = source.head;
			while (temp != 0)
			{
				push(temp->value);
				temp = temp->next;
			}
		}

		//����� ���������� � �����
		void push(int value)
		{

			Node* add_node = new Node;
			add_node->value = value;
			count++;
			if (head == nullptr && tail == nullptr) //������ ���� ����, ���� ����� ��������
			{
				head = tail = add_node;
				add_node->next = nullptr;
				add_node->prev = nullptr;
			}
			else
			{
				tail->next = add_node;
				add_node->next = nullptr;
				add_node->prev = tail;
				tail = add_node;
			}
		}

		//����� �������� ������� ��.
		void pop()
		{
			Node* temp = head;
			if (head != nullptr)
			{
				if (head->next == nullptr)
				{
					delete head;
					head = nullptr;
				}
				else
				{
					head = head->next;
					head->prev = nullptr;
					delete temp;
				}
			}
		}

		// ����� ������ �� ����� �������
		void display()
		{
			Node* temp = head;
			while (temp)
			{
				std::cout << temp->value << ' ';
				temp = temp->next;
			}
		}

		//�������� �� ������� �������
		bool isEmpty()
		{
			if (count)
				return 1;
			else
				return 0;
		}

		//������ ���-�� ���������� � �������
		size_t getCount()
		{
			return count;
		}


		//����������
		~Queue()
		{
			while (head)
			{
				this->pop();
			}
		}

	};
}

int main()
{
	QWE::Queue mas;
	for (int i = 0; i < 10; i++)
	{
		mas.push(i + 1);
	}
	mas.display();
	std::cout << "\n";
	for (int i = 0; i < 9; i++)
	{
		mas.pop();
	}
	mas.display();
	return 0;
}