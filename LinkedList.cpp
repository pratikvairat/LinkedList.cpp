/* 
Linked List in C++
********CREATION*********
1. Create Creation
*******INSERTION*********
2. Add Node At Tail 
3. Add Node At Head
*******DELETION**********
4. Delete Node Deletion
********DISPLAY**********
5. Display
*/

#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *Next;
    
    Node(){
        this->data=0;
        this->Next=NULL;
    }
    Node(int data){
        this->data=data;
        this->Next=NULL;
    }
};
class LinkedList{
    Node *Head;
    public:
    LinkedList(){
        Head=NULL;
        cout<<"List is Created"<<endl;
    }
    void Create();
    void insertAtTail(int);
    void insertAtHead(int);
    void deleteNode(int);
    void printList();
};
void LinkedList::Create(){
    char ch;
        Node *newNode,*temp;
        bool flag=true;
    do{ 
        int data;
        cout<<"Enter data to insert : "<<endl;
        cin>>data;
        newNode=new Node(data);
        if(flag==true){
            Head=newNode;
            temp=Head;
            flag=false;
        }else{
            temp->Next=newNode;
            temp=temp->Next;
        }
        cout<<"Do you want to add data?[Y/N]\n"<<endl;
        cin>>ch;
    }while(ch=='y' || ch=='Y');
}
void LinkedList::insertAtTail(int data){
    Node *newNode=new Node(data);
    if(Head==NULL){
        Head=newNode;
        return;
    }
    Node *temp=Head;
    while(temp->Next!=NULL){
        temp=temp->Next;
    }
    temp->Next=newNode;
    cout<<"Node Inserted \n";
}
void LinkedList::insertAtHead(int data){
    Node *newNode=new Node(data);
    if(Head==NULL){
        Head=newNode;
        return;
    }
    newNode->Next=Head;
    Head=newNode;
}
void LinkedList::deleteNode(int index){
    Node *temp1=Head,*temp2=NULL;
    int len=0;
    if(Head==NULL){
        cout<<"List is Empty"<<endl;
        return;
    }
    if(index=1){
        Head=Head->Next;
        delete temp1;
        return;
    }
    while(temp1!=NULL){
        temp1=temp1->Next;
        len++;
    }
    if(len>index){
        cout<<"Index Out of Range\n";
    }
    while(index-->1){
        temp2=temp1;
        temp1=temp1->Next;
    }
    temp2->Next=temp1->Next;
    delete temp1;
    cout<<"Node Deleted ! \n";
}
void LinkedList::printList(){
    Node *temp;
    temp=Head;
    if(temp==NULL){
        cout<<"List is Empty"<<endl;
    }
    while(temp->Next!=NULL){
        cout<<temp->data<<" ";
        temp=temp->Next;
    }
    cout<<endl;
}

int main(){
    LinkedList lst;
    char lr;
    int op;
    
    do{
        cout<<"Chose Operation to Perform :\n";
        cout<<"1. Create A List \n2. Insert Node At Tail \n3. Insert Node At Head \n4. Delete Node \n5. Display My List\n";
        cin>>op;
        switch(op){
            case 1:
                lst.Create();
                break;
            case 2:
                int d1;
                cout<<"Enter Number To Insert : \n";
                cin>>d1;
                lst.insertAtTail(d1);
                break;
            case 3:
                int d2;
                cout<<"Enter Number To Insert at Head: \n";
                cin>>d2;
                lst.insertAtTail(d2);
                break;
            case 4:
                int n;
                cout<<"Enter Index TO Delete The Node : \n";
                cin>>n;
                lst.deleteNode(n);
                break;
            case 5:
                lst.printList();
                break;   
        }
        cout<<"\nDo You Want To Perform More Operation ?[Y/N]\n";
        cin>>lr;
    }while(lr=='Y' || lr=='y');
    return 0;
}


