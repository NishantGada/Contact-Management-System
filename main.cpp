#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;

// function declarations
void addContact();
void searchContact();
void displayContacts();
bool numberCheck(string);
bool digitCheck(string);
void end();


// global variables
string first_name, last_name, phone_number;


int main () {
    short int choice;

    cout << "CONTACT MANAGEMENT \n";

    while (1) {
    	cout << "\n\n\nPlease make a choice:- \n1. Add\n2. Search\n3. Display all contacts\n4. Exit\n\n=>  ";
	    cin >> choice;
	
	    switch(choice)
	    {
	        case 1 : addContact(); break;
	        case 2 : searchContact(); break;
	        case 3 : displayContacts(); break;
	        case 4 :  
				end();
				break;
	        default :
	            cout << "\n X X X Wrong Choice\n\n\n";
	            break;
	    }
	}
    return 0;
}

void addContact() {

    ofstream phone_book("Phone numbers.txt", ios::app);

	system("cls");
    cout << "\nAdd a contact:- \n";
    cout << "Enter your first name : ";
    cin >> first_name;
    cout << "Enter your last name : ";
    cin >> last_name;
    cout << "Enter your 10 digit phone number : ";
    cin >> phone_number;

    if (numberCheck(phone_number) == true)
    {
        if (digitCheck(phone_number) == true)
        {
            if(phone_book.is_open())
            {
                phone_book << first_name << " " << last_name << " " << phone_number << endl;
                cout << "\nContact Saved Successfully !\n";
            }
            else
            {
                cout << "\n\tError Opening File !";
            }

        }
        else
        {
            cout << "Invalid number, make sure the number is 10 digits long.. \n\n";
        }
    }
    else {
        cout << "Invalid number, make sure the number you have entered contains only digits.. \n\n";
    }
    phone_book.close();
}

void searchContact() {
//    cout << "Search contact section";
	bool found = false;
	ifstream contactFile("Phone numbers.txt");
	string entry;
	system("cls");
	cout << "\nSearch for : ";
	cin >> entry;
	
	cout << "\nContact details..";
	
	while(contactFile >> first_name >> last_name >> phone_number) {
		
		if(entry == first_name || entry == last_name )
        {
            cout << "\n\nFirst Name : " << first_name;
            cout << "\nLast Name : " << last_name;
            cout << "\nPhone Number : " << phone_number;
            found = true;
//            break;
        }
	} 
	
	if(found == false)
    cout << "\nNo Such Contact Found\n\n";
}

void displayContacts() {
	system("cls");
	cout << "\nDisplaying all contacts\n\n";
	
	ifstream contacts("Phone numbers.txt");
	
	while(contacts >> first_name >> last_name >> phone_number) {
		cout << "\nfirst name => ";
		for (int i=0; i<first_name.length(); i++) {
			cout << first_name[i];
		}
		cout << " ";
		cout << "\n";
		cout << "last name => ";
		for (int j=0; j<last_name.length(); j++) {
				cout << last_name[j];
		}
		cout << " ";
		cout << "\n";
		cout << "phone number => ";
		for (int k=0; k<phone_number.length(); k++) {
				cout << phone_number[k];
		}
		cout << "\n";
	}
}

bool digitCheck(string x) {
    if (x.length() == 10) {
        return true;
    }
    else {
        return false;
    }
}

bool numberCheck (string x) {
    bool value = true;

    for (int i=0; i<x.length(); i++) {
       if (!(int(x[i]) >= 48 && int(x[i]) <= 57)) {
            value = false;
            break;
       }
    }

    if (value == true) {
        return true;
    }
    if (value == false) {
        return false;
    }
}

void end () {
	system("cls");
	cout << "\nExiting phone directory..\nThank You\n\nPress any key to continue .. ";
	exit(1);
}


