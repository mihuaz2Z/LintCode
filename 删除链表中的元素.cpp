#include <iostream>

using namespace std;

// * Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};



class Solution {
public:
    ListNode *removeElements(ListNode *head, int val) {
        
        ListNode * node = head; //当前的node
        ListNode * lastnode = NULL; //node的上一个节点
        while(node != NULL){
            if (node->val == val)
            {
                if (lastnode != NULL)
                {
                    lastnode->next = node->next;
                    delete node;
                    node = lastnode->next;
                }
                else {
                    ListNode * currentNode = node;
                    node = node->next;
                    head = node;
                    delete currentNode;
                }
            }
            else{
                
                lastnode = node;
                node = node->next;
                
            }
        }
        if (head != NULL) {
            return head;
        }
        return NULL;
    }
};


void createList(ListNode*head,int * array,int size) {
    head->val = array[0];
    ListNode * lastnode = NULL;
    
    for (int i = 1; i < size; ++i)
    {
        ListNode * node = new ListNode(array[i]);
        if (lastnode != NULL)
        {
            lastnode->next = node;
            lastnode = node;
        }
        else {
            head->next = node;
            lastnode = node;
        }
    }
};

int main(int argc, char const *argv[])
{
    int kaka[] = {1,2,3,4,2,5,6,7,8,22,2,2,2,2,2};
    int size = sizeof(kaka)/sizeof(int);

    ListNode * head = new ListNode(kaka[0]);

    createList(head,kaka,size);

    Solution solution;
    ListNode * node = solution.removeElements(head,2);
    
    
    while(node != NULL) {
        
        cout << node->val << " ";
        node = node->next;
    }
    
    
    return 0;
}