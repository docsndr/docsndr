#include <iostream>
using namespace std;

struct Node {
    int num;
    Node* next;
};

Node* head = NULL;
Node* tail = NULL;

void insert_Node(int n) {
    Node* new_node = new Node;
    new_node->num = n;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
        tail = new_node;
    } else {
        tail->next = new_node;
        tail = new_node;
    }
}

int count_Nodes() {
    Node* tmp = head;
    int ctr = 0;

    while (tmp != NULL) {
        ctr++;
        tmp = tmp->next;
    }

    return ctr;
}

void display_all_nodes() {
    Node* temp = head;

    while (temp != NULL) {
        cout << "Stored Nodes: " << temp->num << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main() {
    int value;
    char repeat, choice;

    while (true) {
    	cout << endl;
        cout << "Linked List\n";
        cout << "[a] Insert node\n";
        cout << "[b] Count the number of nodes\n";
        cout << "[c] Display all nodes\n";
        cout << "[d] Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 'a':
                cout << "Enter the value to insert: ";
                cin >> value;
                insert_Node(value);
                break;
            case 'b':
                cout << "The number of nodes is: " << count_Nodes() << endl;
                break;
            case 'c':
                display_all_nodes();
                break;
            case 'd':
            	exit(0);
            default:
                cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}

