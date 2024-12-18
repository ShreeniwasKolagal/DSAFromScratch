#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data, Node *ptr) : data(data), next(ptr) {}
    Node(int data) : data(data), next(nullptr) {}

    void display()
    {
        Node *temp = next;
        cout << this->data << " ";

        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

void insertAtHead(Node *&head, int val)
{
    Node *temp = new Node(val, head);
    head = temp;
}

int main()
{
    vector<int> arr = {12, 8, 5, 7};
    int val = 100;

    Node *head = nullptr;

    for (auto i = arr.rbegin(); i != arr.rend(); i++)
        insertAtHead(head, *i);

    insertAtHead(head, val);

    head->display();
}