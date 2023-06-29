#include <iostream>

using namespace std;

template <typename T>
struct Node
{
    T data;
    Node<T>* next;
};

int main()
{
    Node<int>* first = nullptr;
    Node<int>* last = nullptr;

    Node<int>* newNode = new Node<int>;
    newNode->data = 1;
    newNode->next = nullptr;

    first = newNode;
    last = newNode;

    //adding another node at the beginning
    newNode = new Node<int>;
    newNode->data = 0;
    newNode->next = first;
    first = newNode;

    Node<int>* current = new Node<int>;

    //adding at the end of the list
    current = first;
    while(current->next != nullptr)
    {
        current = current->next;
    }
    newNode = new Node<int>;
    newNode->data = 3;
    current->next = newNode;
    last = newNode;

    current = first;
    while(current->next != nullptr)
    {
        current = current->next;
    }
    newNode = new Node<int>;
    newNode->data = 4;
    current->next = newNode;
    last = newNode;

    current = first;
    while(current->data != 1)
    {
        current = current->next;
    }
    newNode = new Node<int>;
    newNode->data = 2;
    newNode->next = current->next;
    current->next = newNode;



    //deleting first node
    Node<int>* temp = new Node<int>;
    temp = first;
    delete temp;
    first = first->next;


    //deleting at the end
    current = first;
    while(current->next != last)
    {
        current = current->next;
    }
    last = current;
    current->next = nullptr;


    current = first;
    while(current->data != 1)
    {
        current = current->next;
    }
    Node<int>* temp1 = new Node<int>;
    temp1 = current->next;
    current->next = temp1->next;
    delete temp1;


    current = first;
    while(current!= nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }




    return 0;
}
