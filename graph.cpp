#include <iostream>
#include <cstdlib>
#include<fstream>
#include <stdlib.h>



using namespace std;



int random (int, int);

int main(){
    ofstream ofile;
    ofile.open ("oneM.dat");
    int n = 1000000;
    int edges, head, distance;

    // for(int i = 0; i < n; i++){
    //     edges = random(0, 5);
    //     for(int j = 0; j < edges; j++){
    //         do{
    //             head = random(0, n-1);
    //         }while(i == head);

    //         distance = random(1, 5);
    //         // printf("%d %d %d\n", i, head, distance);
    //         ofile << i << " " << head << " " << distance << endl;
    //     }
    // }
    ofile << n << endl;
    for( int i = 0; i < n-1; i++){
        ofile << i << " " << i+1 << " " << 1 << endl;
        if(i%1000000 == 0){
            cout << (float)i/n * 100 << "%\r";
        }
        // system("cls");
    }

    cout << "Data written to file" << endl; 
    ofile.close();

    return 0;
}

int random(int min, int max){
    return rand()%(max-min + 1) + min;
}