/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* t1 = l1;
    struct ListNode* t2 = l2;
    int tmp;
    int c = 0;
    while(1) {
        tmp = (t1->val + t2->val + c) % 10;
        c = ((t1->val + t2->val + c) / 10);
        t1->val = tmp;
        if (t1->next == NULL || t2->next == NULL) break;
        t1 = t1->next;
        t2 = t2->next;
    }
    if (t2->next != NULL) {
        t1->next = t2->next;
    }
    if (t1->next != NULL) {
        t1 = t1->next;
        while(1) {
            tmp = (t1->val + c) % 10;
            c = ((t1->val + c) / 10);
            t1->val = tmp;
            if (t1->next == NULL) break;
            t1 = t1->next;
        }
    }
    if (c == 1) {
        struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
        node->val = 1;
        node->next = NULL;
        t1->next = node;
    }
    return l1;
}
