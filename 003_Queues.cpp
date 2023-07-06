//BARICAN, John Andrei A. (CS-1302)
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct Queue {
    Node* front;
    Node* rear;
};

void InitializeQueue(Queue& queue) {
    queue.front = NULL;
    queue.rear = NULL;
}

bool IsQueueEmpty(const Queue& queue) {
    return (queue.front == NULL);
}

void Enqueue(Queue& queue, int user_input) {
    Node* newNode = new Node;
    newNode->data = user_input;
    newNode->next = NULL;

    if (IsQueueEmpty(queue)) {
        queue.front = newNode;
        queue.rear = newNode;
    } else {
        queue.rear->next = newNode;
        queue.rear = newNode;
    }

    cout << "\nElement enqueued successfully." << endl;
}

void Dequeue(Queue& queue) {
    if (IsQueueEmpty(queue)) {
        cout << "Queue is empty. Cannot dequeue elements." << endl;
        return;
    }

    Node* temp = queue.front;
    int removed_element = temp->data;

    queue.front = queue.front->next;
    delete temp;

    if (queue.front == NULL) {
        queue.rear = NULL;
    }

    cout << "Element dequeued successfully. Removed element: " << removed_element << endl;
}

void DisplayQueue(const Queue& queue) {
    if (IsQueueEmpty(queue)) {
        cout << "\nQueue is empty." << endl;
        return;
    }

    cout << "\nCurrent elements in the queue: ";
    Node* current = queue.front;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void Search(const Queue& queue, int target) {
    if (IsQueueEmpty(queue)) {
        cout << "\nQueue is empty. Cannot search elements." << endl;
        return;
    }

    Node* current = queue.front;
    int index = 0;
    bool found = false;

    cout << "Element found at index position(s): ";
    while (current != NULL) {
        if (current->data == target) {
            cout << index << " ";
            found = true;
        }

        current = current->next;
        index++;
    }

    if (!found) {
        cout << "Element not found." << endl;
    }

    cout << endl;
}

int Largest_data(const Queue& queue) {
    if (IsQueueEmpty(queue)) {
        cout << "\nQueue is empty. Cannot find the largest element." << endl;
        return -1;
    }

    Node* current = queue.front;
    int largest = current->data;

    while (current != NULL) {
        if (current->data > largest) {
            largest = current->data;
        }

        current = current->next;
    }

    return largest;
}

int main() {
    Queue queue;
    InitializeQueue(queue);

    for (int i = 0; i < 5; i++) {
        int user_input;
        cout << "Enter an integer: ";
        cin >> user_input;
        Enqueue(queue, user_input);
    }

    while (true) {
        char option;

        cout << "\n\nQUEUE Data Structure\n";
        cout << "[a] Add\n";
        cout << "[b] Delete\n";
        cout << "[c] Search\n";
        cout << "[d] Display\n";
        cout << "[e] Largest Integer\n";
        cout << "[f] Exit\n";
        cout << "Choose a letter: ";
        cin >> option;

        switch (option) {
            case 'a': {
                int user_input;
                cout << "Enter an integer: ";
                cin >> user_input;
                Enqueue(queue, user_input);
                break;
            }
            case 'b': {
                Dequeue(queue);
                break;
            }
            case 'c': {
                int target;
                cout << "Enter an integer to search: ";
                cin >> target;
                Search(queue, target);
                break;
                break;
            }
            case 'd': {
                DisplayQueue(queue);
                break;
            }
            case 'e':{
            	int largest = Largest_data(queue);
                if (largest != -1) {
                    cout << "Largest element in the queue: " << largest << endl;
                }
				break;
			}
			case 'f':{
				exit(0);
				break;
			}
            default:
                cout << "\nError! Invalid option." << endl;
        }
    }

    return 0;
}
