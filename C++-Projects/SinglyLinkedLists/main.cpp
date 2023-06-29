#include <iostream>

using namespace std;

template <typename T>
struct Node
{
    T data;
    Node<T>* _next;
};

int main()
{
    Node<int>* _head = nullptr;
    Node<int>* _tail = nullptr;

    Node<int>* newNode = new Node<int>;
    newNode->data = 0;
    newNode->_next = nullptr;

    _head = newNode;
    _tail = newNode;

    newNode = new Node<int>;
    newNode->data = 1;
    newNode->_next = nullptr;

    _tail->_next = newNode;
    //update the tail always
    _tail = newNode;


    newNode = new Node<int>;
    newNode->data = 2;
    newNode->_next = nullptr;

    _tail->_next = newNode;
    _tail = newNode;

    newNode = new Node<int>;
    newNode->data = 3;
    newNode->_next = nullptr;

    _tail->_next = newNode;
    _tail = newNode;

    newNode = new Node<int>;
    newNode->data = 4;
    newNode->_next = nullptr;

    _tail->_next = newNode;
    _tail = newNode;

    _head =_head->_next;

    Node<int>* current = _head;

    while(current->_next->data != 2)
    {
        current = current->_next;
    }

    Node<int>* temp = current->_next;
    current->_next = temp->_next;
    temp = nullptr;





    current = _head;
    while(current != nullptr)
    {
        cout << current->data << " ";
        current = current->_next;
    }

    return 0;
}
