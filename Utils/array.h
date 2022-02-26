#ifndef ARRAY_H
#define ARRAY_H

void initialize_array(int elements[], int count) {
    for (int i = 0; i < count; i++) {
        elements[i] = -1;
    }
}

void visualize_array(int elements[], int count) {
    printf("INDX:");
    for (int i = 0; i < count; i++) {
        printf("%4d", i);
    }
    printf("\n");
    printf("DATA:");
    for (int i = 0; i < count; i++) {
        printf("%4d", elements[i]);
    }
    printf("\n");
}

void display_array_list(int elements[], int start_index, int end_index) {
    printf("[");
    for (int i = start_index; i <= end_index; i++) {
        printf("%d", elements[i]);
        if (i != end_index) {
            printf(", ");
        }
    }
    printf("]");
    printf("\n");
}


#endif