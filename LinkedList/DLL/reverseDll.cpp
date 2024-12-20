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

    void static insertAtHead(Node *&head, int k)
    {
        Node *temp = new Node(k, head);

        if (head != nullptr)
            head->prev = temp;

        head = temp;
    }
};

void reverse(Node *&head)
{
    if (head == NULL || head->next == NULL)
        return;

    Node *last = nullptr, *cur = head, *front = head->next;

    while (cur != nullptr)
    {
        cur->prev = cur->next;
        cur->next = last;

        last = cur;
        cur = front;

        if (front != nullptr)
            front = front->next;
    }

    head = last;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head = nullptr;

    for (auto it = arr.rbegin(); it != arr.rend(); it++)
        Node::insertAtHead(head, *it);

    head->display();
    reverse(head);
    head->display();
}