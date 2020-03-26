#include <iostream>

using namespace std;

template <typename T>
class Node
{
public:
    Node();
    Node(T _data);
    ~Node();
    T getData();
    void setData(T data);
    Node<T> *getNext();
    void setNext(Node<T> *next);
    Node<T> *getPrev();
    void setPrev(Node<T> *prev);

private:
    T data;
    Node<T> *next;
    Node<T> *prev;
};

template <typename T>
Node<T>::Node() : data({}), next(nullptr), prev(nullptr) {}

template <typename T>
Node<T>::Node(T _data) : data(_data), next(nullptr), prev(nullptr) {}

template <typename T>
Node<T>::~Node()
{
    cout << "Deleting node with data " << data << endl;
}

template <typename T>
T Node<T>::getData()
{
    return data;
}

template <typename T>
void Node<T>::setData(T data)
{
    this->data = data;
}

template <typename T>
Node<T> *Node<T>::getNext()
{
    return next;
}

template <typename T>
void Node<T>::setNext(Node<T> *next)
{
    this->next = next;
}

template <typename T>
Node<T> *Node<T>::getPrev()
{
    return prev;
}

template <typename T>
void Node<T>::setPrev(Node<T> *prev)
{
    this->prev = prev;
}

template <typename T>
class LinkedList
{
public:
    LinkedList();
    LinkedList(const LinkedList<T> &other);
    LinkedList(LinkedList<T> &&other);
    ~LinkedList();
    LinkedList<T> &operator=(const LinkedList<T> &other);
    LinkedList<T> &operator=(LinkedList<T> &&other);
    T operator[](int index);
    void clear();
    void pushHead(T data);
    void pushTail(T data);
    T popHead();
    T popTail();
    T peekHead();
    T peekTail();
    void print();
    int size();

private:
    Node<T> *head;
    Node<T> *tail;
    int count;
    void copy(const LinkedList<T> &other);
};

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr), count(0) {}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &other)
{
    cout << "Copy" << endl;
    copy(other);
}

template <typename T>
LinkedList<T>::LinkedList(LinkedList<T> &&other) : head(nullptr), tail(nullptr), count(0)
{
    cout << "Move" << endl;
    swap(head, other.head);
    swap(tail, other.tail);
    swap(count, other.count);
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    clear();
}

template <typename T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &other)
{
    if (head)
    {
        clear();
    }
    copy(other);

    return *this;
}

template <typename T>
LinkedList<T> &LinkedList<T>::operator=(LinkedList<T> &&other)
{
    if (head)
    {
        clear();
    }

    cout << "Move assign" << endl;
    swap(head, other.head);
    swap(tail, other.tail);
    swap(count, other.count);
    return *this;
}

template <typename T>
T LinkedList<T>::operator[](int index)
{
    if (!head || index > count - 1)
    {
        return T();
    }
    int pos = 0;
    Node<T> *tempPtr = head;
    while (pos < index)
    {
        tempPtr = tempPtr->getNext();
        pos++;
    }
    return tempPtr->getData();
}

template <typename T>
void LinkedList<T>::clear()
{
    tail = head;
    while (tail)
    {
        tail = tail->getNext();
        delete head;
        head = tail;
    }
    count = 0;
}

template <typename T>
void LinkedList<T>::pushHead(T data)
{
    Node<T> *newNode = new Node<T>(data);
    if (!head)
    {
        tail = newNode;
    }
    else
    {
        head->setPrev(newNode);
        newNode->setNext(head);
    }
    head = newNode;
    count++;
}

template <typename T>
void LinkedList<T>::pushTail(T data)
{
    Node<T> *newNode = new Node<T>(data);
    if (!tail)
    {
        head = newNode;
    }
    else
    {
        tail->setNext(newNode);
        newNode->setPrev(tail);
    }
    tail = newNode;
    count++;
}

template <typename T>
T LinkedList<T>::popHead()
{
    if (!head)
    {
        return T();
    }
    T nodeData = head->getData();
    if (!head->getNext())
    {
        head = nullptr;
        tail = nullptr;
        count = 0;
        return nodeData;
    }
    Node<T> *tempPtr = head->getNext();
    delete head;
    head = tempPtr;
    head->setPrev(nullptr);
    count--;
    return nodeData;
}

template <typename T>
T LinkedList<T>::popTail()
{
    if (!tail)
    {
        return T();
    }
    T nodeData = tail->getData();
    if (!tail->getPrev())
    {
        head = nullptr;
        tail = nullptr;
        count = 0;
        return nodeData;
    }
    Node<T> *tempPtr = tail->getPrev();
    delete tail;
    tail = tempPtr;
    tail->setNext(nullptr);
    count--;
    return nodeData;
}

template <typename T>
T LinkedList<T>::peekHead()
{
    if (!head)
    {
        return T();
    }
    return head->getData();
}

template <typename T>
T LinkedList<T>::peekTail()
{
    if (!tail)
    {
        return T();
    }
    return tail->getData();
}

template <typename T>
void LinkedList<T>::print()
{
    // 1 <-> 2 <-> 3 -|
    Node<T> *tempPtr = head;
    while (tempPtr)
    {
        cout << tempPtr->getData() << " ";
        if (tempPtr->getNext())
        {
            cout << "<-> ";
        }
        else
        {
            cout << "-|" << endl;
            ;
        }
        tempPtr = tempPtr->getNext();
    }
}

template <typename T>
int LinkedList<T>::size()
{
    return count;
}

template <typename T>
void LinkedList<T>::copy(const LinkedList<T> &other)
{
    if (!other.head)
    {
        head = nullptr;
        tail = nullptr;
        count = 0;
    }
    else
    {
        Node<T> *tempPtr = other.head;
        while (tempPtr)
        {
            pushTail(tempPtr->getData());
            tempPtr = tempPtr->getNext();
        }
        count = other.count;
    }
}

LinkedList<int> generateList()
{
    LinkedList<int> theList = LinkedList<int>();
    theList.pushHead(1);
    theList.pushHead(2);
    theList.pushHead(3);
    theList.pushHead(4);
    return theList;
}

int main()
{
    LinkedList<int> ll1 = generateList();
    LinkedList<int> ll2();
    ll2 = move(ll1);
    ll1.print();

    return 0;
}