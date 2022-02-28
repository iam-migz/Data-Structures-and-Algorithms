#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Student record Definition
typedef struct {
    char FName[10], Mi, LName[10];
    unsigned int ID;
    char course[8];
    int yearLevel;
}studtype;

// Linked List Definition
typedef struct node {
    studtype stud;
    struct node *link;
}*LinkedList;

// Cursor-based List Definition
#define CB_SIZE 0X5
typedef struct {
    studtype stud;
    int link;
}cursorNode;

typedef struct {
    cursorNode VhNode[CB_SIZE];
    int availPtr;
}VHeapMemory;

typedef int CursorList;

void init_VHeap(VHeapMemory *VH) {
    for (int i = 0; i < CB_SIZE; i++) {
        VH->VhNode[i].link = i-1;
    }
    VH->availPtr = CB_SIZE - 1;
}

void populate_LL(LinkedList *L, studtype students[], int size) {
    for (int i = 0 ; i < size; i++) {
        *L = (LinkedList)malloc(sizeof(struct node));
        if (*L != NULL) {
            (*L)->stud = students[i];
            (*L)->link = NULL;
        }
        L = &(*L)->link;
    }
}

void clean_LL(LinkedList *L) {
    LinkedList temp;
    while (*L != NULL) {
        temp = *L;
        *L = (*L)->link;
        free(temp);
    }
}

CursorList getBSICT(LinkedList *L, VHeapMemory *VH) {
    LinkedList temp;
    CursorList BSICT, *trav, index;
    BSICT = -1;   
    
   while(*L != NULL) {
       if ( strcmp((*L)->stud.course, "BSICT") == 0 ) {
          temp = *L;
          *L = (*L)->link;
           for (trav = &BSICT; 
                *trav != -1 && temp->stud.ID > VH->VhNode[*trav].stud.ID; 
                 trav = &VH->VhNode[*trav].link){}
           
           index = VH->availPtr;
           if (index != -1) {
              VH->availPtr = VH->VhNode[index].link;
              VH->VhNode[index].link = *trav;
              VH->VhNode[index].stud = temp->stud;
              *trav = index;
           }
           free(temp);
       } else {
          L = &(*L)->link;
       }
    }
   return BSICT;
}

int main () {
    VHeapMemory VH;
    init_VHeap(&VH);
    
    studtype students[] = { 
        {.FName = "Jim", .LName = "Croce", .Mi = 'L', .course = "BSICT", .yearLevel = 3, .ID = 11 },
        {.FName = "Peter", .LName = "Parker", .Mi = 'S', .course = "BSCS", .yearLevel = 3, .ID = 5 },
        {.FName = "Michael", .LName = "Scott", .Mi = 'G', .course = "BSICT", .yearLevel = 3, .ID = 3 }
    };

    LinkedList L = NULL;
    populate_LL(&L, students, 3);
    CursorList CL = getBSICT(&L, &VH);

    // print cb
    for (int i = CL; i != -1; i = VH.VhNode[i].link) {
        printf("%s -> ", VH.VhNode[i].stud.FName);
    }
    printf("\n");

    // print ll
    for (LinkedList trav = L; trav != NULL; trav = trav->link) {
        printf("%s -> ", trav->stud.FName);
    }

    clean_LL(&L);

    return 0;
}