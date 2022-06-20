#include <iostream>
using namespace std;

void backtrack_fucnc(int i, int n, int** graph, int* arr)
{
    for (int j = 0; j < n; j++)
    {
        if (graph[i][j] == 1 && i != j && arr[j] != 1)
        {
            arr[j] = 1;
            backtrack_fucnc(j, n, graph, arr);
        }
    }
}


void main()
{
    setlocale(LC_ALL, "rus");
    int n;
    cout << "Введите количество вершин графа: ";
    cin >> n;
    int** graph = new int* [n];
    for (int i = 0; i < n; i++)
        graph[i] = new int[n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cout << "Введите '1', если из вершины " << i + 1 << " идет ребро в вершину " << j + 1 << endl;
            int s;
            cin >> s;
            if (s == 1)
                graph[i][j] = 1;
            else graph[i][j] = 0;
        }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << graph[i][j] << " ";
        cout << endl;
    }
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
        arr[i] = 0;
    int vert;
    cout << "Введите веришну графа, из которой хотите найти недостижимые точки: ";
    cin >> vert;
    arr[vert - 1] = 1;
    backtrack_fucnc(vert - 1, n, graph, arr);
    for (int i = 0; i < n; i++)
        if (arr[i] == 0)
        {
            bool log = true;
            cout << "Вершины(а) ";
            for (int i = 0; i < n; i++)
                if (arr[i] == 0)
                {
                    if (log == false) cout << ", ";
                    cout << i + 1;
                    log = false;
                }
            cout << " недостижимы(а) из " << vert;
            return;
        }
    cout << "Недостижимых вершин из вершины " << vert << " нет";
    return;
}
