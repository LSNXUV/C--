#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// С���ѽṹ��
struct MinHeap {
    vector<int> heap;

    // ��ʼ��С����
    MinHeap() {}

    // ��С�����в���Ԫ��
    void insert(int value) {
        heap.push_back(value);
        // ����Ԫ�غ���Ҫ�����ѽṹ
        int index = heap.size() - 1;
        while (index > 0 && heap[(index - 1) / 2] > heap[index]) {
            swap(heap[index], heap[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
        push_heap(heap.begin(), heap.end(), greater<int>()); // ʹ��STL��push_heap����,greater<int>��ʾС����
        // push_heap(heap.begin(), heap.end(), less<int>()); // ʹ��STL��push_heap����,less<int>��ʾ�󶥶�
    }

    // �ж�x�Ƿ�Ϊ�����
    bool isRoot(int x) {
        return heap[0] == x;
    }

    // �ж�x��y�Ƿ�Ϊ�ֵܽ��
    bool areSiblings(int x, int y) {
        int indexX = -1, indexY = -1;
        for (int i = 0; i < heap.size(); ++i) {
            if (heap[i] == x) indexX = i;
            if (heap[i] == y) indexY = i;
        }
        return indexX != -1 && indexY != -1 && (indexX - 1) / 2 == (indexY - 1) / 2;
    }

    // �ж�x�Ƿ�Ϊy�ĸ����
    bool isParent(int x, int y) {
        int indexX = -1, indexY = -1;
        for (int i = 0; i < heap.size(); ++i) {
            if (heap[i] == x) indexX = i;
            if (heap[i] == y) indexY = i;
        }
        return indexX != -1 && indexY != -1 && indexX == (indexY - 1) / 2;
    }

    // �ж�x�Ƿ�Ϊy���ӽ��
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
    //���С����
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
        //��������м��֣�
        if(proposition.substr(firstWordIndex,11)=="is the root"){   //x is the root
            if (heap.isRoot(x)) cout << "T" << endl;
            else cout << "F" << endl;
        } else if(proposition.substr(firstWordIndex,3)=="and"){     //x and y are siblings
            int behindYIndex = proposition.find(' ', firstWordIndex + 4);
            int y = stoi(proposition.substr(firstSpaceIndex + 4, behindYIndex));
            if (heap.areSiblings(x, y)) cout << "T" << endl;
            else cout << "F" << endl;
        }else{  //x is the parent of y��x��y�ĸ���㣻 x is a child of y��x��y��һ���ӽ�㡣
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
