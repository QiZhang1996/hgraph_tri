//
// Created by Rose on 2018/8/15.
//

#include "Triangle.h"


int Triangle::print_gethindex()
{
    return h;
}

void Triangle::print_getH()
{
    cout << "Set H ={";

    for (unordered_map<int, int>::iterator it = H.begin(); it != H.end(); it++) {

        cout << "V" << it->first << ", ";
    }
    cout << "}" << endl;

    return;
}
void Triangle::print_getB()
{
    cout << "Set B ={";
    for (vector<int>::iterator it = B.begin(); it != B.end(); it++) {

        cout << "V" << *it << ", ";
    }
    cout << "}" << endl;
    return;
}
void Triangle::print_getC()
{

//    /*第一种方法*/

    multimap<int, int>::iterator  it = CMap.begin();
    for(it = CMap.begin(); it != CMap.end(); it++){

        cout << "C[" << it->first << "]: " << it->second << endl;


    }

    return;
}

int Triangle::gethindex(){

    return h;


}

void Triangle::print_getP()
{

//    /*第一种方法*/

    unordered_map<EdgeClass, int, EdgeHash, EdgeEqualTo>::iterator it;
    for(it = P.begin(); it != P.end(); it++){

        EdgeClass pair;
        pair = it->first;

        cout << "P:(V" << pair.v1 << ", V"<< pair.v2 << ")：" << it->second << endl;


    }

    cout << "P.size() = " << P.size() << endl;

    return;
}

int Triangle::readgraph(const char *str){

    FILE *in = fopen(str, "r");
    if(in == NULL){

        cout << "files not exist" << endl;
        exit(1);

    }

    fscanf(in ,"%d %d", &V, &E);
    graph.resize(V+1);

    int x = 0, y = 0;


    while(fscanf(in, "%d %d", &x, &y) != EOF){

        insertEdge(x+1, y+1);

    }

    fclose(in);
    return 1;

}

int Triangle::insertVertex(int x, int deg)
{

    //inser deg
    degree[x] = deg;

    //insert C
    CMap.insert(make_pair(deg, x));

    //judge h
    if (deg <= h) {

        //not change h
        return 0;

    }
    else
    {
        //judge B
        if (!B.empty()) {
            //remove y from B and H
            int y = B.at(B.size() - 1);
            B.pop_back();
            H.erase(y);
            CMap.insert(make_pair(h, y));

            H[x] = deg;

        }
        else
        {
            h = h + 1;
            H[x] = deg;
            if(CMap.count(h) != 0){

                B.clear();
                //copy c[h] to B

                multimap<int, int>::size_type  cnt = CMap.count(h);
                multimap<int, int>::iterator  iter = CMap.find(h);
                for(;cnt > 0; cnt--, iter++)
                {

                    B.push_back(iter->second);

                }

                CMap.erase(h);

            }
            else{
                //empty B
                B.clear();

            }

        }
    }
    return 1;

}

int Triangle::removeVertex(int x){

    int dx = degree[x];

    //remove from deg
    degree.erase(x);

    //remove from B
    vector<int>::iterator iter2;

    iter2 = find(B.begin(), B.end(), x);

    if (iter2 != B.end()) {

        B.erase(iter2);

    }
    else
    {
        //remove from C
        multimap<int, int>::size_type  cnt = CMap.count(dx);
        multimap<int, int>::iterator  iter = CMap.find(dx);
        if(iter != CMap.end())
        {

            for(;cnt > 0; cnt--, iter++)
            {

                if(iter->second == x){

                    CMap.erase(iter);

                    break;
                }
            }


        }


    }

    if (H.find(x) == H.end()) {

        return dx;

    }
    else
    {
        //remove from H
        H.erase(x);

        if (CMap.count(h) == 0)
        {
            h = h - 1;
            if (!B.empty())
            {

                for(vector<int>::iterator it = B.begin(); it != B.end(); it++){

                    CMap.insert(pair<int, int>(h + 1, *it));
                }

                B.clear();

            }

        }
        else
        {

            multimap<int, int>::size_type  cnt = CMap.count(h);
            multimap<int, int>::iterator  iter = CMap.find(h);
            int y = iter->second;

            CMap.erase(iter);

            B.push_back(y);

            H.erase(x);

            H[y] = h;

        }

    }
    return dx;

}


int Triangle::insertEdge(int x, int y){

    //cout << "--------------------------------------insert V" << x << " , V" << y << endl;
    int pl,pr;
    if(x > y){
        pl = y;
        pr = x;
    } else{

        pl = x;
        pr = y;
    }

    //find P
    EdgeClass pair(pl, pr);
    unordered_map<EdgeClass, int, EdgeHash, EdgeEqualTo>::iterator itp = P.find(pair);
    if(itp != P.end()) {
        t = t + itp->second;
    }

    //find H
    unordered_map<int, int>::iterator ith;
    for(ith = H.begin(); ith != H.end(); ith++){

        unordered_map<EdgeClass, int, EdgeHash, EdgeEqualTo>::iterator it1, it2, it3, it4;
        int i = ith->first;

        EdgeClass pair1(x, i), pair2(i, x), pair3(y, i), pair4(i, y);

        it1 = EdgeMap.find(pair1);
        it2 = EdgeMap.find(pair2);
        it3 = EdgeMap.find(pair3);
        it4 = EdgeMap.find(pair4);

        if( ((it1 != EdgeMap.end()) || (it2 != EdgeMap.end())) && ((it3 != EdgeMap.end()) || (it4 != EdgeMap.end()))){

            //cout << "In H can get" << endl;
            t = t + 1;

        }

    }

//    //x not in H
    if(H.find(x) == H.end()){

        //cout << "----x:" << x << "not in H" << endl;

        vector<int>::iterator it;

        if(graph[x].empty()){

            //cout << "empty" << endl;

        }
        else
        {
            for(it = graph[x].begin(); it != graph[x].end(); it++){

                int i = *it;
                int pl,pr;
                if(i > y){
                    pl = y;
                    pr = i;
                } else{

                    pl = i;
                    pr = y;

                }

                EdgeClass pair(pl, pr);
                P[pair]++;
                //cout << "p add：" << pl << "+" << pr << endl;

            }

        }


    }
    //y not in H
    if(H.find(y) == H.end()){
        vector<int>::iterator it;
        //cout << "----y:" << y << "not in H" << endl;
        if(graph[y].empty()){

            //cout << "empty" << endl;

        }
        else
        {
            for(it = graph[y].begin(); it != graph[y].end(); it++){

                int i = *it;
                int pl,pr;
                if(i > x){
                    pl = x;
                    pr = i;
                } else{

                    pl = i;
                    pr = x;

                }

                EdgeClass pair(pl, pr);

                P[pair]++;
                //cout << "p add：" << pl << "+" << pr << endl;

            }

        }

    }


    EdgeClass edge(pl, pr);
    EdgeMap[edge] = 1;

    graph[x].emplace_back(y);
    graph[y].emplace_back(x);

    //change deg
    int dx = degree[x] + 1;
    int dy = degree[y] + 1;

    int perH = gethindex();
    unordered_map<int, int> perSetH = getH();

    removeVertex(x);
    insertVertex(x, dx);
    removeVertex(y);
    insertVertex(y, dy);

    //H change, update P for new vertex in H
    int H = gethindex();
    unordered_map<int, int> SetH =getH();

    int flag;

    //update P
    //cout << "update P" << endl;

    for(unordered_map<int, int>::iterator it = SetH.begin(); it != SetH.end(); it++) {
        //find new vertex
        if (perSetH.find(it->first) == perSetH.end()) {

            flag = it->first;
            vector<int>::iterator it1;
            vector<int>::iterator it2;
            for (it1 = graph[flag].begin(); it1 != graph[flag].end(); it1++) {

                for (it2 = it1 + 1; it2 != graph[flag].end(); it2++) {


                    EdgeClass pairl(*it1, *it2);
                    EdgeClass pairr(*it2, *it1);
                    //cout << "P(V" << *it1 << ", V" << *it2 << ") remove " << endl;

                    if (P.find(pairl) != P.end()) {

                        P[pairl]--;
                        if (P[pairl] <= 0) {
                            P.erase(pairl);

                        }

                    }else if(P.find(pairr) != P.end()){

                        P[pairr]--;
                        if (P[pairr] <= 0) {
                            P.erase(pairr);

                        }


                    }

                }

            }

        }
    }

    for(unordered_map<int, int>::iterator it = perSetH.begin(); it != perSetH.end(); it++) {
        //find new vertex
        if (SetH.find(it->first) == SetH.end()) {

            flag = it->first;
            vector<int>::iterator it1;
            vector<int>::iterator it2;
            for (it1 = graph[flag].begin(); it1 != graph[flag].end(); it1++) {

                for (it2 = it1 + 1; it2 != graph[flag].end(); it2++) {


                    EdgeClass pairl(*it1, *it2);
                    EdgeClass pairr(*it2, *it1);
                    //cout << "P(V" << *it1 << ", V" << *it2 << ") add----- " << endl;
                    if(*it1 > *it2){
                        P[pairr]++;

                    } else{

                        P[pairl]++;

                    }




                }

            }

        }

    }
}

int Triangle::removeEdge(int x, int y){

    cout << "remove V" << x << " , V" << y << endl;

    int pl,pr;
    if(x > y){
        pl = y;
        pr = x;
    } else{

        pl = x;
        pr = y;
    }

    //find P
    EdgeClass pair(pl, pr);
    unordered_map<EdgeClass, int, EdgeHash, EdgeEqualTo>::iterator it = P.find(pair);
    if(it != P.end()) {

        cout << "In P can get" << endl;
        t = t - it->second;

    }

    //find H
    unordered_map<int, int>::iterator it_H;
    for(it_H = H.begin(); it_H != H.end(); it_H++){

        unordered_map<EdgeClass, int, EdgeHash, EdgeEqualTo>::iterator it1, it2, it3, it4;
        int i = it_H->first;

        EdgeClass pair1(x, i), pair2(i, x), pair3(y, i), pair4(i, y);


        it1 = EdgeMap.find(pair1);
        it2 = EdgeMap.find(pair2);
        it3 = EdgeMap.find(pair3);
        it4 = EdgeMap.find(pair4);

        if((it1 != (EdgeMap.end()) || (it2 != EdgeMap.end())) && ((it3 != EdgeMap.end() || it4 != EdgeMap.end()))){

            cout << "In H can get" << endl;
            t = t - 1;

        }

    }

    //x not in H
    if(H.find(x) == H.end()){

        cout << "----x:" << x << endl;

        vector<int>::iterator it;

        if(graph[x].empty()){

            cout << "empty" << endl;

        }
        else
        {
            for(it = graph[x].begin(); it != graph[x].end(); it++){

                int i = *it;
                int pl,pr;
                if(i > y){
                    pl = y;
                    pr = i;
                } else{

                    pl = i;
                    pr = y;

                }

                EdgeClass pair(pl, pr);
                P[pair]--;
                if(P[pair] <= 0){

                    P.erase(pair);
                }
                cout << "p remove：" << pl << "+" << pr << endl;

            }

        }


    }
    //y not in H
    if(H.find(y) == H.end()){
        vector<int>::iterator it;
        cout << "----y:" << y << endl;
        if(graph[y].empty()){

            cout << "empty" << endl;

        }
        else
        {
            for(it = graph[y].begin(); it != graph[y].end(); it++){

                int i = *it;
                int pl,pr;
                if(i > x){
                    pl = x;
                    pr = i;
                } else{

                    pl = i;
                    pr = x;

                }

                EdgeClass pair(pl, pr);

                P[pair]--;

                if(P[pair] <= 0){

                    P.erase(pair);
                }

                cout << "p remove：" << pl << "+" << pr << endl;

            }

        }

    }


    //remove EdgeMap
    //remove neighbor

    vector<int>::iterator it2;

    //cout << "vertex" << x<< ": ";

    for( it2 = graph[x].begin(); it2 != graph[x].end(); it2++){

        if(*it2 == y){

            graph[x].erase(it2);
            break;
        }
    }
    for( it2 = graph[y].begin(); it2 != graph[y].end(); it2++){

        if(*it2 == x){

            graph[y].erase(it2);
            break;
        }
    }

    EdgeClass edge(x, y);
    EdgeMap.erase(edge);


    int perH = gethindex();
    unordered_map<int, int> perSetH = getH();

    //change deg
    int dx = degree[x] - 1;
    int dy = degree[y] - 1;
    removeVertex(x);
    insertVertex(x, dx);
    removeVertex(y);
    insertVertex(y, dy);

    //update P
    int H = gethindex();
    unordered_map<int, int> SetH =getH();

    int flag;

    //update P
    cout << "update P" << endl;

    for(unordered_map<int, int>::iterator it = SetH.begin(); it != SetH.end(); it++) {
        //find new vertex
        if (perSetH.find(it->first) == perSetH.end()) {

            flag = it->first;
            vector<int>::iterator it1;
            vector<int>::iterator it2;
            for (it1 = graph[flag].begin(); it1 != graph[flag].end(); it1++) {

                for (it2 = it1 + 1; it2 != graph[flag].end(); it2++) {


                    EdgeClass pairl(*it1, *it2);
                    cout << "P(V" << *it1 << ", V" << *it2 << ") remove " << endl;

                    if (P.find(pairl) != P.end()) {

                        P[pairl]--;
                        if (P[pairl] <= 0) {
                            P.erase(pairl);

                        }

                    }

                }

            }

        }
    }

    for(unordered_map<int, int>::iterator it = perSetH.begin(); it != perSetH.end(); it++) {
        //find new vertex
        if (SetH.find(it->first) == SetH.end()) {

            flag = it->first;
            vector<int>::iterator it1;
            vector<int>::iterator it2;
            for (it1 = graph[flag].begin(); it1 != graph[flag].end(); it1++) {

                for (it2 = it1 + 1; it2 != graph[flag].end(); it2++) {

                    EdgeClass pairl(*it1, *it2);
                    cout << "P(V" << *it1 << ", V" << *it2 << ") add----- " << endl;

                    P[pairl]++;

                }

            }

        }

    }



//    if(h < perH) {
//
//        cout << "start remove" << endl;
//
//        for (unordered_map<int, int>::iterator it = perSetH.begin(); it != perSetH.end(); it++) {
//
//            //find new vertex
//            if (SetH.find(it->first) == SetH.end()) {
//
//                flag = it->first;
//                vector<int>::iterator it1;
//                vector<int>::iterator it2;
//                for (it1 = graph[flag].begin(); it1 != graph[flag].end(); it1++) {
//
//                    for (it2 = it1 + 1; it2 != graph[flag].end(); it2++) {
//
//
//                        EdgeClass pairl(*it1, *it2);
//                        cout << "P(V" << *it1 << ", V" << *it2 << ") add " << endl;
//
//                        if (P.find(pairl) != P.end()) {
//
//                            P[pairl]++;
//
//                        }
//
//                    }
//
//
//                }
//
//            }
//
//
//        }
//
//    }

}

int Triangle::buildHindex(){

    for(int i = 1; i <= V; i++){

        insertVertex(i, degree[i]);

    }

    return 1;

}

const unordered_map<int, int> &Triangle::getDegree() const {
    return degree;
}

const unordered_map<int, int> &Triangle::getH() const {
    return H;
}

int Triangle::getT() const {
    return t;
}

