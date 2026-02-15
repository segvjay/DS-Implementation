#include <bits/stdc++.h>
using namespace std;

struct Node{
    public:
    int data;
    Node* next;
    
    Node(int data){
        this->data=data;
        this->next=nullptr;
    }
};

class SCLL{
public:
    Node *head;

    SCLL(){
        head=nullptr;
    }

    void insertBeg(int data){
        Node* newNode = new Node(data);
        Node *temp;
        if(head==nullptr){
            head = temp = newNode;
        }

        newNode->next=head;
        temp->next=newNode;
        head=newNode;
    }

    void insertEnd(int data){
        if(head==nullptr){
            insertBeg(data);
            return;
        }

        Node* newNode = new Node(data);
        Node* ptr = head;
        while(ptr->next!=head){
            ptr=ptr->next;
        }
        newNode->next=ptr->next;
        ptr->next=newNode;

    }

    int countNodes(){
        Node* ptr=head;
        int count=0;
        while(ptr!=head){
            count++;
            ptr=ptr->next;
        }
        return count;
    }

    void insertPos(int data, int pos){
        if(head==nullptr){
            cout<<"List is empty"<<endl;
            return;
        }


        if(pos==1){
            insertBeg(data);
            return;
        }

        if(pos==countNodes()+1){
            insertEnd(data);
            return;
        }

        Node* newNode=new Node(data);
        Node* ptr = head;
        for(int i=1;i<pos-1;i++){
            ptr=ptr->next;
        }
        newNode->next=ptr->next;
        ptr->next=newNode;

    }

    

    void print(){
        Node* ptr = head;
        while(ptr->next!=head){
            cout<<ptr->data<<" ";
            ptr=ptr->next;
        }
        cout<<ptr->data<<endl;
    }
};

int main(){
    SCLL s1;
    s1.insertBeg(15);
    s1.insertBeg(10);
    s1.insertBeg(5);
    s1.print();
    s1.insertEnd(25);
    s1.print();
    s1.insertPos(20,4);
    s1.print();
    s1.deleteBeg();
    s1.print();
    return 0;
}