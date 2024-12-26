#include <iostream>
#include <vector>
#include <unordered_map>
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

bool detectLoop(Node *head)
{
    unordered_map<Node *, int> mpp;

    while (head)
    {
        mpp[head]++;
        if (mpp[head] > 1)
            return true;

        head = head->next;
    }

    return false;
}
bool detectLoop1(Node *head)
{
    Node *slow = head, *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next;

        if (slow == fast)
            return true;
    }

    return false;
}

int main()
{
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);
    Node *fourth = new Node(4);
    Node *fifth = new Node(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    fifth->next = third;

    if (detectLoop(head))
    {
        cout << "Loop detected in the linked list." << endl;
    }
    else
    {
        cout << "No loop detected in the linked list." << endl;
    }

    if (detectLoop1(head))
    {
        cout << "Loop detected in the linked list." << endl;
    }
    else
    {
        cout << "No loop detected in the linked list." << endl;
    }
}