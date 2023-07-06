#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class LinkedList {
private:
    Node* head;

    Node* createNode(int value) {
        return new Node(value);
    }

    void displayIdenticalElements(Node* resultHead, int value) {
        if (resultHead == NULL) {
            cout << "No node with value '" << value << "' found." << endl;
            return;
        }

        cout << "Node(s) with value '" << value << "' found at position(s): ";
        Node* current = resultHead;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

public:
    LinkedList() {
        head = NULL;
    }

    void insertNodeAtBeginning(int value) {
        Node* newNode = createNode(value);
        newNode->next = head;
        head = newNode;
        cout << "Node inserted at the beginning." << endl;
    }

    void insertNodeAtEnd(int value) {
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

    void insertNodeAtPosition(int value, int position) {
        if (position <= 0) {
            cout << "Invalid position. Node not inserted." << endl;
            return;
        }

        if (position == 1) {
            insertNodeAtBeginning(value);
            return;
        }

        Node* newNode = createNode(value);
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

        delete current->next;
        current->next = NULL;
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
            deleteNodeAtBeginning();
            return;
        }

        Node* current = head;
        Node* previous = NULL;
        int count = 1;

        while (current != NULL && count < position) {
            previous = current;
            current = current->next;
            count++;
        }

        if (current == NULL) {
            cout << "Invalid position. Node not deleted." << endl;
            return;
        }

        previous->next = current->next;
        delete current;

        cout << "Node deleted from position " << position << "." << endl;
    }

    void deleteNodeWithValue(int value) {
        if (head == NULL) {
            cout << "List is empty. Cannot delete node." << endl;
            return;
        }

        Node* current = head;
        Node* previous = NULL;
        Node* nextNode = NULL;
        int count = 0;

        while (current != NULL) {
            nextNode = current->next;

            if (current->data == value) {
                if (previous == NULL) {
                    head = nextNode;
                } else {
                    previous->next = nextNode;
                }

                delete current;
                count++;
            } else {
                previous = current;
            }

            current = nextNode;
        }

        if (count > 0) {
            cout << count << " node(s) with value '" << value << "' deleted." << endl;
        } else {
            cout << "No node with value '" << value << "' found." << endl;
        }
    }
    
    void displayList() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        cout << "Linked List: ";
        Node* current = head;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void compareWithHighestValue() {
    if (head == NULL) {
        cout << "List is empty. Cannot compare." << endl;
        return;
    }

    Node* current = head;
    int firstValue = current->data;
    int lastValue = current->data;

    while (current->next != NULL) {
        current = current->next;
        lastValue = current->data;
    }

    if (firstValue > lastValue) {
        cout << "The first value (" << firstValue << ") is higher than the last value (" << lastValue << ")." << endl;
    } else if (firstValue < lastValue) {
        cout << "The last value (" << lastValue << ") is higher than the first value (" << firstValue << ")." << endl;
    } else {
        cout << "The first value (" << firstValue << ") and the last value (" << lastValue << ") are equal." << endl;
    }
	}
};

int main() {
    LinkedList list;
    int value;
    int dataCount = 0;
    cout << "Enter 5 elements to populate the list:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> value;
        list.insertNodeAtEnd(value);
        dataCount++;
    }

    char option;
    while (true) {
        cout << "\nLINKED LIST Data Structure" << endl;
        cout << "[a] Add" << endl;
        cout << "[b] Delete" << endl;
        cout << "[c] Display" << endl;
        cout << "[d] Exit" << endl;
        cout << "Choose an option: ";
        cin >> option;

        switch (option) {
            case 'a': {
                char subOption;
                cout << "\nChoose a sub-option:" << endl;
                cout << "[a] Add" << endl;
                cout << "[b] Display" << endl;
                cout << "[c] Compare" << endl;
                cout << "Choose a sub-option: ";
                cin >> subOption;

                switch (subOption) {
                    case 'a': {
                        char add_subOption;
                        cout << "\nChoose a sub-option:" << endl;
                        cout << "[a] Add node at the beginning" << endl;
                        cout << "[b] Add node at the end" << endl;
                        cout << "[c] Add node at a specific position" << endl;
                        cout << "Choose a sub-option: ";
                        cin >> add_subOption;

                        switch (add_subOption) {
                            case 'a':
                                cout << "Enter a value to insert at the beginning: ";
                                cin >> value;
                                list.insertNodeAtBeginning(value);
                                dataCount++;
                                break;

                            case 'b':
                                cout << "Enter a value to insert at the end: ";
                                cin >> value;
                                list.insertNodeAtEnd(value);
                                dataCount++;
                                break;

                            case 'c': {
                                int position;
                                cout << "Enter a value to insert: ";
                                cin >> value;
                                cout << "Enter the position to insert (1-" << dataCount + 1 << "): ";
                                cin >> position;
                                list.insertNodeAtPosition(value, position);
                                dataCount++;
                                break;
                            }

                            default:
                                cout << "Invalid sub-option. Try again." << endl;
                                break;
                        }
                        break;
                    }

                    case 'b':
                        list.displayList();
                        break;

                    case 'c':
                        list.compareWithHighestValue();
                        break;

                    default:
                        cout << "Invalid sub-option. Try again." << endl;
                        break;
                }
                break;
            }

            case 'b': {
                char del_suboption;
                cout << "\nChoose a sub-option:" << endl;
                cout << "[a] Display" << endl;
                cout << "[b] Delete" << endl;
                cout << "Choose a sub-option: ";
                cin >> del_suboption;

                switch (del_suboption) {
                    case 'a':
                        list.displayList();
                        break;

                    case 'b': {
                        char subOption2;
                        cout << "\nChoose a sub-option:" << endl;
                        cout << "[a] Delete duplication" << endl;
                        cout << "[b] Delete node at the beginning" << endl;
                        cout << "[c] Delete node at the end" << endl;
                        cout << "[d] Delete node at a specific position" << endl;
                        cout << "Choose a sub-option: ";
                        cin >> subOption2;

                        switch (subOption2) {
                            case 'b':
                                list.deleteNodeAtBeginning();
                                dataCount--;
                                break;

                            case 'c':
                                list.deleteNodeAtEnd();
                                dataCount--;
                                break;

                            case 'd': {
                                int position;
                                cout << "Enter the position to delete (1-" << dataCount << "): ";
                                cin >> position;
                                list.deleteNodeAtPosition(position);
                                dataCount--;
                                break;
                            }

                            case 'a': {
                                cout << "Enter a value to delete: ";
                                cin >> value;
                                list.deleteNodeWithValue(value);
                                dataCount--;
                                break;
                            }

                            default:
                                cout << "Invalid sub-option. Try again." << endl;
                                break;
                        }
                        break;
                    }

                    default:
                        cout << "Invalid option. Try again." << endl;
                        break;
                }
                break;
            }

            case 'c':
                list.displayList();
                break;

            case 'd':
                exit(0);

            default:
                cout << "Invalid option. Try again." << endl;
                break;
        }
    }

    return 0;
}
