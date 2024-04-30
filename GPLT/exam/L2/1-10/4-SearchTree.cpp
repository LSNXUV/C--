/*
�����ʽ��
����ĵ�һ�и��������� N����1000�������һ�и��� N ��������ֵ������Կո�ָ���
�����ʽ��
������������Ƕ�һ�ö������������侵�����ǰ������Ľ����
��������һ������� YES ��Ȼ������һ�����������������Ľ����
���ּ��� 1 ���ո�һ�е���β�����ж���ո������Ƿ������ NO��
�������� 1��
7
8 6 5 7 10 8 11
�������� 3��
7
8 6 8 5 10 9 11
������� 3��
NO
*/
#include <iostream>
#include <vector>
using namespace std;

/*
test:
7
8 6 5 7 10 8 11

*/
void solveByPre(const int arr[], vector<int> &tree, int l,int r, bool mirror){
    if(l > r) return;
    int i = l + 1, j = r;
    if(!mirror){
        while(i <= r && arr[i] < arr[l]) i++;
        while(j > l && arr[j] >= arr[l]) j--;
    }else{
        while(i <= r && arr[i] >= arr[l]) i++;
        while(j > l && arr[j] < arr[l]) j--;
    }
    if(i - j != 1) return;

    // tree.push_back(arr[l]);       //�����������ǰ�����,����û��Ҫ����Ϊarr��������ǰ�����
    solveByPre(arr, tree, l + 1, j, mirror);
    tree.push_back(arr[l]);       //������������������
    solveByPre(arr, tree, i, r, mirror);
    // tree.push_back(arr[l]);         //����������Ǻ������
}

/*
test: 
7
5 7 6 8 11 10 8
*/
void solveByPost(const int arr[], vector<int> &tree, int l,int r, bool mirror){
    if(l > r) return;
    int i = l, j = r -1;
    if(!mirror){
        while(i < r && arr[i] < arr[r]) i++;
        while(j >= l && arr[j] >= arr[r]) j--;
    }else{
        while(i < r && arr[i] >= arr[r]) i++;
        while(j >= l && arr[j] < arr[r]) j--;
    }
    if(i - j != 1) return;

    tree.push_back(arr[r]);    //�����������ǰ�����
    solveByPost(arr, tree, l, j, mirror);
    // tree.push_back(arr[r]);    //������������������
    solveByPost(arr, tree, i, r - 1, mirror);
    // tree.push_back(arr[r]);  //����������Ǻ������������û��Ҫ����Ϊarr�������Ǻ������
}
int main(){
    int n;
    cin>>n;
    int pre[1000];
    for(int i = 0; i < n; i++){
        cin>>pre[i];
    }
    vector<int> tree;
    solveByPre(pre, tree, 0, n - 1, false);
    // solveByPost(pre, tree, 0, n - 1, false);
    if(tree.size() == n){
        cout<<"YES"<<endl;
        for(int i = 0; i < n; i++){
            cout<<(i == 0 ? "" : " ")<<tree[i];
        }
    }else{
        tree.clear();
        solveByPre(pre, tree, 0, n - 1, true);
        // solveByPost(pre, tree, 0, n - 1, true);
        if(tree.size() == n){
            cout<<"YES"<<endl;
            for(int i = 0; i < n; i++){
                cout<<(i == 0 ? "" : " ")<<tree[i];
            }
        }else{
            cout<<"NO";
        }
    }
    system("pause");
    return 0;
}