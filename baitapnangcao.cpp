#include "stdlib.h"
#include "stdio.h"

struct Node {
    int num;
    struct Node *Next;
};

typedef struct Node *PtrToNode;

int main() {
    int n, m, i;
    PtrToNode head, p, q;

    printf("Please input n, m\n");
    scanf("%d %d", &n, &m);
    printf("Input was n=%d, m=%d\n", n, m);

    head = (PtrToNode)malloc(sizeof(struct Node));
    head->num = 1;

    p = head;
    for (i = 2; i <= n; i++) {
        q = (PtrToNode)malloc(sizeof(struct Node));
        q->num = i;
        p->Next = q;
        p = q;
    }
    p->Next = head;

    while (q->Next != q) {
        for (i = 1; i < m+1; i++)
            q = q->Next;
        p = q->Next;
        printf("%d, ", p->num);
        q->Next = p->Next;
        free(p);
    }
    printf("%d\n", q->num);
    free(q);
    return 0;
}
