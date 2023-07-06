#include <iostream>

using namespace std;

struct Stack {
    int* data;
    int top;
    int capacity;
};

void InitializeStack(Stack& stack) {
    stack.data = NULL;
    stack.top = -1;
    stack.capacity = 0;
}

bool IsStackEmpty(const Stack& stack) {
    return (stack.top == -1);
}

void Push(Stack& stack, int user_input) {
    if (stack.top == stack.capacity - 1) {
        int newCapacity = (stack.capacity == 0) ? 1 : stack.capacity * 2;
        int* newData = new int[newCapacity];

        for (int i = 0; i <= stack.top; i++) {
            newData[i] = stack.data[i];
        }

        delete[] stack.data;

        stack.data = newData;
        stack.capacity = newCapacity;
    }

    stack.top++;
    stack.data[stack.top] = user_input;
    cout << "\nElement pushed successfully." << endl;
}

void Pop(Stack& stack) {
    if (IsStackEmpty(stack)) {
        cout << "Stack is empty. Cannot pop elements." << endl;
        return;
    }

    int popped_element = stack.data[stack.top];
    stack.top--;

    if (stack.top < stack.capacity / 2 && stack.capacity > 1) {
        int newCapacity = stack.capacity / 2;
        int* newData = new int[newCapacity];

        for (int i = 0; i <= stack.top; i++) {
            newData[i] = stack.data[i];
        }

        delete[] stack.data;

        stack.data = newData;
        stack.capacity = newCapacity;
    }

    cout << "Element popped successfully. Popped element: " << popped_element << endl;
}

void DisplayStack(const Stack& stack) {
    if (IsStackEmpty(stack)) {
        cout << "\nStack is empty." << endl;
        return;
    }

    cout << "\nCurrent elements in the stack: ";
    for (int i = stack.top; i >= 0; i--) {
        cout << stack.data[i] << " ";
    }
    cout << endl;
}

void ClearStack(Stack& stack) {
    if (stack.data != NULL) {
        delete[] stack.data;
        stack.data = NULL;
        stack.top = -1;
        stack.capacity = 0;
    }
}

int main() {
    Stack stack;
    InitializeStack(stack);

    while (true) {
        char option;

        cout << "\n\nSTACK Data Structure\n";
        cout << "[a] Push\n";
        cout << "[b] Pop\n";
        cout << "[c] Display\n";
        cout << "[d] Exit\n";
        cout << "Choose a letter: ";
        cin >> option;

        switch (option) {
            case 'a': {
                int user_input;
                cout << "Enter an integer: ";
                cin >> user_input;
                Push(stack, user_input);
                break;
            }
            case'b': {
                Pop(stack);
                break;
            }
            case 'c': {
                DisplayStack(stack);
                break;
            }
            case 'd': {
                ClearStack(stack);
                exit(0);
                break;
            }
            default:
                cout << "\nError! Invalid option." << endl;
        }
    }

    return 0;
}

