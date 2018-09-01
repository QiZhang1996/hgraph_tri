//
// Created by Rose on 2018/8/15.
//

#ifndef MYTRIANGLE_TRIANGLE_H
#define MYTRIANGLE_TRIANGLE_H

#define MAX_VERTEX 1000
#define MAX_EDGE 5000

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <fstream>
#include <map>
#include "tool.h"

using namespace std;

class Triangle {

public:

    vector<vector<int>> graph;

    int E,V;

    int t;
public:
    int getT() const;

public:

    unordered_map<EdgeClass, int, EdgeHash, EdgeEqualTo> EdgeMap;

    unordered_map<EdgeClass, int, EdgeHash, EdgeEqualTo> P;

    unordered_map<int, int> degree;

public:

    const unordered_map<int, int> &getH() const;

public:
    unordered_map<int, int> H;

    int h;

    vector<int> B;

    multimap<int, int> CMap;

public:
    const unordered_map<int, int> &getDegree() const;

public:

    Triangle(){

        E = V = 0;
        h = 0;
        t = 0;
        graph.resize(MAX_VERTEX+1);

    }

    int readgraph(const char *str);

    int insertVertex(int x, int deg);
    int removeVertex(int x);

    int insertEdge(int x, int y);
    int removeEdge(int x, int y);


    int buildHindex();


    int print_gethindex();
    void print_getH();
    void print_getB();
    void print_getC();
    void print_getP();
    int gethindex();

};


#endif //MYTRIANGLE_TRIANGLE_H
