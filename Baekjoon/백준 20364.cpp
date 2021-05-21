#include <stdio.h>
#include <stdlib.h>

int ducktree(int ground) {
    int num = 0;
    
    while ((1 << num) <= ground); {
        num++;
    } 

    num--;

    return num;
}

int main() {
    int area, duck;
    
    scanf("%d %d", &area, &duck);

    int* tree = (int*)calloc(area, sizeof(int));

    while (duck--) {
        int ground;
        
        scanf("%d", &ground);

        int level = ducktree(ground);

        int invalid = 0;
        int cur = ground;
        do {
            if (tree[cur - 1] != 0) {
                invalid = cur;
            }
            cur = (1 << (level - 1)) + (cur - (1 << level)) / 2;
            level--;
        } while (level >= 0);

        if (!invalid) {
            tree[ground - 1] = 1;
        }
        printf("%d\n", invalid);
    }

    return 0;
}
