#include <iostream>
#include <string>

using namespace std;

const int data_cap = 15;
string Element[data_cap];
int data_count = 0;

void Insert_element(string user_input) {
    if (data_count >= data_cap) {
        cout << "Data set is full. Cannot add more elements." << endl;
        return;
    }

    Element[data_count] = user_input;
    data_count++;
    cout << "\nElement added successfully." << endl;

    cout << "Updated elements: ";
    for (int i = 0; i < data_count; i++) {
        cout << Element[i] << " ";
    }
    cout << endl;
}

void Remove_element(string user_input) {
    if (data_count <= 0) {
        cout << "Data set is empty. Cannot remove elements." << endl;
        return;
    }

    int removed_count = 0;  
    for (int i = 0; i < data_count; i++) {
        if (Element[i] == user_input) {
            for (int j = i; j < data_count - 1; j++) {
                Element[j] = Element[j + 1];
            }
            data_count--;
            removed_count++;
            i--; 
        }
    }

    if (removed_count > 0) {
        cout << "Element removed successfully.\n";
    }
    else{
        cout << "Element not found." << endl;
    }

    cout << "Updated elements:\n";
    for (int i = 0; i < data_count; i++) {
        cout << Element[i] << "\n";
    }
    cout << endl;
}


void Locate_element(string user_input) {
    if (data_count <= 0) {
        cout << "Data set is empty. Cannot search elements." << endl;
        return;
    }

    bool found = false;
    cout << "Element found at index: ";
    for (int i = 0; i < data_count; i++) {
        if (Element[i] == user_input) {
            found = true;
            cout << i << " ";
        }
    }

    if (!found) {
        cout << "Element not found." << endl;
    } else {
        cout << endl;
    }
}


void Display_elements() {
    cout << "\nCurrent elements:\n ";
    for (int i = 0; i < data_count; i++) {
        cout << Element[i] << " ";
    }
    cout << endl;
}

int main() {
    for (int i = 0; i < 5; i++) {
        string user_input;
        cout << "\nEnter character " << i + 1 << ": ";
        cin >> user_input;
        Insert_element(user_input);
    }

    while (true) {
        char option;

        cout << "\n\nDATA SET using Arrays\n";
        cout << "[a] Add\n";
        cout << "[b] Delete\n";
        cout << "[c] Display\n";
        cout << "[d] Search\n";
        cout << "[e] Exit\n";
        cout << "Choose a letter: ";
        cin >> option;

        switch (option) {
            case 'a': {
                string user_input;
                cout << "Enter a character: ";
                cin >> user_input;
                Insert_element(user_input);
                break;
            }
            case 'b': {
                string user_input;
                cout << "Enter the character to remove: ";
                cin >> user_input;
                Remove_element(user_input);
                break;
            }
            case 'c': {
                Display_elements();
                break;
            }
            case 'd': {
                string user_input;
                cout << "Enter the character to search: ";
                cin >> user_input;
                Locate_element(user_input);
                break;
            }
            case 'e': {
                exit(0);
            }
            default:
                cout << "\nError! Invalid option." << endl;
        }
    }

    return 0;
}

