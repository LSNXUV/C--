
#include <iostream>
using namespace std;

/**
 * @brief 生成一个n*m的螺旋矩阵,默认从左上角开始,顺时针方向,从1开始增大
 * 
 * @param n 行数
 * @param m 列数
 * @param start 1,2,3,4分别代表左上,右上,右下,左下
 * @param direction 1,2分别代表顺时针,逆时针
 * @param altitute 1,2分别代表从1开始递增、从n*m开始递减
 * @return int**  n*m的螺旋矩阵
 */
int **VortexMatrix(int n,int m,int start = 1,int direction = 1,int altitute = 1){
    int **Arr = new int*[m];
    //初始化数组，全部为0
    for(int i = 0;i<n;i++){
        Arr[i] = new int[m];
        for(int j = 0;j<m;j++){
            Arr[i][j] = 0;
        }
    }
    int i,j;
    int stepI,stepJ;
    int num,numStep;
    //根据altitute确定递增还是递减
    switch(altitute){
        case 1:
            numStep = 1;
            num = 1;
            break;
        case 2:
            numStep = -1;
            num = n*m;
            break;
    }
    //根据start、direction确定起始位置（i，j）和I、J的增量
    switch(start){
        case 1:
            i = 0;
            j = 0;
            switch(direction){
                case 1:
                    stepI = 0;
                    stepJ = 1;
                    break;
                case 2:
                    stepI = 1;
                    stepJ = 0;
                    break;
            }
            break;
        case 2:
            i = 0;
            j = m-1;
            switch(direction){
                case 1:
                    stepI = 1;
                    stepJ = 0;
                    break;
                case 2:
                    stepI = 0;
                    stepJ = -1;
                    break;
            }
            break;
        case 3:
            i = n-1;
            j = m-1;
            switch(direction){
                case 1:
                    stepI = 0;
                    stepJ = -1;
                    break;
                case 2:
                    stepI = -1;
                    stepJ = 0;
                    break;
            }
            break;
        case 4:
            i = n-1;
            j = 0;
            switch(direction){
                case 1:
                    stepI = -1;
                    stepJ = 0;
                    break;
                case 2:
                    stepI = 0;
                    stepJ = 1;
                    break;
            }
            break;
    }
    
    //填充数组
    while(true){
        Arr[i][j] = num;
        num+=numStep;

        //如果下一个位置超出边界或者已经有值，则改变方向
        if(i + stepI < 0 || i+stepI >= n || j + stepJ < 0 || j + stepJ >=m || Arr[i+stepI][j+stepJ] != 0){
            if(direction == 1){
                if(stepI == 0){
                    stepI = stepJ;
                    stepJ = 0;
                }else{
                    stepJ = -stepI;
                    stepI = 0;
                }
            }else{
                if(stepJ == 0){
                    stepJ = stepI;
                    stepI = 0;
                }else{
                    stepI = -stepJ;
                    stepJ = 0;
                }
            }
        }
        //如果再下一个位置还是超出边界或者已经有值，说明已经填充完毕
        if(i + stepI < 0|| i + stepI >= n || j + stepJ < 0 || j + stepJ >=m || Arr[i+stepI][j+stepJ] != 0){
            break;
        }
        //移动到下一个位置
        i+=stepI;j+=stepJ;
    }
    return Arr;
}

int main(){

    int n,m,start,direction,altitute;
    cin>>n>>m>>start>>direction>>altitute;

    int **Arr = VortexMatrix(n,m,start,direction,altitute);

    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cout<<Arr[i][j]<<"\t";
        }
        cout<<endl;
    }

    system("pause");
    return 0;
}