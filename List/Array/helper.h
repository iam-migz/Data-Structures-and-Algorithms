#ifndef HELPER_H
#define HELPER_H

void display(int elements[], int count) {
    for (int i = 0; i < count; i++) {
        printf("%d", elements[i]);
        if (i+1 != count) {
            printf(", ");
        }
    }
    printf("\n");
}


#endif