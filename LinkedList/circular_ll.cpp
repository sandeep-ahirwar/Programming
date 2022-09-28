#include <iostream>
using namespace std;


class Node{
    public:
    int data;
    Node* next;

    //Constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    //Destructor
    ~Node(){
        int value = this->data;
        //memory free
        if(this->next != NULL){
            delete next;
            this->next == NULL;
        }
    }
};

void insertNode(Node* &tail, int element, int d){
    //empty list
    if(tail == NULL){
        Node* newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }
    else{
        //non empty list
        //assuming that the element is present in the list
        Node* curr = tail;
        // int count = 1;
        while(curr->data != element){
            curr = curr->next;
            // count++;
        }

        //element found and curr is on element wala node
        Node* temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;


    }
}

void deleteNode(Node* &tail, int value){

    //empty list
    if(tail == NULL){
        cout << "List is empty, pls check again"<<endl;
        return;
    }
    else{
        Node* prev = tail;  
        Node* curr = prev->next;

        while(curr->data != value){
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;

        //1 Node LinkedList
        if(curr==prev){
            tail = NULL;
        }
        else{
            if(curr == tail){
                tail = curr->next;
            } 
            curr->next = NULL;
            delete curr;
        }

    }

     
}
void print(Node* &tail){
    Node* temp = tail;

    //empty list
    if(tail == NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    // if we use while loop the we won;t be able to print tail element
    do{
        cout<<tail->data<<" ";
        tail = tail->next;
    } while(tail != temp);
    cout<<endl;
}

int main(){

    Node* tail = NULL;

    deleteNode(tail, 4); //try delete in empty list
    

    insertNode(tail, 1, 3);
    print(tail);

    deleteNode(tail, 3); //1 node linked list
    print(tail);

    insertNode(tail, 1, 3);
    print(tail);

    insertNode(tail, 3, 6);
    print(tail);

    insertNode(tail, 6, 9);
    print(tail);

    insertNode(tail, 9, 10);
    print(tail);

    insertNode(tail, 3 , 4);
    print(tail);

    insertNode(tail, 6, 7);
    print(tail);

    insertNode(tail, 10, 11);
    print(tail);

    deleteNode(tail, 3);
    print(tail);

    deleteNode(tail, 6);
    print(tail);


    

    return 0;
}