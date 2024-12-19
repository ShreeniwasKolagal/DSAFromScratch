#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data, Node *next = nullptr) : data(data), next(next) {}

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

void deleteLastNode(Node *&head)
{
    Node *prev = nullptr;
    Node *cur = head;

    if (cur == nullptr)
        return;

    while (cur->next != nullptr)
    {
        prev = cur;
        cur = cur->next;
    }

    prev->next = nullptr;
    delete cur;
}

int main()
{
    Node *head = new Node(4);
    head->next = new Node(3);
    head->next->next = new Node(2);
    head->next->next->next = new Node(1);

    head->display();
    deleteLastNode(head);
    head->display();
}