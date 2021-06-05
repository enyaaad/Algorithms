#include <iostream>
#include <conio.h>

using namespace std;

class Graf
{
private:
    int MaxNodes;
    int* nodes;
    int num_vershina;
    int num_rebro;
    int Last_vershina;

    struct uzel
    {
        int v1;
        int v2;
        int wes;
    }
    *uzels;
public:
    Graf();
    void InitGraf();
    void sort();
    int GetColor(int n);
    void OutTree();

};

Graf::Graf()
{
    MaxNodes = 50;
    nodes = new int[MaxNodes];
    uzels = new uzel[MaxNodes];
}


void Graf::InitGraf()
{
    setlocale(LC_ALL, "Russian");
    cout << "Ввидите число вершин" << endl;
    cin >> num_vershina;
    cout << endl
        << "Введите число ребер" << endl;
    cin >> num_rebro;

    // Задаем начальные цвета вершинам
    for (int i = 0; i < num_vershina; i++)
        nodes[i] = -1 - i;
    cout << endl
        << "Колличество ребер :" << num_rebro << endl
        << "Введите их в формате : вершина 1,вершина 2,вес"
        << endl;
    for (int i = 0; i < num_rebro; i++)
    {
        cout << endl << "Вершина 1 = "; cin >> uzels[i].v1;
        cout << "Вершина 2 = "; cin >> uzels[i].v2;
        cout << "Вес = "; cin >> uzels[i].wes;
    }
    cout << endl << "Граф задан" << endl;
}

// Пузырьковая сортировка
void Graf::sort()
{
    uzel tmp;

    for (int i = 0; i < num_rebro - 1; i++)
        for (int j = 0; j < num_rebro - 1; j++)
            if (uzels[j].wes > uzels[j + 1].wes)
            {
                tmp = uzels[j];
                uzels[j] = uzels[j + 1];
                uzels[j + 1] = tmp;
            }

}

int Graf::GetColor(int n)
{

    if (nodes[n] < 0)
    {
        Last_vershina = n;
        return nodes[Last_vershina];
    }
    else
    {
        int color;
        
        color = GetColor(nodes[n]);
        nodes[n] = Last_vershina;
        return color;
    }

}


void Graf::OutTree()
{
    sort();
    setlocale(LC_ALL, "Russian");

    cout << "Минимальное остовное дерево состоит из ребер с весами " << endl;
    for (int i = 0; i < num_rebro; i++)
    {
        int color1 = GetColor(uzels[i].v2);
        int color2 = GetColor(uzels[i].v1);  

        if (color2 != color1)
        {
            nodes[Last_vershina] = uzels[i].v2;
            cout << endl
                << uzels[i].wes;
        }
    }


}

int main()
{
    setlocale(LC_ALL, "Russian");
    Graf graf;
    int c = 1;

    while (c != 3)
    {

        cout << "Операции" << endl;
        cout << "1. Задать граф" << endl;
        cout << "2. Построить дерево" << endl;
        cout << "3. Выход" << endl;
        cout << ">> " << endl;

        cin >> c;

        switch (c)
        {
        case 1:
            graf.InitGraf();
            break;

        case 2:
            graf.OutTree();
            break;

        case 3:
            break;

        default:
            cout << endl << "Неверный выбор" << endl;
            break;
        }
    }
    return(1);
}