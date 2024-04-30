#include<iostream>

using namespace std;

int **Vortex(int n,int m){

    int **Arr = new int*[n];
    for(int i = 0;i<n;i++){
        Arr[i] = new int[m];
    }

    int num = 1;
    int i = 0,j = 0;
    int stepI = 0,stepJ = 1;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            Arr[i][j] = 0;
        }
    }

    while(true){
        Arr[i][j] = num++;

        if(i + stepI < 0 || i+stepI >= n || j+stepJ < 0|| j+stepJ >= m || Arr[i+stepI][j+stepJ] != 0){
            if(stepI == 0){
                stepI = stepJ;
                stepJ = 0;
            }else{
                stepJ = -stepI;
                stepI = 0;
            }
            if(i + stepI < 0 || i+stepI >= n || j+stepJ < 0|| j+stepJ >= m || Arr[i+stepI][j+stepJ] != 0){
                break;
            }
        }

        i+=stepI;
        j+=stepJ;
    }

    return Arr;
}

int main(){

    int n,m;
    cin>>n>>m;

    int **Arr = Vortex(n,m);

    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cout<<Arr[i][j]<<"  ";
        }
        cout<<endl;
    }

    system("pause");
    return 0;
}