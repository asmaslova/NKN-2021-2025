#include <iostream>
#include <limits>
#include <cmath>
using namespace std; 
struct Node {
    string name;
    int amount;
    float price;
    Node *next;
};

struct list{
    
    void AddFirst(Node*&Head, string NewName, int n, float p){ //2
        Node *NewNode = new Node; //dinamic array
        NewNode->name = NewName;
        NewNode->amount = n;
        NewNode->price = p;
        NewNode->next = Head;
        Head = NewNode;
        return;
    }

    void AddItem (Node *&Head, string NewName, int n, float p){ //1
       Node *tmp=Head;
       if (Head == NULL) {
           AddFirst(Head, NewName, n, p);
           return;
       }
       while (tmp->next) tmp = tmp->next;
       Node *NewNode = new Node;
       NewNode->name = NewName;
       NewNode->amount = n;
       NewNode->price = p;
       NewNode->next = NULL;
       tmp->next = NewNode;
       return;
   }    

    int AddAfter (Node *Head, string NewName, int n, float p, string NameAfter){ //3 ..
       if (Head == NULL) return 1;
       Node *tmp = Head;
       while(tmp!=NULL && tmp->name != NameAfter){
           tmp = tmp->next;
       }
       if (tmp == NULL) return 1;
       Node *NewNode = new Node;
       NewNode->name = NewName;
       NewNode->amount = n;
       NewNode->price = p;
       NewNode->next = tmp->next;
       return 0;
   }
   
    int AddBefore(Node *&Head, string NewName, int n, float p, string NameBefore){ //4
        if (Head == NULL) return 1;
        if (Head->name == NameBefore){
            AddFirst(Head, NewName, n, p); return 0;
        }
        if(Head->next == NULL)return 1;
        Node *prev=Head, *tmp=Head->next;
        while (tmp->next!=NULL && tmp->name!=NameBefore){
            prev = prev->next;
            tmp = tmp->next;
        }
        if(tmp->next==NULL && tmp->name!=NameBefore) return 1;
        Node *NewNode = new Node;
        NewNode->name = NewName;
        NewNode->amount = n;
        NewNode->price = p;
        NewNode->next = tmp;
        prev->next = NewNode;
        return 0;
    }   

    int DelNode(Node *&Head, string DelName){ //5
        if(Head == NULL) return 1;
        Node *tmp=Head;
        if (Head->name == DelName){
            Head = Head->next;
            delete tmp; 
            return 0;
        }
        if(Head->next==NULL) return 1;
        Node *prev=Head;
        tmp=Head->next;
        while(tmp->next!=NULL && tmp->name!=DelName){
            prev = prev->next;
            tmp = tmp->next;
        }
        if(tmp->next==NULL && tmp->name!=DelName) return 1;
        prev->next = tmp->next;
        delete tmp;
        return 0;
    }

    void PrintList(Node *Head){ //6
        if(Head==NULL){
            cout<<"The list is empty"<<endl;
            return;
        }
        Node *tmp=Head;
        while(tmp!=NULL){
            cout<<"product: "<<tmp->name<<"\nAmount: "<<tmp->amount<<"\nPrice: "<<tmp->price<<"\n\n";
            tmp = tmp->next;
        }
        return;
    }
};

int main()
{
    int ItemAmount, number;
    string ItemName, ItemName1;
    float ItemPrice;
    typedef Node *PNode;
    PNode Head = NULL;
    bool flag = false;
    list ProductList;
    cout<<"Your product list."<<endl;
    cout<<"Enter the number of the required action"<<endl<<"0. Exit the programm."<<endl<<"1. Add a list item."<<endl<<"2. Add a list item at the beginning."<<endl<<"3. Add a list item after required item."<<endl;
    cout<<"4. Add a list item before required item."<<endl<<"5. Delete a list item"<<endl<<"6. Show the whole product list."<<endl;
    do{
        cout<<"What do you need to do? ";
        cin>>number;
        switch(number){

            case 1: //add a list item
                cout<<"Enter the name of item: ";
                cin>>ItemName;
                cout<<"Enter the amount of item: ";
                cin>>ItemAmount;
                cout<<"Enter the price of the item: ";
                cin>>ItemPrice;
                ProductList.AddItem(Head,ItemName,ItemAmount, ItemPrice);
                cout<<"Item added successfully."<<endl;
                break;
                
            case 2: //add a list item at the beginning
                cout<<"Enter the name of item: ";
                cin>>ItemName;
                cout<<"Enter the amount of item: ";
                cin>>ItemAmount;
                cout<<"Enter the price of the item: ";
                cin>>ItemPrice;
                ProductList.AddFirst(Head,ItemName,ItemAmount, ItemPrice);
                cout<<"Item added successfully."<<endl;
                break;
            
            case 3: //add a list item after smth
                cout<<"Enter the name of item: ";
                cin>>ItemName;
                cout<<"Enter the amount of item: ";
                cin>>ItemAmount;
                cout<<"Enter the price of the item: ";
                cin>>ItemPrice;
                cout<<"Enter the name of item you want to place your item after: ";
                cin>>ItemName1;
                ProductList.AddAfter(Head,ItemName,ItemAmount,ItemPrice,ItemName1);  
                cout<<"Item added successfully."<<endl;
                break;
                
            case 4: //add a list item before smth
                cout<<"Enter the name of item: ";
                cin>>ItemName;
                cout<<"Enter the amount of item: ";
                cin>>ItemAmount;
                cout<<"Enter the price of the item: ";
                cin>>ItemPrice;
                cout<<"Enter the name of item you want to place your item before: ";
                cin>>ItemName1;
                ProductList.AddBefore(Head,ItemName,ItemAmount,ItemPrice,ItemName1);
                cout<<"Item added successfully."<<endl;
                break;
                
            case 5: //delete a list item
                cout<<"Enter the name of item you want to delete: ";
                cin>>ItemName;
                ProductList.DelNode(Head,ItemName);
                cout<<"Item deleted successfully."<<endl;
                break;
                
            case 6:
                ProductList.PrintList(Head);
                break; 
                
            default:
                cout<<"Try again. Wrong input."<<endl; 
                cin.clear();
                break;
        };
    }while (number!=0);
    
return 0;
}

