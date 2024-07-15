#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    int numchild[n];
    int id1[n], id2[n];
    char child[n][50];  
    char father[n][50];  
    for (int i = 0; i < n; i++) {
        scanf("%d",&id1[i]);
        scanf("%d",&id2[i]);
		scanf("%s", father[i]);
        scanf("%d", &numchild[i]);
        for (int j = 0; j < numchild[i]; j++) {
            scanf("%s", child[j]);  
        }
    }
    int cnt = 0;
    char A[50];  
    strcpy(A, father[0]);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < numchild[i]; j++) {
            int k = strcmp(A, child[j]);  
            if (k == 0) cnt++;
        }
    }
    printf("%d", cnt);
    return 0;
}
