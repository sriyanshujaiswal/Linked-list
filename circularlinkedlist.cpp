#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int d)
    {
        this-> data = d;
        this-> next=NULL;
    }

    ~Node(){
        int value = this-> data;
        if(this-> next != NULL)
        {
            delete next;
            this-> next = NULL;
        }
        cout<<"Memory is free for node of data:"<< value<< endl;
    }
};
void print(Node* tail)
{
    if (tail ==  NULL){
        cout<<"List is empty";
    }
    Node* temp = tail;
    do{
        cout<< tail -> data<< " ";
        tail= tail-> next;
    }while(tail != temp);
    cout<< endl;
}

void insertnode(Node* &tail, int element, int d)
{ 

    // empty list
    if(tail == NULL){
        Node* newNode = new Node(d);
        tail = newNode;
        newNode -> next = newNode;
    }
    else{
        // NOn empty list
        // Assuming that the element is present in the list
        Node* curr= tail;
        while(curr-> data != element)
        {
            curr= curr -> next;
        }
        // element found -> curr is representing element wala data
        Node* temp = new Node(d);
        temp-> next = curr-> next;
        curr-> next = temp;

    }
}

void deletnode( Node* &tail, int value)
{
    // empty List
    if (tail= NULL)
    {
        cout<<"List is Empty"<< endl;
        return ;
    }
    else{
        // Non empty list
        // Assuming value is present int the list
        Node* prev = tail;
        Node* curr = prev-> next;    
        while(curr->data != value)
        {
            prev = curr;
            curr = curr -> next;
        }

        prev -> next = curr -> next;

        // 1 Node linkedlist
        if(curr == prev){
            tail = NULL;
        }

        if(tail ==  curr){
            tail = prev;
        }
        curr-> next = NULL;
        delete curr;
    }
}


int main ()
{
    Node* tail = NULL;

    insertnode(tail, 2, 3);
    print (tail);

    insertnode(tail, 3, 5);
    print (tail);
    insertnode(tail, 5, 7);
    print (tail);
    insertnode(tail, 7, 9);
    print (tail);
    insertnode(tail, 5, 6);
    print (tail);
    insertnode(tail, 9, 10);
    print (tail);
    insertnode(tail, 3, 4);
    print (tail);

    
    deletnode(tail, 3);
    print (tail);

    return 0;
}