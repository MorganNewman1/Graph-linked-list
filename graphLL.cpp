
// Partial program
// Partial program
// Binary Search Tree - object oriented approach

#include <iostream>
#include <fstream>
#include "llla.h"
using namespace std;
int main(int argc, char *argv[]){
    lheader * graph;
    int i, n, j;
    int v;
    int k, p;
    std::ifstream ifp;
    ifp.open(argv[1],std::ifstream::in);
    ifp >> n;
    graph = (lheader*)malloc(n * sizeof(lheader));

    for(i = 0; i < n; i++) {
        graph[i].start = NULL;
        graph[i].len = 0;
    }
    ifp >> v;
    //ifp >>c;

    for(i = 0; i < v; i++) {
        ifp >> k;
        ifp >> p;

        insertBack(&(graph[k-1]),p);
        insertBack(&(graph[p-1]),k);
    }

    for(i = 1; i <= n; i++) {
        cout << i << ": ";
        for(j = 1; j <= n; j++)
            if(isInList(&(graph[i-1]),j))
                cout << j << " ";
        cout << endl;
    }

    ifp.close();

    return 0;
}