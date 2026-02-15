#include <bits/stdc++.h>
using namespace std;

class LinearQueue{
    int arr[10];
    int front,rear,size;
    
public:
    LinearQueue(){
        size = 10;
        front=-1;
        rear=-1;
    }

    void enQueue(int data){
        if(rear == size-1){
            cout<<"Overflow"<<endl;
            return;
        }
        
        else if(front==-1){
            front=0;
        }

        arr[++rear]=data;
    }

    void deQueue(){
        if(front==-1){
            cout<<"Underflow"<<endl;
            return;
        }
        else if (front > rear) {
            front = -1;
            rear = -1;
        }
        else{
            front++;
        }

        
    }

    void show(){
        if (front == -1) {
            cout << "Queue is empty" << endl;
            return;
        }
        for(int i=front; i<=rear; i++){
            cout<<arr[i]<<" ";
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