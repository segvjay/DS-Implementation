#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};

class LinearQueue{
    Node* front;
    Node* rear;
public:
    LinearQueue(){
        front=nullptr;
        rear=nullptr;
    }

    void enQueue(int data){
        Node* newNode = new Node(data);
        if(rear==nullptr){
            front=newNode; 
        }
        else{
            rear->next=newNode;
        }
        rear=newNode;
    }

    void deQueue(){
        if(front==nullptr){
            cout<<"Queue underflow"<<endl;
        }
        else{
            Node* temp = front;
            front=front->next;
            delete temp;
        }
    }

    void show(){
        if(front==nullptr){
            cout<<"Queue is empty"<<endl;
        }
        Node* temp = front;
        while(temp!=rear->next){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};

int main(){
    LinearQueue q;
    q.enQueue(10);
    q.enQueue(20);
    q.enQueue(30);
    q.show();
    q.deQueue();
    q.show();
    return 0;
}