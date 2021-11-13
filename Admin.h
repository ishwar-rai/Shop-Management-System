#include <iostream>
#include <algorithm>
//#include <windows.h>
#include <string>
#include "Customer.h"

using namespace std;

// class Node
// {
// public:
//     int ID;
//     string Name;
//     double Price;
//     int Quantity;
    
//     Node *next = NULL;
// };

// Node* head = 0;
// Node* last = 0;


// class Node{
//     public:
//     int id;
//     int quantity;
//     float price;
//     string name;
//     Node* next;
// };
// Node* head = NULL;

// void product_list(){
//     int Id, quantity;
//     double price;
//     string name;
//     cout<<"\t\t\tEnter ID: ";
//     cin>>Id;
//     cout<<"\t\t\tEnter Name: ";
//     cin>>name;
//     cout<<"\t\t\tEnter product quantity:";
//     cin>>quantity;
//     cout<<"\t\t\tEnter product price:";
//     cin>>price;
//     Node* first = NULL;
//     first = new Node();

//     first->ID = Id;
//     first->Name = name;
//     first->Quantity =quantity;
//     first->Price = price;
//     first->next = NULL;
//     if(head == 0 && last == 0){
//         head = last = first;
//     }
//     else{
//         last->next = first;
//         last = first;
//     }
// }
void remove();
void modify();
void product_list(Node* &head);

void Admin(){
    int code = 1234, input;
    cout<<"\nEnter Code: ";
    cin>>input;
    if(input != code){
        cout<<"\n!! Invalid Code !!\n";
        return;
    }
    int value;
    while (true)
    {
        cout<<"\n";
        cout<<"\n+=================================+\n";
        cout << "|| Enter 1 to Add Products       ||" << endl;
        cout << "|| Enter 2 to update Products    ||" << endl;
        cout << "|| Enter 3 to Delete Products    ||" << endl;
        cout << "|| Enter 4 to Show Products      ||" << endl;
        cout<<"+=================================+\n";

        //cout<<"\nEnter 4 for Admin Login\n";
        cout<< "Enter 5 to exit\n"<<endl;
        
        cout<<"Enter: ";
        cin >> value;
        switch (value)
        {
            case 1:
                product_list(head);
                break;
            case 2:
                modify();
                break;
            case 3:
                remove();
                break;
            case 4:
                showProducts(head);
                break;
                //return;
            case 5:
                return;
            default:
                cout << "Invalid input" << endl;
                break;
        }
    }
}



void product_list(Node* &head){
    int id , quantity;
    double price;
    string name;

    Node *new_node = new Node();
    //t = ;
    //Node *p=head;
    if(head == NULL){
        head=new_node;
    } else{
    Node* temp = head;
    for (temp; temp->next !=NULL ; temp = temp->next);
    temp->next = new_node;
    new_node->next = NULL;
    }

    cout<<"\nEnter product ID :";
    cin>>id;
    new_node->id = id;
    cout<<"Enter product Name :";
    cin>>name;
    new_node->name=name;
    cout<<"Enter product quantity :";
    cin>>quantity;
    new_node->quantity=quantity;
    cout<<"Enter product price :";
    cin>>price;
    new_node->price = price;
    //head = t;
    cout<<"\n\n=====================================================";
    cout<<"\n\t\t!Product Addedd!\n";
    cout<<"=====================================================\n"; 

    int choice;
    cout<<"\nEnter 1 to Add more Products\n";
    cout<<"\nEnter 0 to Exit\n";
    cout<<"\nEnter: ";
    cin>>choice;

    if(choice == 1)
        product_list(head);
    else if(choice == 0)
        return;
    else{
        cout<<"!!Invalid Input!!\n";
        // cout<<"\nEnter: ";
        // cin>>choice;
    } 
    

}



void modify()
{
    int id;
    double nPrice;
    string nName;
    int nId;
    int nQuantity;
    
    //Node *cur;
    if (head == NULL)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        cout << "=================================================================" << endl;
        cout << "Product ID          Product Name        Quantity            Price" << endl;
        cout << "=================================================================" << endl;
        for (Node* t = head; t != NULL; t = t->next)
            table(t);
        cout << "=================================================================\n" << endl;
        cout << "\n\nEnter Products ID to modify product details: ";
        cin >> id;
        //cur = head;
    }
    Node *temp = NULL;
    //temp = head;
    cout << "=================================================================" << endl;
    cout << "Product ID          Product Name        Quantity            Price" << endl;
    cout << "=================================================================" << endl;
    for (temp = head; temp != NULL; temp = temp->next)
    {
        if (temp->id == id)
        {
            table(temp);
            cout << "\n=================================================================" << endl;
            cout << "\n\n\n";
            cout << "Enter new ID:";
            cin >> nId;
            temp->id = nId;
            cout << "Enter new Name:";
            cin >> nName;
            temp->name = nName;
            cout << "Enter new Quantity:";
            cin >> nQuantity;
            temp->quantity = nQuantity;
            cout << "Enter new Price:";
            cin >> nPrice;
            temp->price = nPrice;
            cout<<"\n=======================";
            cout<<"\n  Update Successfully\n";
            cout<<"=======================\n";
            return;
        }
        else if(temp->next == NULL)
        {
            cout << id << " is <<<Not found>>\n\n";
        }
    }
}


void remove(){
        
        Node *cur = NULL;
        Node *temp = NULL;
        temp = head;
        Node *temp1 = NULL;
        int pos;
        //cout<<
        cout<<"================================================================="<<endl;
        cout<<"Product ID          Product Name        Quantity            Price"<<endl;
        cout<<"================================================================="<<endl;
        for (temp; temp != NULL; temp = temp->next)
            table(temp);
        cout<<"=================================================================\n"<<endl;
        cout << "Enter Product ID: ";
        cin >> pos;
        int count = 0;
        
        for (temp = head; temp->id != pos; temp = temp->next)
        {
            count = count + 1;
        }
        //cout << "count" << count;
        temp = head;

        if (temp == NULL)
        {
            cout << "NO link...";
        }
        else if (count == 0)
        {
            head = temp->next;
            temp->next = NULL;
            free(temp);
            cout<<"Delete successfully...";
        }

        else if(count != 0)
        {

            for (int i = 0; i < count - 1; i++) // 1 2 3 5
            {
                temp = temp->next;
            }

            temp1 = temp->next;

            temp->next = temp1->next;
            temp1->next = NULL;
            free(temp1);
            cout<<"Delete successfully...";
        }
        else{
            cout<<pos <<"Not found";
        }
}




// void display(){
//     Node* temp = NULL;
//     if(head == 0 && last == 0){
//         cout<<"Underflow...";
//     }
//     else{
//         temp = head;
//         cout<<"Queue data: ";
//         while(temp != 0){
//             cout<<temp->id;
//             temp = temp->next;
//         }
//     }
// }






// main()
// {
// 	int value;
// 	while (true)
// 	{
// 		cout << "\nPress 1 for enter data" << endl;
// 		cout << "Press 2 to modify data" << endl;
// 		cout << "Press 3 to delete data" << endl;
// 		cout << "Press 4 to display the data" << endl;
        
// 		cin >> value;
// 		switch (value)
// 		{
// 		case 1:
// 			product_list();
// 			break;
// 		case 2:
// 			modify();
// 			break;
// 		case 3:
// 			delet();
// 			break;
// 		case 4:
// 			display();
// 			break;
        

// 		default:
// 			cout << "Invalid input" << endl;
// 			break;
// 		}
// 	}
// }