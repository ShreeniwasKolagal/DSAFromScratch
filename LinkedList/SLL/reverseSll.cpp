#include <iostream>
#include <vector>
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

    int size()
    {
        Node *temp = this;
        int n = 0;

        while (temp != nullptr)
        {
            n++;
            temp = temp->next;
        }

        return n;
    }

    void static insertAtHead(Node *&head, int val)
    {
        Node *temp = new Node(val, head);
        head = temp;
    }
};

void reverseList(Node *&head)
{
    if (head == nullptr || head->next == nullptr)
        return;

    Node *prev = nullptr, *cur = head, *front = head->next;

    while (cur != nullptr)
    {
        cur->next = prev;

        prev = cur;
        cur = front;
        if (front != nullptr)
            front = front->next;
    }

    head = prev;
}

void reverseList1(Node *&head)
{
    if (head == nullptr || head->next == nullptr)
        return;

    Node *temp = head->next;
    reverseList1(temp);

    Node *front = head->next;

    front->next = head;
    head->next = nullptr;

    head = temp;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 10};
    Node *head = nullptr;

    for (auto it = arr.rbegin(); it != arr.rend(); it++)
        Node::insertAtHead(head, *it);

    head->display();
    reverseList(head);
    head->display();
    reverseList1(head);
    head->display();
}