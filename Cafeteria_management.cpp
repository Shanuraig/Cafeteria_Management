#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

class Cafeteria
{
    struct details
    {
        int quantity, id;
        string name;
        int price;
        details* next;
    };

public:
    details* head = NULL;

    // **** Declaring all Functions of a Program *****

    void Insert_items();
    void Show_Main_Menu();
    void Update_items();
    void Search_items();
    void Delete_items();
    void Show_Total_food_items();
};

void Cafeteria :: Show_Main_Menu()
{ 
    int choice;
    cout << endl;
    cout << "******* Welcome to Our CafeShefe *******" << endl;
    cout << "\n S.NO.                    Functions "<<endl;
    cout << "\n   1.                  Insert new item :)"<<endl;
    cout << "\n   2.                  Show Main menu :)"<<endl;
    cout << "\n   3.                  Update new items:)"<<endl;
    cout << "\n   4.                  Search new items:)"<<endl;
    cout << "\n   5.                  Delete new items:)"<<endl;
    cout << "\n   6.                  Show total food items:)"<<endl;
    cout << "\n   7. **************** Exit ******************" << endl;

    cout << "Enter your choice : ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        Insert_items();

    case 2:
        Show_Main_Menu();

    case 3:
        Update_items();
        Show_Main_Menu();

    case 4:
        Search_items();
        Show_Main_Menu();
    case 5:
        Delete_items();
        Show_Main_Menu();
    case 6:
        Show_Total_food_items();
        Show_Main_Menu();

    case 7:
        exit(0);

    default:
        cout << "Invalid Input (Choose from 1 to 7 only)" << endl;
        Show_Main_Menu();
    }
}

void Cafeteria ::Insert_items()
{
    cout << ":::: Here you can add new items in your list :::::" << endl;

    details *new_details = new details;

    cout << "Enter the food ID :) ";
    cin >> new_details->id;

    cout << "Enter the food name :) ";
    cin >> new_details->name;

    cout << "Enter the price of the item :) ";
    cin >> new_details->price;

    cout << "Enter the quantity of items :) ";
    cin >> new_details->quantity;

    if (head == NULL)
    {
        head = new_details;
    }
    else
    {
        details* ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = new_details;
    }
    cout << "**** Item added successfully *****" << endl;
}

void Cafeteria ::Update_items()
{
    cout << "~~~ Here you can update the previous record ~~~~~" << endl;
    int t_id;
    if (head == NULL)
    {
        cout << "****OOPS! Your list is empty ******" << endl;
    }
    else
    {
        cout << "Enter the ID number of the item : ";
        cin >> t_id;
        details *ptr = head;
        if(t_id != ptr->id)
        {
            cout<<"~~~~~ OOPS! ID didn't match :( ~~~~~~"<<endl;
        }
        while (ptr != NULL)
        {
            if (t_id == ptr->id)
            {
                cout << "Enter the id for the updated item : ";
                cin >> ptr->id;

                cout << "Enter the name for the new updated food :) ";
                cin >> ptr->name;

                cout << "Enter the price of the new updated item :) ";
                cin >> ptr->price;

                cout << "Enter the quantity of the new updated item :) ";
                cin >> ptr->quantity;

                cout << "::::: Hurray! Details are updated successfully  :::::" << endl;
            }
            ptr = ptr->next;
        }
        
    }
}

void Cafeteria :: Show_Total_food_items()
{
    details* ptr = head;
    while (ptr != NULL)
    {
        cout << "Id of the item is : " << ptr->id << endl;
        cout << "Name of the item is : " << ptr->name << endl;
        cout << "Price of the item is : " << ptr->price << endl;
        cout << "Quantity of the item is : " << ptr->quantity << endl;
        ptr = ptr->next;
    }
}

void Cafeteria :: Search_items()
{
    cout << "~~~~ Here you can search the previous record ~~~ " << endl;
    int t_id;
    if (head == NULL)
    {
        cout << "##### OOPS! YOUR LIST IS EMPTY :( ####" << endl;
    }
    else
    {
        cout << " Enter the item id which you want to search :) " << endl;
        cin >> t_id;
        details* ptr = head;
        if(t_id != ptr->id)
        {
            cout<<"~~~~~ OOPS! ID didn't match :( ~~~~~~"<<endl;
        }
        while (ptr != NULL)
        {
            if (t_id == ptr->id)
            {
                cout << "id of item is : " << ptr->id << endl;
                cout << "Name of the item is : " << ptr->name << endl;
                cout << "price of the item is : " << ptr->price << endl;
                cout << "quantity of the item is : " << ptr->quantity << endl;
                
            }
        ptr=ptr->next;
        }
    }
}

void Cafeteria :: Delete_items()
{
    cout << "~~~~ Here you can Delete the previous record ~~~~~ " << endl;
    int t_id;
    if (head == NULL)
    {
        cout << "#### OOPS! YOUR LIST IS EMPTY :( ######" << endl;
    }
    else
    {
        cout << " Enter the item id which you want to delete :) " << endl;
        cin >> t_id;

        if(t_id != head->id)
        {
            cout<<"~~~~~ OOPS! ID didn't match :( ~~~~~~"<<endl;
        }
        
        if (t_id == head->id)
        {
            details* ptr = head;
            head = head->next;
            delete ptr;
            cout << "Deleted the searched item successfully :)";
        }
        else
        {
            details* pre = head;
            details* ptr = head;
            while (ptr != NULL)
            {
                if (t_id == ptr->id)
                {
                    pre->next = ptr->next;
                    delete ptr;
                    cout << "**** Your record is deleted successfuly :) *****" << endl;
                    break;
                }
                pre = ptr;
                ptr = ptr->next;
            }
        }
    }
}


int main()
{
    Cafeteria cafe;
    cafe.Show_Main_Menu();
    return 0;
}