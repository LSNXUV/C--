
#include <iostream>
using namespace std;

/**
 * @brief ����һ��n*m����������,Ĭ�ϴ����Ͻǿ�ʼ,˳ʱ�뷽��,��1��ʼ����
 * 
 * @param n ����
 * @param m ����
 * @param start 1,2,3,4�ֱ��������,����,����,����
 * @param direction 1,2�ֱ����˳ʱ��,��ʱ��
 * @param altitute 1,2�ֱ�����1��ʼ��������n*m��ʼ�ݼ�
 * @return int**  n*m����������
 */
int **VortexMatrix(int n,int m,int start = 1,int direction = 1,int altitute = 1){
    int **Arr = new int*[m];
    //��ʼ�����飬ȫ��Ϊ0
    for(int i = 0;i<n;i++){
        Arr[i] = new int[m];
        for(int j = 0;j<m;j++){
            Arr[i][j] = 0;
        }
    }
    int i,j;
    int stepI,stepJ;
    int num,numStep;
    //����altituteȷ���������ǵݼ�
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
    //����start��directionȷ����ʼλ�ã�i��j����I��J������
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
    
    //�������
    while(true){
        Arr[i][j] = num;
        num+=numStep;

        //�����һ��λ�ó����߽�����Ѿ���ֵ����ı䷽��
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
        //�������һ��λ�û��ǳ����߽�����Ѿ���ֵ��˵���Ѿ�������
        if(i + stepI < 0|| i + stepI >= n || j + stepJ < 0 || j + stepJ >=m || Arr[i+stepI][j+stepJ] != 0){
            break;
        }
        //�ƶ�����һ��λ��
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