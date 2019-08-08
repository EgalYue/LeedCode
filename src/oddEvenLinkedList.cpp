//
// Created by yuehu on 19-8-8.
//

using namespace std;
class Node{
public:
    int value;
    Node *next;
    explicit Node(int value): value(value), next(nullptr){

    }
};

Node* oddEvenLinkedList(Node *input){
    if (input == nullptr || input->next == nullptr || input->next->next == nullptr){
        return input;
    }

    Node *odd = new Node(-1);
    Node *even = new Node(-1);

    Node *oddNext = odd;
    Node *evenNext = even;
    Node *next = input;

    int count = 1;
    while( next != nullptr){
        int thisValue = input->value;
        if (count % 2 != 0){
            // odd
            oddNext->next = next;
        }
        else{
            // even
            evenNext->next = next;
        }

        oddNext = oddNext->next;
        evenNext = evenNext->next;
        next = next->next;
        count++;
    }
    oddNext ->next = even->next;
    return odd->next;
}
