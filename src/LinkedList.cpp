//
// Created by yuehu on 2020/3/24.
//


// Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
};

class Solution206 {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* curr = head;
        while(curr){
            ListNode* next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }
        return pre;
    }
};



class Solution92 {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        ListNode* pre0,*cur0;
        unsigned int count = 1;
        while(cur != nullptr && count <= n){
            //当cur为m时,记录一下当前cur和pre
            if(count == m)//在头节点,则记录当前pre和cur供后续连接使用
            {
                pre0 = pre;
                cur0 = cur;
            }
            //当cur在(m,n]之间时，反转链表
            if(count > m && count <= n)
            {
                ListNode* temp = cur->next;
                cur->next = pre;
                pre = cur;
                cur = temp;
            }
            else         //常规迭代处理
            {
                pre = cur;
                cur = cur->next;
            }
            //常规处理
            ++count;
        }
        //最后的链接操作
        //将pre0的next指向第n元素,此时pre指向n，cur指向原始链表中n的下一个元素
        if(pre0 == nullptr) head = pre;
        else pre0->next = pre;
        //将指向m的cur0的next指向n后第一个元素
        cur0->next = cur;

        return head;
    }
};


class Solution83 {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;
        while(curr != nullptr){
            ListNode* next = curr->next;
            if(next != nullptr && curr->val == next->val){
                curr->next = next->next;
            }else{
                curr = curr->next;
            }
        }
        return head;
    }
};

class Solution203 {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* sentinel = new ListNode(0);
        sentinel->next = head;

        ListNode *prev = sentinel, *curr = head, *toDelete = nullptr;
        while (curr != nullptr) {
            if (curr->val == val) {
                prev->next = curr->next;
                toDelete = curr;
            } else prev = curr;

            curr = curr->next;

            if (toDelete != nullptr) {
                delete toDelete;
                toDelete = nullptr;
            }
        }

        ListNode *ret = sentinel->next;
        delete sentinel;
        return ret;
    }

};

class Solution82 {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode thead=ListNode(-1);
        thead.next=head;
        ListNode *pre,*cur;
        int t;
        cur=&thead;
        while (cur){
            pre = cur;
            cur = cur->next;
            while (cur && cur->next &&
                   cur->next->val==cur->val){
                t=cur->val;
                while (cur && cur->val==t)
                    cur=cur->next;
            }
            pre->next=cur;
        }
        return thead.next;
    }

};


class Solution19 {
public:

    int getLength(ListNode* head){
        ListNode* curr = head;
        int num = 0;
        while(curr != nullptr){
            curr = curr->next;
            num++;
        }
        return num;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = getLength(head);
        int pos = length - n;

        ListNode* sentinel = new ListNode(-1);
        ListNode* pre = sentinel;
        pre->next = head;
        ListNode* curr = head;

        while(pos >= 0){
            if(pos == n){
                pre->next = curr->next;
            }

            pre = curr;
            curr = curr->next;
            pos--;
        }

        return sentinel->next;

    }
};


class Solution141 {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast != nullptr && fast->next != nullptr){

            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast){
                return true;
            }
        }
        return false;
    }
};


class Solution160 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto a=headA,b=headB;
        while(a!=b){
            if(a) a=a->next;
            else a=headB;
            if(b) b=b->next;
            else b=headA;
        }
        return a;
    }
};

class Solution328 {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head== nullptr){
            return head;
        }

        auto odd = head;
        auto even = head->next;
        auto evenHead = even;

        while(even && even->next){
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }

        odd->next = evenHead;

        return head;
    }
};


class Solution21 {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        auto curr1 = l1;
        auto curr2 = l2;
        auto sen = new ListNode(-1);
        auto curr = sen;
        while(curr1 != nullptr && curr2 != nullptr){
            if(curr1->val <= curr2->val){
                curr->next = curr1;
                curr = curr->next;
                curr1 = curr1->next;
            }else{
                curr->next = curr2;
                curr = curr->next;
                curr2 = curr2->next;
            }
        }
        if(curr1 == nullptr){
            curr->next = curr2;
        } else{
            curr->next = curr1;
        }
        return sen->next;
    }
};


class Solution02_02 {
public:
    int kthToLast(ListNode* head, int k) {
        ListNode* curr = head;
        int sum = 0;
        while(curr != nullptr){
            sum++;
            curr = curr->next;
        }


        int pos = sum - k;
        curr = head;
        while(pos >0){
            curr = curr->next;
            pos--;
        }
        return curr->val;
    }
};