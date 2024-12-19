#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data, Node *next = nullptr, Node *prev = nullptr) : data(data), next(next), prev(prev) {}

    void display()
    {
        Node *temp = this;

        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

void insertAtHead(Node *&head, int k)
{
    Node *temp = new Node(k, head);

    if (head != nullptr)
        head->prev = temp;

    head = temp;
}

void deleteLastNode(Node *&head)
{
    if (head == nullptr)
        return;

    Node *temp = head;

    while (temp->next->next != nullptr)
        temp = temp->next;

    delete temp->next;
    temp->next = nullptr;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head = nullptr;

    for (auto it = arr.rbegin(); it != arr.rend(); it++)
        insertAtHead(head, *it);

    head->display();
    deleteLastNode(head);
    head->display();
}