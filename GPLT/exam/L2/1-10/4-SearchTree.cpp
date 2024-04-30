/*
输入格式：
输入的第一行给出正整数 N（≤1000）。随后一行给出 N 个整数键值，其间以空格分隔。
输出格式：
如果输入序列是对一棵二叉搜索树或其镜像进行前序遍历的结果，
则首先在一行中输出 YES ，然后在下一行输出该树后序遍历的结果。
数字间有 1 个空格，一行的首尾不得有多余空格。若答案是否，则输出 NO。
输入样例 1：
7
8 6 5 7 10 8 11
输入样例 3：
7
8 6 8 5 10 9 11
输出样例 3：
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

    // tree.push_back(arr[l]);       //放在这儿就是前序遍历,这里没必要，因为arr本来就是前序遍历
    solveByPre(arr, tree, l + 1, j, mirror);
    tree.push_back(arr[l]);       //放在这儿就是中序遍历
    solveByPre(arr, tree, i, r, mirror);
    // tree.push_back(arr[l]);         //放在这儿就是后序遍历
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

    tree.push_back(arr[r]);    //放在这儿就是前序遍历
    solveByPost(arr, tree, l, j, mirror);
    // tree.push_back(arr[r]);    //放在这儿就是中序遍历
    solveByPost(arr, tree, i, r - 1, mirror);
    // tree.push_back(arr[r]);  //放在这儿就是后序遍历，这里没必要，因为arr本来就是后序遍历
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