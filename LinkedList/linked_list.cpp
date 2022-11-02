#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // #constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // deconstructor
    ~Node()
    {
        int value = this->data;
        // memory free
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
    }
};

void insertAtHead(Node *&head, int d)
{
    // new node create
    Node *temp = new Node(d);

    temp->next = head;
    head = temp;
}

void insertAtTail(Node *&tail, int d)
{
    // new node create
    Node *temp = new Node(d);

    tail->next = temp;
    tail = temp; // or tail = tail-> next;
}

void insertAtPosition(Node *&tail, Node *&head, int position, int d)
{
    // insert at head
    if (position == 1)
    {
        insertAtHead(head, d);
        return;
    }

    Node *temp = head;
    int count = 1;

    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }

    // insert at tail, last position
    if (temp->next == NULL)
    {
        insertAtTail(tail, d);
        return;
    }

    // creating a node for d
    Node *nodeToInsert = new Node(d);

    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void print(Node *&head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " "; // printing the current value
        temp = temp->next;         // assigning next node to temp
    }

    cout << endl;
}

void deleteNode(int position, Node *&head)
{
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    else
    {
        // delete middle node or last node
        Node *prev = NULL;
        Node *curr = head;
        int count = 1;
        while (count < position)
        {
            prev = curr;
            curr = curr->next;
            count++;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

int main()
{

    // Create new Node
    Node *node1 = new Node(10);
    // cout<< node1 -> data<<endl;
    // cout<< node1 -> next <<endl;

    // head pointed to node1;

    Node *head = node1;
    Node *tail = node1;
    print(head);

    insertAtTail(tail, 12);
    print(head);

    insertAtTail(tail, 15);
    print(head);

    insertAtPosition(tail, head, 3, 22);
    print(head);

    deleteNode(1, head);
    print(head);

    return 0;
}
