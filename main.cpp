#include <iostream>
#include "Triangle.h"

using namespace std;

void testprint(Triangle hindex2){

    cout << "t----------" << hindex2.getT() << endl;
    cout << "h = " << hindex2.print_gethindex() << endl;
    //hindex2.print_getB();
    hindex2.print_getH();
    //hindex2.print_getC();
    hindex2.print_getP();


}

int main() {

//    Triangle hindex, hindex2;
//    //hindex.readgraph("../graphfile.txt");
//
//    //hindex.buildHindex();
//
////    hindex2.insertVertex(1, 2);
////    hindex2.insertVertex(2, 4);
////    hindex2.insertVertex(3, 4);
////    hindex2.insertVertex(4, 2);
////    hindex2.insertVertex(5, 4);
////    hindex2.insertVertex(6, 5);
////    hindex2.insertVertex(7, 3);
////    hindex2.insertVertex(8, 3);
////    hindex2.insertVertex(9, 3);
//
//    hindex2.insertEdge(1, 2);
//    testprint(hindex2);
//
//    hindex2.insertEdge(2, 3);
//    testprint(hindex2);
//    hindex2.insertEdge(2, 4);
//    testprint(hindex2);
//    hindex2.insertEdge(2, 7);
//    testprint(hindex2);
//    hindex2.insertEdge(2, 12);
//    testprint(hindex2);
//    hindex2.insertEdge(3, 4);
//    testprint(hindex2);
//    hindex2.insertEdge(3, 5);
//    testprint(hindex2);
//    hindex2.insertEdge(3, 6);
//    testprint(hindex2);
//    hindex2.insertEdge(3, 7);
//    testprint(hindex2);
//    hindex2.insertEdge(6, 7);
//    testprint(hindex2);
//    hindex2.insertEdge(6, 8);
//    testprint(hindex2);
//    hindex2.insertEdge(6, 11);
//    testprint(hindex2);
//    hindex2.insertEdge(8, 9);
//    testprint(hindex2);
//    hindex2.insertEdge(8, 10);
//    testprint(hindex2);
//    hindex2.insertEdge(8, 12);
//    testprint(hindex2);
//    hindex2.insertEdge(9, 10);
//    testprint(hindex2);
//    hindex2.insertEdge(9, 11);
//    testprint(hindex2);
//    hindex2.insertEdge(10, 12);
//
//
//    cout << "t----------" << hindex2.getT() << endl;
//    cout << "h = " << hindex2.print_gethindex() << endl;
//    //hindex2.print_getB();
//    hindex2.print_getH();
//    //hindex2.print_getC();
//    hindex2.print_getP();
//
//    hindex2.insertEdge(9, 12);
//
//    cout << "t----------" << hindex2.getT() << endl;
//    cout << "h = " << hindex2.print_gethindex() << endl;
//    //hindex2.print_getB();
//    hindex2.print_getH();
//    //hindex2.print_getC();
//    hindex2.print_getP();
//
//    hindex2.removeEdge(9, 12);
//
//    cout << "t----------" << hindex2.getT() << endl;
//    cout << "h = " << hindex2.print_gethindex() << endl;
//    //hindex2.print_getB();
//    hindex2.print_getH();
//    //hindex2.print_getC();
//    hindex2.print_getP();
//
////    cout << "h = " << hindex2.print_gethindex() << endl;
////    hindex2.print_getB();
////    hindex2.print_getH();
////    hindex2.print_getC();
//    cout << endl;

    Triangle hindex233;
    hindex233.readgraph("../dolphins.txt");
    cout << "t = " << hindex233.getT() << endl;
    //hindex233.print_getP();

//    for(int i = 1; i <= hindex233.V; i++){
//
//        cout << "V" << i <<": ";
//
//        for(vector<int>::iterator it = hindex233.graph[i].begin(); it != hindex233.graph[i].end(); it++){
//
//            cout << *it << ", ";
//
//        }
//        cout << endl;
//
//
//    }

//    int x = 0;
//    for(int i = 1; i <= hindex233.V; i++){
//
//        cout << "i = " << i << ": ";
//
//        for(vector<int>::iterator it = hindex233.graph[i].begin(); it != hindex233.graph[i].end(); it++){
//            for(vector<int>::iterator it2 = it+1; it2 != hindex233.graph[i].end(); it2++){
//
//                EdgeClass pair1(*it,*it2), pair2(*it2, *it);
//                if(hindex233.EdgeMap.find(pair1) != hindex233.EdgeMap.end() || hindex233.EdgeMap.find(pair2) != hindex233.EdgeMap.end()){
//
//                    if(*it > *it2){
//
//                        cout << "(" << *it2 <<", " << *it << "), ";
//
//                    }
//                    else{
//                        cout << "(" << *it <<", " << *it2 << "), ";
//
//                    }
//                    x = x+1;
//
//                }
//
//            }
//
//
//        }
//        cout << endl;



//    }
//
//
//    cout << x/3 << endl;
    return 0;
}