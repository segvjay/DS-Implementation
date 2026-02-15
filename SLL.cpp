#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        this->next=nullptr;
    }
};

class SLL{
    Node* head;
public:
    SLL(){
        head=nullptr;
    }

    void createNode(int data){
        Node* newNode = new Node(data);
        if(head==nullptr){
            head=newNode;
        }
        else{
            Node* temp;
           temp=head;
           while(temp->next!=nullptr){
                temp=temp->next;
           }
           temp->next=newNode;
        }
       
    }

    
    void insertAtBeg(int data){
        Node* newNode = new Node(data);
        newNode->next=head;
        head=newNode;
    }

    
    int countNode(){
        Node* temp = head;
        int count=0;
        while(temp!=nullptr){
            temp=temp->next;
            count++;
        }

        return count;
    }
    
    void insertAtPos(int data, int pos){
        int count = countNode();
        if(pos>count+1 || pos<=0){
            cout<<"Invalid Position"<<endl;
        }
        else if(pos==1){
            insertAtBeg(data);
        }
        else if(pos==count+1){
            insertAtEnd(data);
        }
        else{
            Node* curr=head;
           for(int i=1; i<pos-1; i++){
               curr=curr->next;
           }
           Node* newNode = new Node(data);
           newNode->next=curr->next;
           curr->next=newNode;
        }
    }

    void insertAtEnd(int data){
       createNode(data);
    }

    void deleteFromBeg(){
        if(head==nullptr){
            cout<<"Underflow"<<endl;
        }
        else{
            Node* temp = head;
            head=head->next;
            delete temp;
        }
    }

    void deleteFromEnd(){
        if(head==nullptr){
            cout<<"Underflow"<<endl;
        }
        else if(head->next==nullptr){
            delete head;
            head=nullptr;
        }
        else{
            Node* temp = head;
            Node* curr = nullptr;
            while(temp->next!=nullptr){
                curr=temp;
                temp=temp->next;
            }
            curr->next=nullptr;
            delete temp;
        }
    }

    void deleteFromPos(int pos){
        int count = countNode();
        if(pos>count+1|| pos<=0){
            cout<<"Invalid Position"<<endl;
        }

        else if(pos==1){
            deleteFromBeg();
        }

        else if(pos==count){
            deleteFromEnd();
        }

        else{
            Node* temp = head;
            for(int i=1;i<pos-1;i++){
                temp=temp->next;
            }
            Node* curr = temp->next;
            temp->next = curr->next;
            delete curr;

        }
    }

    void show(){
        Node* temp = head;
        while(temp!=nullptr){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<endl;
    }
};

int main(){
    SLL l1;
    l1.createNode(20);
    l1.createNode(-1);
    l1.createNode(30);
    l1.show();
    l1.insertAtBeg(15);
    l1.insertAtEnd(89);
    l1.insertAtPos(25,3);
    l1.show();
    l1.deleteFromBeg();
    l1.deleteFromEnd();
    l1.deleteFromPos(3);
    l1.show();
    return 0;
}