#include <iostream>
using namespace std;

const int MAX = 100;

class Queue {
    int queue[MAX];
    int front, rear;

public:
    Queue() {
        front = rear = -1;
    }

    void qinsert(int item) {
        if (rear == MAX - 1) {
            cout << "\nQUEUE OVERFLOW";
        } else if (front == -1 && rear == -1) {
            front = rear = 0;
            queue[rear] = item;
            cout << "\nITEM INSERTED: " << item;
        } else {
            rear++;
            queue[rear] = item;
            cout << "\nITEM INSERTED: " << item;
        }
    }

    void qdelete() {
        int item;

        if (rear == -1) {
            cout << "\nQUEUE UNDERFLOW";
        } else if (front == 0 && rear == 0) {
            item = queue[front];
            front = rear = -1;
            cout << "\n\nITEM DELETED: " << item;
        } else {
            item = queue[front];
            front++;
            cout << "\n\nITEM DELETED: " << item;
        }
    }

    void qtraverse() {
        if (front == -1) {
            cout << "\n\nQUEUE IS EMPTY\n";
        } else {
            cout << "\n\nQUEUE ITEMS\n";
            for (int i = front; i <= rear; i++) {
                cout << queue[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Queue q;
    int item;
    char choice;

    while (true) {
        cout << "\nQueue\n";
        cout << "[a] Insert item\n";
        cout << "[b] Delete item\n";
        cout << "[c] Display all items\n";
        cout << "[d] Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 'a':
                cout << "Enter the item to insert: ";
                cin >> item;
                q.qinsert(item);
                break;
            case 'b':
                q.qdelete();
                break;
            case 'c':
                q.qtraverse();
                break;
            case 'd':
                exit(0);
            default:
                cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}

