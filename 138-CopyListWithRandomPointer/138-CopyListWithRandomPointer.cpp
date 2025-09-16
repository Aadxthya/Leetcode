// Last updated: 9/16/2025, 9:53:31 AM
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr)
            return nullptr;

        unordered_map<Node*, Node*> mp;

        Node* newHead = new Node(head->val);
        Node* oldTemp = head->next;
        Node* newTemp = newHead;

        mp[head] = newHead;

        while (oldTemp != NULL) {
            newTemp->next = new Node(oldTemp->val);
            // newTemp->random = oldTemp->random; is wrong because it just
            // copies the old random pointer
            mp[oldTemp] = newTemp->next;
            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        oldTemp = head;
        while (oldTemp != NULL) {
            mp[oldTemp]->random =
                mp[oldTemp->random]; // corresponding to the oldnode what is the
            oldTemp = oldTemp->next; // random in new list?
            // suppose oldTemp -> 1
            // mp[oldTemp] => new 1
            //  new 1 -> random = mp[....]
            // oldTemp->random => the random element pointing towards 1 i.e 7
            // (old 7) mp[old 7] = new 7
            //  therefore, new 1 ->random = new 7;
        }
        return newHead;
    }
};