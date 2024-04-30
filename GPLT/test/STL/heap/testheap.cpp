#include <iostream>
#include <vector>  
#include <algorithm>
using namespace std;

vector<int> heap;

void add(int x){
    heap.push_back(x);
    push_heap(heap.begin(), heap.end());    //Ĭ���Ǵ󶥶�
}

/*
test data:
// 1
5
1 2 3 4 5
�� �Ƕ�

// 2
5
4 2 5 3 1
�� ���Ƕ�
*/

int main(){
    vector<int> v;
    int n, x;
    cin>>n;
    while(n != -1){
        for(int i=0; i<n; i++){
            cin>>x;
            v.push_back(x);
        }
        cout<<(is_heap_until(v.begin(), v.end()) == v.end())<<endl; //Ĭ���жϴ󶥶�,�ж�С���ѿ���ʹ��greater<int>()
        //is_heap_until()���ص��ǵ�һ��������ѵ�λ�ã�����Ƕѣ�����end()
        //is_heap()���ص����Ƿ��Ƕ�,Ĭ���Ǵ󶥶�
        cout<<(is_heap(v.begin(), v.end()) == 1)<<endl;
        v.clear();
        cin>>n;
    }

    system("pause");
    return 0;
}