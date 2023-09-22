#include <iostream>

using namespace std;

class Node {
    
    public:
    int data;
    Node* next;
    
    //constructor
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }

    //destructor
    ~Node() {
        int value = this -> data;
        //memory free
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }
};

void print(Node* head){
    
    if(head == NULL){
        cout << "List is empty" << endl;
        return;
    }
    Node* temp = head;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

void insertAtHead(Node* &head, int d){
    //create new node
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int d){
    //create new node
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = temp;
}

void insertAtPosition(Node* &head, Node* &tail, int position, int d){

    if(position == 1){
        insertAtHead(head, d);
        return;
    }

    Node* temp  = head;
    int cnt = 1;

    while(cnt < position - 1){
        temp = temp -> next;
        cnt++;
    }

    //inserting at last position
    if(temp -> next == NULL){
        insertAtTail(tail, d);
        return;
    }

    Node* nodeToInsert = new Node(d);

    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;
}

void deleteNode(int position, Node* &head){

    //deleting fist or start node
    if(position == 1){
        Node* temp = head;
        head  = head -> next;

        delete(temp);
    }
    else{
        //deleting any middle node or last node
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position) {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        prev -> next = curr -> next;
        curr -> next  = NULL;
        delete curr;

    }
}

int main()
{
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    print(head);

    insertAtHead(head, 12);
    print(head);
    insertAtTail(tail, 15);
    print(head);
    insertAtHead(head, 55);
    print(head);
    insertAtPosition(head, tail, 3, 22);
    print(head);
    deleteNode(4, head);
    print(head);


    return 0;
}
