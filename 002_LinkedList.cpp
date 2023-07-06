#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct Node {
    string data;
    Node* next;
};

class LinkedList {
private:
    Node* head;

    Node* createNode(string value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;
        return newNode;
    }

    void displayIdenticalElements(Node* resultHead, string value) {
        if (resultHead == NULL) {
            cout << "No identical elements found for value: " << value << endl;
            return;
        }

        cout << "Identical elements found for value: " << value << endl;
        Node* current = resultHead;
        while (current != NULL) {
            cout << "Position: " << current->data << endl;
            current = current->next;
        }
    }

public:
    LinkedList() : head(NULL) {}

    void insertNodeAtBeginning(string value) {
        Node* newNode = createNode(value);
        newNode->next = head;
        head = newNode;
        cout << "Node inserted at the beginning." << endl;
    }

    void insertNodeAtEnd(string value) {
        Node* newNode = createNode(value);

        if (head == NULL) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }

        cout << "Node inserted at the end." << endl;
    }

    void insertNodeAtPosition(string value, int position) {
        Node* newNode = createNode(value);

        if (position <= 0) {
            cout << "Invalid position. Node not inserted." << endl;
            return;
        }

        if (position == 1) {
            newNode->next = head;
            head = newNode;
            cout << "Node inserted at position 1." << endl;
            return;
        }

        Node* current = head;
        int count = 1;

        while (current != NULL && count < position - 1) {
            current = current->next;
            count++;
        }

        if (current == NULL) {
            cout << "Invalid position. Node not inserted." << endl;
            return;
        }

        newNode->next = current->next;
        current->next = newNode;
        cout << "Node inserted at position " << position << "." << endl;
    }

    void deleteNodeAtBeginning() {
        if (head == NULL) {
            cout << "List is empty. Cannot delete node." << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Node deleted from the beginning." << endl;
    }

    void deleteNodeAtEnd() {
        if (head == NULL) {
            cout << "List is empty. Cannot delete node." << endl;
            return;
        }

        if (head->next == NULL) {
            delete head;
            head = NULL;
            cout << "Node deleted from the end." << endl;
            return;
        }

        Node* current = head;
        while (current->next->next != NULL) {
            current = current->next;
        }

        Node* temp = current->next;
        current->next = NULL;
        delete temp;
        cout << "Node deleted from the end." << endl;
    }
    
    void deleteNodeAtPosition(int position) {
        if (head == NULL) {
            cout << "List is empty. Cannot delete node." << endl;
            return;
        }

        if (position <= 0) {
            cout << "Invalid position. Node not deleted." << endl;
            return;
        }

        if (position == 1) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Node deleted from position 1." << endl;
            return;
        }

        Node* current = head;
        int count = 1;

        while (current != NULL && count < position - 1) {
            current = current->next;
            count++;
        }

        if (current == NULL || current->next == NULL) {
            cout << "Invalid position. Node not deleted." << endl;
            return;
        }

        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
        cout << "Node deleted from position " << position << "." << endl;
    }

    void deleteNodeWithValue(string value) {
    if (head == NULL) {
        cout << "List is empty. Cannot delete node." << endl;
        return;
    }

    while (head != NULL && head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    Node* current = head;
    while (current != NULL && current->next != NULL) {
        if (current->next->data == value) {
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
        } else {
            current = current->next;
        }
    }

    cout << "Node(s) with value '" << value << "' deleted." << endl;
}


    void displayList() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        cout << "Stored data:" << endl;
        Node* current = head;
        while (current != NULL) {
            cout << current->data << endl;
            current = current->next;
        }
        cout << endl;
    }

    void searchValue(string value) {
        Node* resultHead = NULL;
        Node* current = head;
        int position = 0;

        while (current != NULL) {
            position++;
            if (current->data == value) {
                stringstream ss;
                ss << position;
                string positionString = ss.str();
                if (resultHead == NULL) {
                    resultHead = createNode(positionString);
                } else {
                    Node* temp = createNode(positionString);
                    temp->next = resultHead;
                    resultHead = temp;
                }
            }
            current = current->next;
        }

        displayIdenticalElements(resultHead, value);

        Node* temp;
        while (resultHead != NULL) {
            temp = resultHead;
            resultHead = resultHead->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList list;
    string value;
    int dataCount = 0;

    char option;
    while (true) {
        cout << "\nLINKED LIST Data Structure" << endl;
        cout << "[a] Add" << endl;
        cout << "[b] Delete" << endl;
        cout << "[c] Display" << endl;
        cout << "[d] Search" << endl;
        cout << "[e] Exit" << endl;
        cout << "Choose an option: ";
        cin >> option;

        switch (option) {
            case 'a':
                char subOption;
                cout << "\nChoose a sub-option:" << endl;
                cout << "[a] Insert at the beginning" << endl;
                cout << "[b] Insert at the end" << endl;
                cout << "[c] Insert at a specific position" << endl;
                cout << "Enter sub-option: ";
                cin >> subOption;

                switch (subOption) {
                    case 'a':
                        cout << "Enter a value to insert: ";
                        cin >> value;
                        list.insertNodeAtBeginning(value);
                        break;
                    case 'b':
                        cout << "Enter a value to insert: ";
                        cin >> value;
                        list.insertNodeAtEnd(value);
                        break;
                    case 'c':
                        int position;
                        cout << "Enter the position to insert the node (starting from 1): ";
                        cin >> position;
                        cout << "Enter a value to insert: ";
                        cin >> value;
                        list.insertNodeAtPosition(value, position);
                        break;
                    default:
                        cout << "\nError! Invalid sub-option." << endl;
                        break;
                }
                break;
            case 'b':
			    char deleteOption;
			    cout << "\nChoose a delete option:" << endl;
			    cout << "[a] Delete at the beginning" << endl;
			    cout << "[b] Delete at the end" << endl;
			    cout << "[c] Delete at a specific position" << endl;
			    cout << "[d] Delete a specific element and its duplicates" << endl; 
			    cout << "Enter delete option: ";
			    cin >> deleteOption;
			
			    switch (deleteOption) {
			        case 'a':
			            list.deleteNodeAtBeginning();
			            break;
			        case 'b':
			            list.deleteNodeAtEnd();
			            break;
			        case 'c':
			            int position;
			            cout << "Enter the position to delete the node (starting from 1): ";
			            cin >> position;
			            list.deleteNodeAtPosition(position);
			            break;
			        case 'd':
			            cout << "Enter a value to delete and its duplicates: ";
			            cin >> value;
			            list.deleteNodeWithValue(value);
			            break;
			        default:
			            cout << "\nError! Invalid delete option." << endl;
			            break;
			    }
			    break;
            case 'c':
                list.displayList();
                break;
            case 'd':
                cout << "Enter a value to search: ";
                cin >> value;
                list.searchValue(value);
                break;
            case 'e':
                cout << "Exiting program..." << endl;
                exit(0);
            default:
                cout << "\nError! Invalid option." << endl;
                break;
        }
    }

    return 0;
}

