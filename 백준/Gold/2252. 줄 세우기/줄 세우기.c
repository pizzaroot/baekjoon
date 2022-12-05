#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef struct Node {
    struct Node *next;
    int x;
} node;
void insert(node *, int);
int main() {
    int n, m, left = 0, right = -1; scanf("%d%d", &n, &m);
    node **adj = (node **)malloc((n + 1) * sizeof(node *));
    int *indegree = (int *)malloc((n + 1) * sizeof(int));
    int *order = (int *)malloc(n * sizeof(int));
    int *queue = (int *)malloc((n + 1) * sizeof(int));
    assert(adj != NULL && indegree != NULL && order != NULL && queue != NULL);
    for (int i = 1; i <= n; i++) {
        indegree[i] = 0;
        adj[i] = (node *)malloc(sizeof(node));
        assert(adj[i] != NULL);
        adj[i]->next = NULL;
    }
    for (int i = 0; i < m; i++) {
        int u, v; scanf("%d%d", &u, &v);
        insert(adj[u], v);
        indegree[v]++;
    }
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) queue[++right] = i;
    }
    int idx = 0;
    while (left <= right) {
        int u = queue[left++];
        order[idx++] = u;
        node *cur = adj[u];
        while (cur->next) {
            cur = cur->next;
            if (--indegree[cur->x] == 0) queue[++right] = cur->x;
        }
    }
    for (int i = 0; i < n; i++) printf("%d%c", order[i], " \n"[i == n - 1]);
    free(indegree); free(order); free(queue);
    for (int i = 1; i <= n; i++) free(adj[i]);
    free(adj);
    return 0;
}
void insert(node *n, int x) {
    node *tmp = n->next;
    n->next = (node *)malloc(sizeof(node));
    assert(n->next != NULL);
    n->next->next = tmp;
    n->next->x = x;
    return;
}
