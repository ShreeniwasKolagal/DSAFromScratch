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
};

/*
 ? Time Complexity: O(N)
 ? Space Complexity: O(N)
*/
void detectLoop(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        cout << "There is no loop" << endl;
        return;
    }
    Node *temp = head;
    unordered_map<Node *, int> mpp;

    while (temp != nullptr)
    {
        if (mpp.count(temp) != 0)
        {
            cout << "Loop starts at: " << temp << endl;
            return;
        }

        mpp[temp] += 1;
        temp = temp->next;
    }

    cout << "No Loop" << endl;
}

/*
 ? Time Complexity: O(N)
 ? Space Complexity: O(1)
*/
void detectLoop1(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        cout << "There is no loop" << endl;
        return;
    }

    Node *slow = head, *fast = head;

    while (fast != nullptr || fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            slow = head;

            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }

            cout << "Loop starts at: " << slow << endl;
        }
    }

    cout << "No Loop" << endl;
}

int main()
{
    // Create a sample linked list with a loop
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    node1->next = node2;
    Node *node3 = new Node(3);
    node2->next = node3;
    Node *node4 = new Node(4);
    node3->next = node4;
    Node *node5 = new Node(5);
    node4->next = node5;

    // Make a loop from node5 to node2
    node5->next = node2;

    // Set the head of the linked list
    Node *head = node1;

    // Detect the loop in the linked list
    detectLoop(head);
    detectLoop1(head);

    return 0;
}