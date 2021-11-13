#include<iostream>
//#include "Customer.h"
#include "Admin.h"





int main(){

    int value;
  while (true)
  {
    cout<<"\n";
    cout<<"\n+=================================+\n";
    cout << "|| Enter 1 to View products      ||" << endl;
    cout << "|| Enter 2 to Search Products    ||" << endl;
    cout << "|| Enter 3 to View Cart          ||" << endl;
    cout<<"+=================================+\n";

    cout<<"\nEnter 4 for Admin Login\n";
    cout<< "Enter 5 to exit\n"<<endl;
    
    cout<<"Enter: ";
    cin >> value;
    switch (value)
    {
            case 1:
                showProducts(head);
                break;
            case 2:
                int id;
                cout<<"Enter Product id: ";
                cin>>id;
                searchProduct(head, id);
                break;
            case 3:
                viewCart(head);
                break;
           case 4:
                Admin();
                break;
            case 5:
                exit(0);
                break;
            default:
                cout << "Invalid input" << endl;
                break;
    }
  }

    return 0;
}