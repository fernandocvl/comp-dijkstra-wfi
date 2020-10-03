#include <iostream>
#include <bits/stdc++.h>
#include <limits.h>
#include <stdio.h>
#include <chrono>
#include <windows.h>
#include <cstdlib>
#include <cstdlib>
#include <conio.h>

using namespace std;
#define INF 99999           //infinity value for WFI
int **graph, **graphwfi;    //matrix global declaration

//######################################################################################################################################
//minimal distance dijjstra aux function
int minDistance(int dist[], int V, bool sptSet[])
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
    {
        if (sptSet[v] == false && dist[v] <= min)
        {
            min = dist[v], min_index = v;
        }
    }
    return min_index;
}
//######################################################################################################################################
// dijkstra algorithm
void dijkstra(int V, int src)
{
    Sleep(2);
    int dist[V];    //distances
    bool sptSet[V]; //shortest paths
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX, sptSet[i] = false;
    }
    dist[src] = 0;
    //search spt
    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, V, sptSet);
        sptSet[u] = true;
        for (int v = 0; v < V; v++)
        {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    cout << "DIJKSTRA: Distance 1st->Last: " << dist[V-1] << endl;
    Sleep(2);
}

//######################################################################################################################################
//floyd-warshall-ingerman-roy
void floydwarshall(int V)
{
    Sleep(2);
    int i, j, k;

    for (k = 0; k < V; k++)
    {
        for (i = 0; i < V; i++)
        {
            for (j = 0; j < V; j++)
            {
                if (graphwfi[i][k] + graphwfi[k][j] < graphwfi[i][j])
                    graphwfi[i][j] = graphwfi[i][k] + graphwfi[k][j];
            }
        }
    }
    cout << "FLOYD-WARSHALL: Distance 1st->Last: " << graphwfi[0][V-1] << endl;
    Sleep(2);
}

//######################################################################################################################################
//main program
int main()
{
    int i,j,m,n,numVert;            //integers
    fstream file;                   //filestream variable file
    string word, t, q, filename;    //strings

    //menu
    system("CLS");
    cout << "COMPARAÇÃO - DIJKSTRA-WFI" << endl;
    cout << "ESCOLHA UMA ENTRADA PARA PROCESSAR" << endl;
    cout << "1 - Entrada 10" << endl;
    cout << "2 - Entrada 25" << endl;
    cout << "3 - Entrada 50" << endl;
    cout << "4 - Entrada 75" << endl;
    cout << "5 - Entrada 100" << endl;
    cout << "6 - Entrada 150" << endl;
    cout << "7 - Entrada 200" << endl;
    cout << "8 - Entrada 250" << endl;
    cout << "9 - Entrada 300" << endl;
    cout << "10 - Entrada 400" << endl;
    cout << "11 - Entrada 500" << endl;
    cout << "12 - Entrada 650" << endl;
    cout << "13 - Entrada 800" << endl;
    cout << "14 - Entrada 1000" << endl;
    cout << "15 - Entrada 1500" << endl;

    std::string choice;
    std::cin >> choice;

    if(choice == "1")
    {
        system("cls");
        filename = "Entrada 10.txt";
    }
    else if(choice == "2")
    {
        system("cls");
        filename = "Entrada 25.txt";
    }
    else if(choice == "3")
    {
        system("cls");
        filename = "Entrada 50.txt";
    }
    else if(choice == "4")
    {
        system("cls");
        filename = "Entrada 75.txt";
    }
    else if(choice == "5")
    {
        system("cls");
        filename = "Entrada 100.txt";
    }
    else if(choice == "6")
    {
        system("cls");
        filename = "Entrada 150.txt";
    }
    else if(choice == "7")
    {
        system("cls");
        filename = "Entrada 200.txt";
    }
    else if(choice == "8")
    {
        system("cls");
        filename = "Entrada 250.txt";
    }
    else if(choice == "9")
    {
        system("cls");
        filename = "Entrada 300.txt";
    }
    else if(choice == "10")
    {
        system("cls");
        filename = "Entrada 400.txt";
    }
    else if(choice == "11")
    {
        system("cls");
        filename = "Entrada 500.txt";
    }
    else if(choice == "12")
    {
        system("cls");
        filename = "Entrada 650.txt";
    }
    else if(choice == "13")
    {
        system("cls");
        filename = "Entrada 800.txt";
    }
    else if(choice == "14")
    {
        system("cls");
        filename = "Entrada 1000.txt";
    }
    else if(choice == "15")
    {
        system("cls");
        filename = "Entrada 1500.txt";
    }
    else
    {
        cout << "Choose a valid option!" << endl;
        system("pause");
    }

    system("CLS");

    // opening file
    file.open(filename.c_str());

    if(file.is_open())
    {
        cout << filename << " is open." << endl;
    }
    else
    {
        cout << filename << " failed to open!" << endl;
    }

    // extracting words from the file
    file >> word;
    cout << "Size: " << word << endl;
    numVert = stoi(word);
    m = stoi(word);
    n = stoi(word);

    // Allocate space for the matrix
    graph = new int* [m];
    graphwfi = new int* [m];
    for(i = 0; i < m; i++)
    {
        graph[i] = new int[n];
        graphwfi[i] = new int[n];
    }
    if(!graph || !graphwfi)
    {
        cerr << "Can't allocate space!" << endl;
        return 1;
    }

    cout << "Processing matrix..." << endl;
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            file >> word;
            graph[i][j] = stoi(word);
            if(i == j)
            {
                graphwfi[i][j] = 0;
            }
            else if(stoi(word) == 0)
            {
                graphwfi[i][j] = 99999;
            }
            else
            {
                graphwfi[i][j] = stoi(word);
            }
        }
    }

    cout << "Matrix inputed!\n";

    //executa dijkstra para a matriz de entrada
    auto dstr = std::chrono::high_resolution_clock::now();
    dijkstra(numVert, 0);
    cout << "RUNTIME: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-dstr).count() << " ms " << std::endl;

    //executa floyd-warshall para a matriz de entrada
    auto fstr = std::chrono::high_resolution_clock::now();
    floydwarshall(numVert);
    cout << "RUNTIME: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-fstr).count() << " ms " << std::endl;

    delete [] graph;
    delete [] graphwfi;

    return 0;
}
