/*
Gaddiel Mohamed Pedroza Martinez
Stephanie Paola Perez Ramirez 
Anabel Romo Esparza
Ariadna Vargas Medina 
Materia: Estructuras computacionales avanzadas
Floyd-Warshallfunciona con pesos negativos pero no con ciclos negativos
*/
#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e8; //numero muy grande ( el 100000 daba problemas)
void floydWarshall(vector<vector<int>> &dist) {
    int V = dist.size();
    for (int k=0;k<V;k++) {
        for (int i=0;i<V;i++) {
            for (int j=0;j<V;j++) {
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]); // 
                }
            }
        }
    }
}

int main() {
    int num;
    cout << "Numero de nodos:\n ";
    cin >> num;
    vector<vector<int>> dist(num, vector<int>(num));
    cout << "\nIngresa la matriz de adyacencia (usa -1 si no hay conexión):\n";
    for (int i=0;i<num;i++) {
        for (int j=0;j<num;j++) {
            int n;
            cin >> n;
            if (n==-1)
                dist[i][j]=INF;
            else
                dist[i][j]=n;
        }
    }
    floydWarshall(dist);
    cout << "\n Matriz de distancias mas cortas entre todos los pares de nodos:\n\n";
    for (int i=0;i<num;i++) {
        for (int j=0;j<num;j++) {
            if (dist[i][j]>=INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

/*
4

0   2  -1  5
-1  0   4 -1
1  -1   0 -1
-1 -1   3  0
*/