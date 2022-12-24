#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    //constructor
    Node(int d){
        this-> data = d;
        this-> prev = NULL;
        this-> next = NULL;
    }

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

void print (Node* head)
{
    Node* temp = head;
     
    while(temp != NULL)
    {
        cout<< temp -> data<<" ";
        temp = temp -> next;
    }
    cout<< endl;
}
int getLength(Node* head){
    int len=0;
    Node* temp = head;
     
    while(temp != NULL)
    {
        len++;
        temp = temp -> next;
    }
    return len;
}
void insertathead(Node* &head, int d)
{
    Node* temp = new Node(d);
    temp-> next = head;
    head-> prev = temp;
    head = temp;
}
void insertattial(Node*  &tail, int d)
{
    Node* temp= new Node(d);
    tail-> next = temp;
    temp-> prev = tail;
    tail = temp;

}

void insertatposition(Node* &head, Node* &tail, int position ,int d){
    if(position == 1)
    {
        // Insert at head
        insertathead(head, d);
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
        insertattial(tail , d);
        return ;
    }
    // creating a node for d
    Node* nodetoinsert = new Node(d);

    nodetoinsert -> next = temp -> next;
    temp -> next -> prev = nodetoinsert;
    
    temp -> next = nodetoinsert;
    nodetoinsert-> prev = temp;

}
void deletenode(int position, Node* &head)
{
    //deleting first or start node
    if(position == 1){
        Node* temp = head;
        temp->next-> prev = NULL;
        head =  temp-> next;
        temp-> next= NULL;
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
        curr-> prev = NULL;
        prev -> next = curr-> next;
        curr-> next = NULL;
        delete curr;
    }
}

int main()
{
    Node* node1= new Node(10);
    Node* head = node1;
    Node* tail = node1;

    print (head);
    
    insertathead(head , 11);
    print (head);
    
    insertathead(head , 12);
    print (head);
    
    insertathead(head , 13);
    print (head);
    
    insertattial(tail, 25);
    print (head);

    insertattial(tail, 26);
    print (head);
    
    insertattial(tail, 28);
    print (head);

    insertatposition(head, tail, 5, 15);
    print (head);

    insertatposition(head, tail, 6, 20);
    print (head);

    insertatposition(head, tail, 7, 23);
    print (head);

    deletenode(3, head);
    print(head);

    deletenode(1, head);
    print(head);

    deletenode(8, head);
    print(head);

    cout<<"Length of linklist is:"<< getLength(head)<< endl;
    return 0;
}