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

void SegregatetoOddEven(Node *&head)
{
    Node *oddHead = new Node(-1), *oddTail = oddHead;
    Node *evenHead = new Node(-1), *evenTail = evenHead;
    Node *cur = head, *temp;

    while (cur)
    {
        temp = cur;
        cur = cur->next;

        temp->next = nullptr;

        if (temp->data & 1)
        {
            oddTail->next = temp;
            oddTail = temp;
        }
        else
        {
            evenTail->next = temp;
            evenTail = temp;
        }
    }
    evenTail->next = oddHead->next;

    head = evenHead->next;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    Node *head = nullptr;

    for (auto it = arr.rbegin(); it != arr.rend(); it++)
        Node::insertAtHead(head, *it);

    head->display();
    SegregatetoOddEven(head);
    head->display();
}