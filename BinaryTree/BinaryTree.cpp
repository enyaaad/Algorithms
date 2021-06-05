#include <iostream>
#include <queue>
#include <iomanip>
using namespace std;

class Tree {
public:
    int value = 0;
    Tree* left = nullptr;
    Tree* right = nullptr;
 
    Tree() { }
    Tree(int value) {
        this->value = value;
    }

    void SetValue(int value) {
        this->value = value;
    }
    Tree* Push(const int value, bool* alreadyPushed) {
        Tree* newList = new Tree(value);
        Tree* temp = this; // корень

        while (true) {
            if (value == temp->value) { // проверка значения на местоположение в корне
                *alreadyPushed = false;
                return this;
            }
            if (value < temp->value) { // если значение меньше n, то добавление в левое поддерево
                if (temp->left == nullptr) {
                    temp->left = newList;
                    *alreadyPushed = true;
                    return this;
                }
                temp = temp->left;
            }
            if (value > temp->value) { // если значение больше n, то добавление в правое поддерево
                if (temp->right == nullptr) {
                    temp->right = newList;
                    *alreadyPushed = true;
                    return this;
                }
            }
            temp = temp->right;
        }
    }
    Tree* Delete(const int value, bool* Deleted, bool* Existence) {
        Tree* current = this;
        Tree* parent = nullptr;

        while (current != nullptr && current->value != value) {
            parent = current;
            if (value < current->value) // сравниваем значение и ходим по дереву
                current = current->left;
            else
                current = current->right;
        }

        if (current == nullptr)
        {
            *Deleted = false;
            return this;
        }

        if (current->left == nullptr) {
            if (this == current) {
                if (this->right == nullptr) {
                    *Existence = false;
                    *Deleted = true;
                }
                else {
                    *this = *current->right;
                    *Deleted = true;
                }
            }
        }

        if (current->right == nullptr) {
            if (this == current) {
                *this = *current->left;
                *Deleted = true;
                return this;
            }

            if (parent != nullptr && parent->left == current)
                parent->left = current->left;

            if (parent != nullptr && parent->right == current)
                parent->right = current->left;

            delete current;
            *Deleted = true;

            return this;
        }
        Tree* replace = current->right;

        while (replace->left != nullptr)
            replace = replace->left;

        int replaceValue = replace->value;
        this->Delete(replaceValue, Deleted, Existence);
        current->value = replaceValue;
    }
    bool SearchList(int value) {
        Tree* current = this;

        while (current != nullptr && current->value != value) {
            if (value < current->value)
                current = current->left;

            if (value > current->value)
                current = current->right;
        }
        if (current == nullptr) {
            return false;
        }
        else {
            return true;
        }

    }
    void PrintTree(int space = 0) {
        if (this != nullptr) {

            if (this->right != nullptr)
                this->right->PrintTree(space + 4);

            if (space) {
                cout << setw(space) << " ";
            }

            if (this->right != nullptr)
                cout << " /\n" << setw(space) << " ";

            cout << this->value << endl;

            if (this->left != nullptr) {
                cout << setw(space) << " " << " \\\n";
                this->left->PrintTree(space + 4);
            }
        }
    
    }
};
    void ShowMenu() {
        system("chcp 1251");
        cout << "М Е Н Ю:" << endl;
        cout << "  0 - Показать меню" << endl;
        cout << "  1 - Создать дерево" << endl;
        cout << "  2 - Вставить элемент" << endl;
        cout << "  3 - Удалить элемент" << endl;
        cout << "  4 - Существует ли элемент" << endl;
        cout << "  5 - Вывести дерево" << endl;
        cout << "  6 - Выйти" << endl;
    }

    int main() {
        ShowMenu();
        setlocale(LC_ALL, "Russian");
        
        Tree* tree = new Tree();
        int answer = 0, value = 0;
        bool Existence = false, isTreeAlreadyCreated = false;

        while (1) {
            cout << "   Выберите элемент меню: ";
            cin >> answer;

            switch (answer)
            {
            case 0: {
                cout << endl;
                ShowMenu();
            }break;
            case 1: {
                if (isTreeAlreadyCreated == false) {
                    cout << "Введите корень: ";
                    cin >> value;

                    tree->SetValue(value);

                    Existence = true;
                    cout << "Дерево создано!" << endl;

                    isTreeAlreadyCreated = true;
                }
                else
                    cout << "Дерево уже существует!" << endl;
            }break;
            case 2: {
                if (Existence == true) {
                    bool isPushed = false;

                    cout << "Введите значение: ";
                    cin >> value;

                    tree->Push(value, &isPushed);

                    if (isPushed == true)
                        cout << "Значение добавлено!" << endl;
                    else
                        cout << "Значение уже существует!" << endl;
                }
                else
                    cout << "Дерева не существует!" << endl;
            }break;
            case 3: {
                if (Existence == true) {
                    bool isDeleted = false;

                    cout << "Введите значение: ";
                    cin >> value;

                    tree->Delete(value, &isDeleted, &Existence);

                    if (Existence == false)
                        isTreeAlreadyCreated = false;

                    if (isDeleted == true)
                        cout << "Значение удалено!" << endl;
                    else
                        cout << "Значения не существует!" << endl;
                }
                else
                    cout << "Дерева не существует!" << endl;
            }break;
            case 4: {
                if (Existence == true) {
                    cout << "Введите значение: ";
                    cin >> value;

                    if (tree->SearchList(value) == true)
                        cout << "Значение в дереве существует!" << endl;
                    else
                        cout << "Значение в дереве не существует!" << endl;
                }
                else
                    cout << "Дерева не существует!" << endl;
            }break;
            case 5: {
                if (Existence == true) {
                    cout << endl;
                    tree->PrintTree();
                    cout << endl;
                }
                else
                    cout << "Дерева не существует!" << endl;
            }break;
            case 6: {
                exit(1);
            }break;
            default:
                break;
            }
        }

        return 0;
    }