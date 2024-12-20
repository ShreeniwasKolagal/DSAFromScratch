#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data, Node *next) : data(data), next(next) {}

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

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 10};
    Node *head = nullptr;

    for (auto it = arr.rbegin(); it != arr.rend(); it++)
        Node::insertAtHead(head, *it);

    head->display();
    cout << "Length: " << head->size() << endl;
}