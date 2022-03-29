// Closed Hashing (Progressive Overflow)
#include <stdio.h>
#include <string.h>
#include <windows.h>

// use id to mark as EMPTY or DELETED
#define SIZE 11
#define EMPTY 999
#define DELETED 1000
typedef char String[15];

typedef struct{
	int id;
	String color_name; // (use color_name as key) <- important
	String hex_value;	
	String complement[3]; // list of color_name
	int complement_count;	
} Color;

typedef struct {
	Color value;
	int next; 
} Node;

typedef struct {
	Node data[SIZE];
	int avail;
} Dictionary;

void init_Dict(Dictionary *D) {
    int i;
    D->avail = SIZE/2;

    // initialize the primes
    for (i = 0; i < D->avail; i++) {
        D->data[i].value.id = EMPTY;
        D->data[i].next = -1;
    }

    // initialize the synonyms
    for (i = D->avail; i < SIZE-1; i++) {
        D->data[i].value.id = EMPTY;
        D->data[i].next = i+1;
    }
    D->data[SIZE-1].next = -1;
}

int hash_func(String key) {
    int hash = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        hash += key[i];
    }
    return (hash*32) % (SIZE/2);
}

void Set2Dict(Dictionary *D, Color SET[], int set_count) {
    int i, *k, temp, hash;
    for (i = 0; i < set_count; i++) {
        hash = hash_func(SET[i].color_name);
        if (D->data[hash].value.id == EMPTY) {
            D->data[hash].value = SET[i];
        } else {
            for (k = &D->data[hash].next; *k != -1 && D->data[*k].value.id != EMPTY; k = &D->data[*k].next) {}
            temp = D->avail;
            D->avail = D->data[D->avail].next;

            *k = temp;
            D->data[temp].value = SET[i];
            D->data[temp].next = -1;
        }
    }
}

// returns the index if it is a member, returns -1 if not 
int member(Dictionary D, String key) {
    int index, hash;

    hash = hash_func(key);
    if (strcmp(D.data[hash].value.color_name, key) == 0) {
        index = hash;
    } else {
        for (index = D.data[hash].next; index != -1 && strcmp(D.data[index].value.color_name, key) != 0; index = D.data[index].next){}
    }

    return index;
}

void visualize(Dictionary D) {
    for (int i = 0; i < SIZE/2; i++) {
        printf("i[%d]: ", i);
        for (int k = i; k != -1 && D.data[k].value.id != EMPTY; k = D.data[k].next) {
            printf("|%2d %2d| ", D.data[k].value.id, D.data[k].next);
        }
        printf("\n");
    }
    printf("\n");
}

// complete all the other functions before trying this
void magic(Dictionary D, String key) {
    int index, complement;
    index = member(D, key);
    if (index != -1) {
        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

        SetConsoleTextAttribute(h, D.data[index].value.id);
        printf("%s", D.data[index].value.color_name);

        // print the complements
        for (int i = 0; i < D.data[index].value.complement_count; i++) {
            SetConsoleTextAttribute(h, 15);
            printf(" --> ");
            complement = member(D, D.data[index].value.complement[i]);
            SetConsoleTextAttribute(h, D.data[complement].value.id);
            printf("%s", D.data[complement].value.color_name);
        }

        SetConsoleTextAttribute(h, 15);
    } else {
        printf("color not found\n");
    }
}

int main() {

    Color SET[7] = {
        {0, "black", "#000000", {""}, 0},
        {1, "blue", "#0000FF", {"red"}, 1},
        {2, "green", "#00FF00", {"red", "violet"}, 2},
        {4, "red", "#FF0000", {"blue", "green"}, 2},
        {5, "magenta", "#FF00FF", {"green"}, 1},
        {3, "cyan", "#00FFFF", {"yellow", "magenta"}, 2},
        {14, "yellow", "#FFFF00", {"blue"}, 1}
    };

    Dictionary D;
    init_Dict(&D);
    Set2Dict(&D, SET, 7);
    visualize(D);
    magic(D, "blue");
    return 0;
}