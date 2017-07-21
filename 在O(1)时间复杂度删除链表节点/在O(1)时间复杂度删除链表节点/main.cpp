//
//  main.cpp
//  在O(1)时间复杂度删除链表节点
//
//  Created by Ruiwen Feng on 2017/7/21.
//  Copyright © 2017年 Ruiwen Feng. All rights reserved.
//

/*
 给定一个单链表中的一个等待被删除的节点(非表头或表尾)。请在在O(1)时间复杂度删除该链表节点。
 
 样例
 Linked list is 1->2->3->4, and given node 3, delete the node in place 1->2->4
 
 */

#include <iostream>
#include <vector>

using namespace std;


// * Definition of ListNode
class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};


class Solution {
public:
    /**
     * @param node: a node in the list should be deleted
     * @return: nothing
     */
    void deleteNode(ListNode *node) {
        ListNode * deleteNode = node->next;
        node->val = node->next->val;
        node->next = node->next->next;
        delete deleteNode;
    }
};

ListNode * createList(vector<int> array) {
    
    ListNode * header = new ListNode(array[0]);
    ListNode * next = header;
    for (int i = 1; i < array.size(); i++) {
        next->next = new ListNode(array[i]);
        next = next->next;
    }
    return header;
}

int main(int argc, const char * argv[]) {
    vector<int> array = {1,2,3,4};
    ListNode * node = createList(array);
    
    Solution s;
    s.deleteNode(node->next);
    
    while (node) {
        cout << node->val;
        node = node->next;
    }
    return 0;
}
