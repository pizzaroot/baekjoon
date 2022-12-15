#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef struct Node {
    struct Node *prev, *next;
    int x;
} node;
typedef struct {
    node *head, *tail;
    int sz;
} deque;
int mint(int, int);
deque *create_deque();
void push_back(deque *, int);
int pop_front(deque *);
int front(deque *);
void destroy_deque(deque *);
int main() {
    int n, m, ans = 0; scanf("%d %d", &n, &m);
    deque *dq = create_deque();
    for (int i = 1; i <= n; i++) push_back(dq, i);
    for (int i = 0; i < m; i++) {
        int a, shift = 0; scanf("%d", &a);
        while (front(dq) != a) {
            push_back(dq, front(dq));
            pop_front(dq); shift++;
        }
        ans += mint(dq->sz - shift, shift);
        pop_front(dq);
    }
    destroy_deque(dq);
    printf("%d\n", ans);
    return 0;
}
int mint(int a, int b) {
    return a < b ? a : b;
}
deque *create_deque() {
    deque *dq = (deque *)malloc(sizeof(deque));
    dq->head = (node *)malloc(sizeof(node));
    dq->tail = (node *)malloc(sizeof(node));
    assert(dq != NULL && dq->head != NULL && dq->tail != NULL);
    dq->head->prev = NULL;
    dq->head->next = dq->tail;
    dq->tail->prev = dq->head;
    dq->tail->next = NULL;
    dq->sz = 0;
    return dq;
}
int pop_front(deque *dq) {
    if (dq->sz == 0) return 0;
    node *n = dq->head->next;
    int tmp = n->x;
    dq->head->next = n->next;
    n->next->prev = dq->head;
    dq->sz--; free(n); return tmp;
}
void push_back(deque *dq, int x) {
    node *n = (node *)malloc(sizeof(node));
    assert(n != NULL); n->x = x;
    n->prev = dq->tail->prev; n->next = dq->tail;
    dq->tail->prev->next = n; dq->tail->prev = n; dq->sz++;
}
int front(deque *dq) {
    if (dq->sz == 0) return 0;
    return dq->head->next->x;
}
void destroy_deque(deque *dq) {
    while (dq->sz) pop_front(dq); free(dq->head); free(dq->tail); free(dq);
}