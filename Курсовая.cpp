#include <iostream>

class Node {
public:
    int key;
    Node* p;

    // Конструктор по умолчанию
    Node() {
        key = 0;
        p = nullptr;
    }

    // Конструктор с параметрами
    Node(int k, Node* next) {
        key = k;
        p = next;
    }

    // Деструктор
    ~Node() {
        // нет необходимости освобождать память,
        // так как в данном примере не было использовано оператора new
    }
};

class Stack {
private:
    Node* top;
    int size;

public:
    // Конструктор по умолчанию
    Stack() {
        top = nullptr;
        size = 0;
    }

    // Деструктор
    ~Stack() {
        removeAll();
    }

    // Проверка, является ли стек пустым
    bool isEmpty() {
        return(top == nullptr);
    }

    // Проверка, является ли стек переполненным
    bool isFull() {
        // в данной реализации стека нет ограничений по размеру
        return false;
    }

    // Копирование всего стека в новый объект
    Stack copy() {
        Stack newStack;
        Node* current = top;
        while (current != nullptr) {
            newStack.push(current->key);
            current = current->p;
        }
        return newStack;
    }

    // Добавление элемента в стек
    void push(int value) {
        Node* newNode = new Node(value, top);
        top = newNode;
        size++;
    }

    // Удаление элемента из стека и его вывод на экран
    int pop() {
        if (isEmpty()) {
            std::cout << "Стек удален" << std::endl;
            return 0;
        }
        int value = top->key;
        Node* temp = top;
        top = top->p;
        delete temp;
        size--;
        return value;
    }

    // Удаление всего стека
    void removeAll() {
        while (!isEmpty()) {
            pop();
        }
    }

    // Вывод информации о длине стека
    void printLength() {
        std::cout << "Длина стека: " << size << std::endl;
    }

    // Вывод стека в терминал
    void print() {
        Node* current = top;
        while (current != nullptr) {
            std::cout << current->key << " ";
            current = current->p;
        }
        std::cout << std::endl;
    }
};

int main() {
    Stack stack;
    int choice;
    setlocale(LC_ALL, "RU");

    do {
        std::cout << "1. Добавить элемент элемент\n";
        std::cout << "2. Удалить элемент\n";
        std::cout << "3. Удалить весь стек\n";
        std::cout << "4. Вывести длину стека\n";
        std::cout << "5. Вывести стек\n";
        std::cout << "6. Копировать стек\n";
        std::cout << "7. Выйти\n";
        std::cout << "Выберите операцию: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            int value;
            std::cout << "Введите значение для удаления: ";
            std::cin >> value;
            stack.push(value);
            break;
        }
        case 2: {
            int value = stack.pop();
            std::cout << "Удаленный элемент: " << value << std::endl;
            break;
        }
        case 3: {
            stack.removeAll();
            std::cout << "Удаленный стек" << std::endl;
            break;
        }
        case 4: {
            stack.printLength();
            break;
        }
        case 5: {
            stack.print();
            break;
        }
        case 6: {
            Stack newStack; 
            myStack.copy(newStack); 
            std::cout << "Новый стек создан." << std::endl;
            break;
        }   
        case 7: {
            std::cout << "Выход..." << std::endl;
            break;
        }
        default: {
            std::cout << "Invalid choice" << std::endl;
            break;
        }
        }

        std::cout << std::endl;
    } while (choice != 0);

    return 0;
}
