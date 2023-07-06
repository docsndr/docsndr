#include <iostream>
#include <string>

using namespace std;

const int data_cap = 15;
char Alphabet[data_cap];
int data_count = 0;

void Insert_element(char user_input) {
    if (data_count >= data_cap) {
        cout << "Data set is full. Cannot add more elements." << endl;
        return;
    }

    Alphabet[data_count] = user_input;
    data_count++;
    cout << "\nElement added successfully." << endl;

    cout << "Updated elements: ";
    for (int i = 0; i < data_count; i++) {
        cout << Alphabet[i] << " ";
    }
    cout << endl;
}

void Remove_element(char user_input) {
    if (data_count <= 0) {
        cout << "Data set is empty. Cannot remove elements." << endl;
        return;
    }

    bool found = false;
    for (int i = 0; i < data_count; i++) {
        if (Alphabet[i] == user_input) {
            found = true;
            for (int j = i; j < data_count - 1; j++) {
                Alphabet[j] = Alphabet[j + 1];
            }
            data_count--;
            cout << "Element removed successfully." << endl;
            break;
        }
    }

    if (!found) {
        cout << "Element not found." << endl;
    }

    cout << "Updated elements: ";
    for (int i = 0; i < data_count; i++) {
        cout << Alphabet[i] << " ";
    }
    cout << endl;
}

void Locate_element(char user_input) {
    if (data_count <= 0) {
        cout << "Data set is empty. Cannot search elements." << endl;
        return;
    }

    bool found = false;
    for (int i = 0; i < data_count; i++) {
        if (Alphabet[i] == user_input) {
            found = true;
            cout << "Element found at index " << i << "." << endl;
            break;
        }
    }

    if (!found) {
        cout << "Element not found." << endl;
    }
}

int main() {
    for (int i = 0; i < 5; i++) {
        char user_input;
        cout << "\nEnter character " << i + 1 << ": ";
        cin >> user_input;
    }

    while (true) {
        char option;

        cout << "\n\nDATA SET using Arrays\n";
        cout << "[a] Add\n";
        cout << "[b] Delete\n";
        cout << "[c] Search\n";
        cout << "[d] Exit\n";
        cout << "Chosen option: ";
        cin >> option;

        switch (option) {
            case 'a': {
                char user_input;
                cout << "Enter a character: ";
                cin >> user_input;
                Insert_element(user_input);
                break;
            }
            case 'b': {
                char user_input;
                cout << "Enter the character to remove: ";
                cin >> user_input;
                Remove_element(user_input);
                break;
            }
            case 'c': {
                char user_input;
                cout << "Enter the character to search: ";
                cin >> user_input;
                Locate_element(user_input);
                break;
            }
            case 'd':
                exit(0);
            default:
                cout << "\nError! Invalid option." << endl;
        }
    }

    return 0;
}

