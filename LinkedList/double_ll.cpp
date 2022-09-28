#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* prev;
    Node* next;

    //Constructor
    Node(int d) {
        this -> data = d;
        this-> prev = NULL;
        this -> next = NULL;
    }

    //destructor
    ~Node(){
        int val = this->data;
        if(next!=NULL){
            delete next;
            next = NULL;
        }
        cout<<"memory free for node with data : "<< val <<endl;
    }
};

//traversing dll to get length
int getLength(Node* &head){
    Node* temp = head;
    int count=0;
    while(temp!=NULL){
        count++ ;
        temp = temp-> next;
    }

    return count;
}

//traversing a dll to print
void print(Node* &head){
    Node* temp = head;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp-> next;
    }
    cout<< endl;
}

//insert at head
void insertAtHead(Node* &head,Node* &tail, int d){
    //if list is empty
    if(head == NULL){
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else{
        Node* temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

//insert at tail
void insertAtTail(Node* &tail,Node* &head, int d){
    //list empty
    if(head == NULL){
        Node* temp = new Node(d);
        tail = temp;
        head = temp;
    }
    else{
        Node* temp = new Node(d);
        tail-> next = temp;
        temp->prev= tail;
        tail = temp;
    }
}

//insert at position
void insertAtPosition(Node* &head, Node* &tail,int position, int d){
    if(position==1){
        insertAtHead(head,tail, d);
        return;
    }
    
    Node* temp = head;
    int count = 1;
    while(count < position-1){
        temp = temp->next;
        count ++;
    }

    if(temp->next == NULL){
        insertAtTail(tail,head,d);
        return;
    }

    Node* nodetoInsert = new Node(d);
    nodetoInsert->next = temp->next;
    temp->next->prev = nodetoInsert;
    temp->next = nodetoInsert;
    nodetoInsert->prev = temp;

}

void deleteNode(int position, Node* &head,Node* &tail){
    //deleting first or starting node
    if(position == 1){
        Node* temp = head;
        temp -> next -> prev = NULL;
        head = temp -> next;
        temp -> next = NULL;
        delete temp;
    }
    else{
        // deleting any middle node or last node
        Node* curr = head;
        Node* prev = NULL;

        int count = 1;
        while(count<position){
            prev = curr;
            curr = curr->next;
            count ++;
        }

        if(curr->next == NULL){
            tail = curr->prev;
        }
        
        curr->prev = NULL;
        prev->next = curr -> next;
        curr -> next = NULL;
        delete curr;
        
    }
    
}


int main() {

    Node* head = NULL;
    Node* tail = NULL;

    print(head);

    insertAtHead(head,tail, 15);
    print(head);

    insertAtTail(tail,head, 20);
    print(head);

    insertAtPosition(head,tail, 2, 11);
    print(head);

    insertAtPosition(head,tail, 1, 9);
    print(head);

    insertAtPosition(head,tail, 5, 22);
    print(head);

    deleteNode(4, head,tail);
    print(head);

    cout<<"Tail: "<< tail->data << endl;

    cout<<"Length : "<<getLength(head)<< endl;
    return 0;
}
