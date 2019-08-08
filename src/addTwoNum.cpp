//
// Created by yuehu on 19-8-6.
//

class Node{
public:
    int value;
    Node *next;

    Node(int value): value(value), next(nullptr){}
};

Node* addTwoNum(Node *l1, Node *l2){
    int sum = 0;
    int carry = 0;
    Node *res_head = new Node(-1);
    Node *res_next = res_head;
    Node *p = l1;
    Node *q = l2;

    while(p != nullptr || q != nullptr || carry){
        sum = (p?p->value:0) + (q?q->value:0);
        if (sum >= 10){
            carry = 1;
            sum = sum - 10;
        }

        Node* res_temp = new Node(sum);
        res_next->next = res_temp;

        res_next = res_next->next;
        if(p) p = p->next;
        if(q) q = q->next;
    }
    return res_head->next;
}

int main(){
    Node *l1 = new Node(1);
    Node *temp = new Node(2);
    l1->next = temp;

    Node *l2 = new Node(1);
    Node *temp2 = new Node(2);
    l2->next = temp2;

    Node *res = addTwoNum(l1, l2);
    std::cout<< res->value <<std::endl;
    return 0;
}