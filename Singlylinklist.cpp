#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    
    
    //Constructor 
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
    //Distructor
    ~Node(){
        int value = this -> data;
        if(this-> next != NULL)
        {
            delete next;
            this-> next = NULL;
        }
        cout<<" Memory is free for node with data  "<< value<< endl;
    } 


};
// Insert data at start
void Insertathead(Node* &head, int d) {

    // new node create
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;

}

void insertattail(Node* &tail , int d)
{
     // new node create
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = temp;

}
void insertatposition( Node* &head, Node* tail, int position , int d)
{
    if(position == 1)
    {
        Insertathead(head, d);
        return ;
        
    }
    Node* temp = head;
    int cnt = 1;
    while (cnt < position -1)
    {
        temp = temp -> next;
        cnt++;
    }
    //inserting at last position
    if(temp -> next == NULL)
    {
        insertattail(tail , d);
        return ;
    }
    // creating a node for d
    Node* nodetoinsert = new Node(d);
    nodetoinsert -> next = temp -> next;
    temp -> next = nodetoinsert;
}

void deletenode(int position, Node* &head)
{
    //deleting first or start node
    if(position == 1){
        Node* temp = head;
        head = head -> next;
        // memory free start node by distructor
        temp-> next = NULL;
        delete temp;
    }
    else{
        // deleting any middle and last node
        Node* curr = head ;
        Node* prev = NULL;
        int cnt = 1;
        while(cnt < position){
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev -> next = curr-> next;
        curr-> next = NULL;
        delete curr;
    }
}

void print (Node* &head) {
    Node* temp = head;

    while( temp != NULL)
    {
        cout<< temp -> data << " ";
        temp = temp -> next;
    }
    cout<< endl;

}

int main()
{
    // Create a new node
    Node* node1  = new Node(10);   //object
    cout<< node1 -> data << endl;
    cout<< node1 -> next << endl; 
    
    // head pointed on node1
    Node* head = node1;
    Node* tail=  node1;
    print (head);

    Insertathead (head, 9);
    
    print (head);
    
    Insertathead (head, 8);
    
    print (head);

    insertattail (tail , 12);
    print (head);

    insertattail (tail, 15);
    print (head);
    

    insertatposition(head, tail, 1, 7);
    print(head);

    insertatposition(head, tail, 5, 11);
    print(head);

    insertatposition(head, tail, 8, 16);
    print(head);

    cout<< "Head :"<< head-> data<< endl;
    cout<< "Tail :"<< tail-> data<< endl;

    deletenode(3, head);
    print(head);
    deletenode(1, head);
    print(head);
    cout<< "Head :"<< head-> data<< endl;
    cout<< "Tail :"<< tail-> data<< endl;
    return 0;

}