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

    void static insertAtHead(Node *&head, int val)
    {
        Node *temp = new Node(val, head);
        head = temp;
    }
};

int lengthLoop(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return 0;

    Node *slow = head, *fast = head;

    while (fast != nullptr || fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            int cnt = 1;
            fast = fast->next;

            while (slow != fast)
            {
                fast = fast->next;
                cnt++;
            }

            return cnt;
        }
    }

    return 0;
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

    fifth->next = second;

    int loopLength = lengthLoop(head);
    if (loopLength > 0)
    {
        cout << "Length of the loop: " << loopLength << endl;
    }
    else
    {
        cout << "No loop found in the linked list." << endl;
    }

    return 0;
}