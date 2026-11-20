struct ListNode* merge(struct ListNode* a, struct ListNode* b) {
    if (a == NULL)
        return b;

    if (b == NULL)
        return a;

    struct ListNode* result;

    if (a->val < b->val) {
        result = a;
        result->next = merge(a->next, b);
    }
    else {
        result = b;
        result->next = merge(a, b->next);
    }

    return result;
}

struct ListNode* sortList(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;

    struct ListNode* slow = head;
    struct ListNode* fast = head->next;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct ListNode* mid = slow->next;
    slow->next = NULL;

    struct ListNode* left = sortList(head);
    struct ListNode* right = sortList(mid);

    return merge(left, right);
}