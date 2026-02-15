#include <iostream>
#include <vector>
using namespace std;

class Node{
public:
    int row;
    int col;
    int data;
    Node* next;
};

int main(){
    int mat[4][5]={
        {0 , 0 , 3 , 0 , 4 },
        {0 , 0 , 5 , 7 , 0 },
        {0 , 0 , 0 , 0 , 0 },
        {0 , 2 , 6 , 0 , 0 }
    };

    Node *head = nullptr,*ptr;
    
    for(int i=0;i<4;i++){
        for(int j=0;j<5;j++){
            if(mat[i][j]!=0){
                Node *newNode = new Node;
                newNode->row=i;
                newNode->col=j;
                newNode->data=mat[i][j];
               if(head==nullptr){
                    head=ptr=newNode;
                    newNode->next=nullptr;
               }
               else{
                ptr->next=newNode;
                ptr=newNode;
                newNode->next=nullptr;
               }
            }
        }
    }

    Node * temp=head;
    while(temp!=nullptr){
        cout<<temp->row<<" ";
        cout<<temp->col<<" ";
        cout<<temp->data<<" ";
        temp=temp->next;
        cout<<endl;
    }

    return 0;

}