using System;
using System.Collections;

namespace ConsoleApp.Logic
{
    public class Node<T>
    {
        public T Value { get; set; }
        public Node<T>? Next { get; set; }
        public Node<T>? Prev { get; set; }
    }




    public class DoubleLinkedList<T> : IEnumerable
    {
        public Node<T>? Head { get; set; }
        public Node<T>? Tail { get; set; }

        public T this[int i]
        {
            get
            {
                Node <T> result = Head; 
                if (Tail == null || i < 0)
                {
                    throw new IndexOutOfRangeException();
                }
                for (int counter = 0; counter < i; counter++)
                {
                    if (result == null)
                    {
                        throw new IndexOutOfRangeException();
                    }
                    result = result.Next;
                    
                }
                return result.Value;
            }
        }



        public DoubleLinkedList()
        {
            Head = Tail = null;
        }

        public void Add(T item)
        {
            if (item == null)
            {
                throw new Exception();
            }
            Node<T> obj = new Node<T>();
            obj.Value = item;       
            if (Tail == null)
            {
                Tail = obj;
                Head = obj;
            }
            else
            {
                Tail.Next = obj;
                obj.Prev = Tail;
                Tail = obj;
            }
        }
        public void Clear()
        {
            Head = Tail = null;
        }

        public bool Contains(T item)
        {
            foreach (T element in this)
            {
                if (element.Equals(item))
                    return true;
            }
            return false;
        }

        public bool Remove(T item)
        {

            var counterNode = Head;
            if (Head == null && Tail == null)
            {
                throw new IndexOutOfRangeException();
            }
            int i = 0;
            while (counterNode.Next != null)
            {
                if (counterNode.Value.Equals(item))
                {
                    Delete(i);
                    return true;
                }
                i++;               
              
            }
            return false;       
        }

        public void Delete(int index)
        {
            Node<T> result = Head;
            if (Tail == null || index < 0)
            {
                throw new IndexOutOfRangeException();
            }
            
            for (int counter = 0; counter < index; counter++)
            {             
                result = result.Next;
                if (result == null)
                {
                    throw new IndexOutOfRangeException();
                }
            }

            var parentNode = result.Prev;
            var childNode = result.Next;
            
            if (parentNode != null && childNode != null)
            {
                parentNode.Next = childNode;
                childNode.Prev = parentNode;
                result = null;
            }
            else if (parentNode != null && childNode == null)
            {
                parentNode.Next = null;
                result = null;
            } 
            else if (parentNode == null && childNode != null)
            {
                childNode.Prev = null;
                result = null;
                Head = childNode;
            }      
        }

        public T GetValue(int index)
        {
            return this[index]; //in indexator already implemented IndexOutOfRangeException                
        }

        public T[] GetValues()
        {
            var counterNode = Head;
            if (Head == null)
            {
                return new T[0];
            }

            int i = 0;
            while (counterNode.Next != null)
            {
                counterNode = counterNode.Next;
                i++;
            }

            T[] result = new T[i];

            for (int arrCounter = 0; arrCounter < i; arrCounter++)
            {
                result[arrCounter] = this[arrCounter];
            }
            return result;
        }

        public void CopyTo(T[] array, int index)
        {
            var counterNode = Head;
            if (counterNode == null) throw new IndexOutOfRangeException();

            int Count = 0;
            while (counterNode.Next != null)
            {
                counterNode = counterNode.Next;
                Count++;
            }
            if (array == null || index < 0 || array.Length - index < Count)
            {
                throw new IndexOutOfRangeException();
            }

            for (int i = 0; i < Count; ++i)
                array.SetValue(this[i], i + index);
        }

        public IEnumerator GetEnumerator()
        {
            return new DoubleLinkedListEnumerator<T>(this);
        }


        public class DoubleLinkedListEnumerator<TItem> : IEnumerator
        {
            public object Current { get ; private set; }

            private DoubleLinkedList<TItem> _dlist;
            Node<TItem> nextNode;


            public DoubleLinkedListEnumerator(DoubleLinkedList<TItem> dlist)
            {
                _dlist = dlist;
                nextNode = _dlist.Head;
            }

            public bool MoveNext()
            {                          
                if (nextNode == null)
                {
                    return false;
                }
                TItem val = nextNode.Value;
                Current = val;
                nextNode = nextNode.Next;
                return true;
            }

            public void Reset()
            {
                _dlist.Head = _dlist.Tail = null;
            }
        }
    }
}