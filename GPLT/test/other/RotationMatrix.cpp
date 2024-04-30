#include <iostream>
using namespace std;

//n*m的螺旋矩阵
int **Vortex(int n,int m){
    int **Arr = new int*[n];
    for(int i = 0;i < n;i++){
        Arr[i] = new int[m];
    }
    int num = 1;
    
    //方法一：直接填充，较难理解
    /* 
    for(int i = 0;i < n;i++){
        for(int j = i;j < n - i;j++){
            Arr[i][j] = num++;
        }
        for(int j = i + 1;j < n - i;j++){
            Arr[j][n - i - 1] = num++;
        }
        for(int j = n - i - 2;j >= i;j--){
            Arr[n - i - 1][j] = num++;
        }
        for(int j = n - i - 2;j > i;j--){
            Arr[j][i] = num++;
        }
    } */
    
    //方法二：stepI和stepJ控制方向，较容易理解
    int i = 0, j = 0;
    int stepI = 0, stepJ = 1;
    //初始化数组，全部为0
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            Arr[i][j] = 0;
        }
    }
    //判断能否继续填充，如果出界或者已经填充过（不为0），则停止
    //i < 0 || i >= n || j < 0 || j >= m || Arr[i][j] != 0
    while (true) {
        Arr[i][j] = num++;
        if(i + stepI < 0 || i + stepI >= n || j + stepJ < 0 || j + stepJ >= m || Arr[i + stepI][j + stepJ] != 0){
            if(stepI == 0){
                stepI = stepJ;
                stepJ = 0;
            }else{
                stepJ = -stepI;
                stepI = 0;
            }
            if(i + stepI < 0 || i + stepI >= n || j + stepJ < 0 || j + stepJ >= m || Arr[i + stepI][j + stepJ] != 0){
                break;
            }
        }
        i += stepI;
        j += stepJ;
    }
    return Arr;
}

int main(){
    int n,m;
    cin >> n >> m;

    int **Arr = Vortex(n,m);

    //输出数组
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cout << Arr[i][j] << " ";
        }
        cout << endl;
    }

    system("pause");
    return 0;
}