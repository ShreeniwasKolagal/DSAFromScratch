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
    }
};

void insertAtHead(Node *&head, int k)
{
    Node *temp = new Node(k, head);

    // Make sure that head is not nullptr. Otherwise it will lead to Segmentation fault
    if (head != nullptr)
        head->prev = temp;

    head = temp;
}

int main()
{
    vector<int> arr = {12, 5, 8, 7, 4};
    Node *head = nullptr;

    for (auto it = arr.rbegin(); it != arr.rend(); it++)
        insertAtHead(head, *it);

    head->display();
}