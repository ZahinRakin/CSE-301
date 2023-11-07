//directed graph.
int** init(int** Graph){
    Graph = (int**)malloc(sizeof(int*)*7);
    for(int i = 0; i < 6; i++){
        Graph[i] = (int*)malloc(sizeof(int)*7);
    }

    Graph[0][0] = 0;
    Graph[0][1] = 4;
    Graph[0][2] = 4;
    Graph[0][3] = 0;
    Graph[0][4] = 0;
    Graph[0][5] = 0;
    Graph[0][6] = 0;

    Graph[1][0] = 4;
    Graph[1][1] = 0;
    Graph[1][2] = 2;
    Graph[1][3] = 0;
    Graph[1][4] = 0;
    Graph[1][5] = 0;
    Graph[1][6] = 0;

    Graph[2][0] = 4;
    Graph[2][1] = 2;
    Graph[2][2] = 0;
    Graph[2][3] = 3;
    Graph[2][4] = 4;
    Graph[2][5] = 0;
    Graph[2][6] = 0;

    Graph[3][0] = 0;
    Graph[3][1] = 0;
    Graph[3][2] = 3;
    Graph[3][3] = 0;
    Graph[3][4] = 3;
    Graph[3][5] = 0;
    Graph[3][6] = 0;

    Graph[4][0] = 0;
    Graph[4][1] = 0;
    Graph[4][2] = 4;
    Graph[4][3] = 3;
    Graph[4][4] = 0;
    Graph[4][5] = 0;
    Graph[4][6] = 0;

    Graph[5][0] = 0;
    Graph[5][1] = 0;
    Graph[5][2] = 2;
    Graph[5][3] = 0;
    Graph[5][4] = 3;
    Graph[5][5] = 0;
    Graph[5][6] = 0;

    return Graph;
}