#include <iostream>
using namespace std;


typedef struct Node{
	int id;//学号 
	char name[50];//姓名 
	char sex[10];//性别 
	int ma,en,et,pc;//数英体机 
	int sum;//总分 
	int avr;
	
	struct Node *next;//指针域 
}node;


node* mid_node(Node* start, Node* last){
   if (start == NULL)
      return NULL;
   node* slow = start;
   node* fast = start -> next;
   while (fast != last){
      fast = fast -> next;
      if (fast != last){
         slow = slow -> next;
         fast = fast -> next;
      }
   }
   return slow;
}
node* binarySearch(Node *head, int value){
   node* start = head;
   node* last = NULL;
   do{
      Node* mid = mid_node(start, last);
      if (mid == NULL)
         return NULL;
      if (mid -> id == value)
         return mid;
      else if (mid -> id < value)
         start = mid -> next;
      else
         last = mid;
   }
   while (last == NULL || last != start);
      return NULL;
}

int main(){


	system("pause");
	return 0;
}