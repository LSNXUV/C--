#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// 小顶堆结构体
struct MinHeap {
    vector<int> heap;

    // 初始化小顶堆
    MinHeap() {}

    // 向小顶堆中插入元素
    void insert(int value) {
        heap.push_back(value);
        // 插入元素后，需要调整堆结构
        int index = heap.size() - 1;
        while (index > 0 && heap[(index - 1) / 2] > heap[index]) {
            swap(heap[index], heap[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
        push_heap(heap.begin(), heap.end(), greater<int>()); // 使用STL的push_heap函数,greater<int>表示小顶堆
        // push_heap(heap.begin(), heap.end(), less<int>()); // 使用STL的push_heap函数,less<int>表示大顶堆
    }

    // 判断x是否为根结点
    bool isRoot(int x) {
        return heap[0] == x;
    }

    // 判断x和y是否为兄弟结点
    bool areSiblings(int x, int y) {
        int indexX = -1, indexY = -1;
        for (int i = 0; i < heap.size(); ++i) {
            if (heap[i] == x) indexX = i;
            if (heap[i] == y) indexY = i;
        }
        return indexX != -1 && indexY != -1 && (indexX - 1) / 2 == (indexY - 1) / 2;
    }

    // 判断x是否为y的父结点
    bool isParent(int x, int y) {
        int indexX = -1, indexY = -1;
        for (int i = 0; i < heap.size(); ++i) {
            if (heap[i] == x) indexX = i;
            if (heap[i] == y) indexY = i;
        }
        return indexX != -1 && indexY != -1 && indexX == (indexY - 1) / 2;
    }

    // 判断x是否为y的子结点
    bool isChild(int x, int y) {
        int indexX = -1, indexY = -1;
        for (int i = 0; i < heap.size(); ++i) {
            if (heap[i] == x) indexX = i;
            if (heap[i] == y) indexY = i;
        }
        return indexX != -1 && indexY != -1 && (indexX - 1) / 2 == indexY;
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    MinHeap heap;
    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        heap.insert(num);
    }
    //输出小根堆
    for (int i = 0; i < heap.heap.size(); ++i) {
        cout << heap.heap[i];
        if (i != heap.heap.size() - 1) cout << " ";
    }
    cout<<endl;
    for (int i = 0; i < M; ++i) {
        string proposition;
        if(i==0) cin.ignore();
        getline(cin, proposition);
        int firstSpaceIndex = proposition.find(' ');
        int firstWordIndex = firstSpaceIndex + 1;
        int x = stoi(proposition.substr(0, firstSpaceIndex));
        //命题分下列几种：
        if(proposition.substr(firstWordIndex,11)=="is the root"){   //x is the root
            if (heap.isRoot(x)) cout << "T" << endl;
            else cout << "F" << endl;
        } else if(proposition.substr(firstWordIndex,3)=="and"){     //x and y are siblings
            int behindYIndex = proposition.find(' ', firstWordIndex + 4);
            int y = stoi(proposition.substr(firstSpaceIndex + 4, behindYIndex));
            if (heap.areSiblings(x, y)) cout << "T" << endl;
            else cout << "F" << endl;
        }else{  //x is the parent of y：x是y的父结点； x is a child of y：x是y的一个子结点。
            int y = stoi(proposition.substr(proposition.rfind(' ') + 1));
            if((proposition.substr(firstWordIndex,13)=="is the parent" && heap.isParent(x, y))
            || (proposition.substr(firstWordIndex,10)=="is a child" && heap.isChild(x, y)))
                cout << "T" << endl;
            else cout << "F" << endl;
        }
    }
    
    system("pause");
    return 0;
}
