#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    //constructor
    Node(int d){
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }

    //destructor
    ~Node(){
        int val = this->data;
        if(next!=NULL){
            delete next;
            next = NULL;
        }
    }
};


void insertNode(Node* &head, int value, int d){
    Node* temp = new Node(d);
    //empty linked list
    if(head == NULL){
        temp->next = temp;
        temp->prev = temp;
        head = temp;
    }
    //list is not empty
    //assuming value is present in linked list
    else{
        //only 1 node 
        if(head->next == head){
            temp->next = head;
            temp->prev = head;
            head->next = temp;
        }
        //node >= 2
        else{
            Node* curr = head;
            while(curr->data!=value){
                curr = curr->next;
            }

            temp->next = curr->next;
            curr->next = temp;
            temp->prev = curr;
            curr->next->prev = temp;
        }
        
    }
}

void print(Node* &head){
    if(head == NULL){
        cout<<"List is empty"<<endl;

    }

    else{
        Node* temp = head;
        do{ 
            cout<<head->data<<" ";
            head = head->next;
        } while(head != temp);
        cout<<endl;
    }
}

void length(Node* &head){
    if(head == NULL){
        cout<<"List is empty, Lenght: 0"<<endl;

    }

    else{
        Node* temp = head;
        int count = 0;
        do{ 
            count ++;
            head = head->next;
        } while(head != temp);
        cout<<"Length: "<<count<<endl;
    }
}

void deleteNode(Node* &head, int element){
    if(head == NULL){
        cout<<"List is empty"<<endl;
        return;
    }

    else{
        Node* prev = head;
        Node* curr = prev->next;

        //for 1 node;
        if(curr == prev){
            head = NULL;
            return;
        }

        while(curr->data != element){
            prev = curr;
            curr = curr->next;
        }
        
        if(curr==head){
            head = curr->next;
        }

        prev->next = curr->next;
        curr->next->prev = curr->prev;
        curr->next = NULL;
        curr->prev = NULL;
        delete curr;
    }
}

int main(){

    Node* head = NULL;

    length(head);
    print(head);
    insertNode(head, 2, 1); //insert in empty list
    print(head);

    deleteNode(head, 1);
    print(head);

    insertNode(head, 1, 2);
    print(head);

    insertNode(head, 2, 5);
    print(head);
    
    insertNode(head, 5, 6);
    print(head);

    insertNode(head, 6, 9);
    print(head);

    insertNode(head, 6, 10);
    print(head);

    insertNode(head, 10, 15);
    print(head);
    length(head);


    deleteNode(head, 10);
    print(head);

    deleteNode(head, 2);
    print(head);
    
    deleteNode(head, 9);
    print(head);

    length(head);







    return 0;
}
