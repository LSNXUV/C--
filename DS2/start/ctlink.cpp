#include <iostream>
using namespace std;

struct Node {
    int num; // 学号
    int score; // 成绩
    Node* next; // 指向下一个节点的指针
};

int main() {
    Node* head = nullptr; // 链表头指针
    Node* tail = nullptr; // 链表尾指针

    // 输入三组数据
    int num1, num2, num3;
    int score1, score2, score3;
    scanf("%d,%d %d,%d %d,%d",&num1,&score1,&num2,&score2,&num3,&score3);

    // 创建三个节点
    Node* node1 = new Node{num1, score1, nullptr};
    Node* node2 = new Node{num2, score2, nullptr};
    Node* node3 = new Node{num3, score3, nullptr};

    // 将三个节点加入链表
    if (head == nullptr) { // 如果链表为空，头指针和尾指针都指向第一个节点
        head = node1;
        tail = node1;
    } else { // 如果链表不为空，将第一个节点加入链表尾部
        tail->next = node1;
        tail = node1;
    }
    tail->next = node2; // 将第二个节点加入链表尾部
    tail = node2;
    tail->next = node3; // 将第三个节点加入链表尾部
    tail = node3;

    // 遍历链表并输出各节点数据
    Node* p = head;
    while (p != nullptr) {
        cout << "[num=" << p->num << ",score=" << p->score << "]" << endl;
        p = p->next;
    }

    system("pause");
    return 0;
}

