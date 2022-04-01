/*
    ♩ ♪ ♫ ♬ ♭ ♩ ♪ ♫ ♬ ♭ 
    ╔═════════════════╗
    ║ The Office in C ║
    ╚═════════════════╝
    ♩ ♪ ♫ ♬ ♭ ♩ ♪ ♫ ♬ ♭ 

    Dwight's Instructions: 
        1. Closed hashing 
            a. Variation: Linear Hashing/Probing
        2. use Employee fname as 'key' 
            a. Apply the macro EMPTY, DELETED to key to 
               determine if position is occupied, empty or deleted.
        3. array is circular
            a. use modulo to circle the array.
        4. in this case the key is a string so be careful 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EMPTY "EMPTY"
#define DELETED "DELETED"
#define SIZE 32

typedef char Key[20]; 
typedef struct {
    int id;
    Key fname;
    char lname[20];
    char job_title[60];
    char quote[150];
} Employee;

typedef struct {
    char branch_name[20];
    Employee *value;         // pointer to a dynamic array
    int count;               // use this to deterine if Dictionary is full
} Dictionary;

// initializes an empty array with the SIZE 27, set the branch name
void init_dict(Dictionary *D, char branch_name[]) {
    D->count = 0;
    strcpy(D->branch_name, branch_name);
    D->value = (Employee*) malloc(sizeof(Employee) * SIZE);

    if (D->value != NULL) {
        for (int i = 0; i < SIZE; i++) {
            strcpy(D->value[i].fname, EMPTY);
        }
    }
}

// Accepts fname, create ur own hash algo. :)
int get_hash(Key fname) {
    int hash, i;
    hash = 0;
    for (i = 0; fname[i] != '\0'; i++)
        hash += fname[i];
    return (hash * strlen(fname)) % SIZE;
}

// Accepts a dictionary and an employee
void insert_dict(Dictionary *D, Employee E) {
    if (D->count < SIZE-1) {
        int i, hash;
        hash = get_hash(E.fname);
        for (i = hash; strcmp(D->value[i].fname,EMPTY)!=0 && strcmp(D->value[i].fname,DELETED)!=0;
        i = (i+1)%SIZE) {}
        D->value[i] = E;
        D->count++;
    }
}

// Accepts a dictionary and Key
void delete_dict(Dictionary *D, Key fname) {
    if (D->count > 0) {
        int i, hash;
        hash = get_hash(fname);
        for (i = hash; strcmp(D->value[i].fname,EMPTY)!=0 && strcmp(D->value[i].fname,fname)!=0; i = (i+1)%SIZE) {}
        if (strcmp(D->value[i].fname,fname)==0) {
            strcpy(D->value[i].fname, DELETED);
            D->count--;
        }
    }
}

// return 1 if found 0 if not
int is_member(Dictionary D, Key fname) {
    int i, hash;
    hash = get_hash(fname);
    for (i = hash; strcmp(D.value[i].fname, EMPTY) != 0 && strcmp(D.value[i].fname,fname)!=0; i = (i+1)%SIZE){}
    if (strcmp(D.value[i].fname,fname)==0) 
        return 1;
    return 0;
}

// 
void visualize(Dictionary D) {
    int i, k, hash, asl, sl;
    asl = 0;
    printf("Welcome to the %s branch!\n", D.branch_name);
    printf("Dictionary Count: %d\n", D.count);
    printf("%5s: %15s %5s %15s\n", "Index", "Name", "Hash", "Search Length");
	for (i = 0; i < SIZE; i++) {
        if (strcmp(D.value[i].fname, EMPTY)!=0) {
            hash = get_hash(D.value[i].fname);
            sl = (i+1)-hash;
            asl += sl;
            printf("i[%2d]: %15s %5d %15d\n", i, D.value[i].fname, hash, sl);
        }
    }
    if (D.count > 0) 
        asl = asl / D.count;
    printf("Average Search Length: %d\n", asl);
}

int main() {

    Employee data[] = {
            {0, "Michael", "Scott", "Regional Manager", "I. Declare. Bankruptcy!"},
            {1, "Jim", "Halpert", "Salesman", ""},
            {2, "Dwight", "Schrute", "Assistant To The Regional Manager", ""},
            {3, "Pam", "Beesly", "Receptionist", "I feel God in this Chili’s tonight."},
            {4, "Ryan", "Howard", "Temp", ""},
            {5, "Kelly", "Kapoor", "Customer Service Specialist", ""},
            {6, "Angela", "Martin", "Accountant", ""},
            {7, "Kevin", "Malone", "Accountant", ""},
            {8, "Oscar", "Martinez", "Accountant", ""},
            {9, "Andy", "Bernard", "Salesman", "I Went To Cornell. Ever Heard Of It?"},
            {10, "Stanley", "Hudson", "Salesman", ""},
            {11, "Phyllis", "Lapin", "Saleswoman", ""},
            {12, "Toby", "Flenderson", "Human Resources Representative", "Why You Always Gotta Be So Mean To Me?"},
            {13, "Erin", "Hannon", "Receptionist", "Planking Is One Of Those Things Where, Hey, You Either Get It Or You Don't. And I Don't."},
            {14, "Gabe", "Lewis", "Coordinating Director of Emerging Regions", ""},
            {15, "Darryl", "Philbin", "Warehouse Foreman", ""},
            {16, "Creed", "Bratton", "Quality Assurance Director", ""},
            {17, "Jo", "Bennett", "CEO of Sabre", ""},
            {18, "Nellie", "Bertram", "Sabre's President Of Special Projects", ""},
            {19, "Holly", "Flax", "Human Resources Representative", ""},
            {20, "Jan", "Levinson", "Vice President of Sales at Dunder Mifflin", ""},
            {21, "Todd", "Packer", "Traveling salesman", ""},
            {22, "Charles", "Minor", "Vice President of Northeast Sales for Dunder Mifflin", ""},
            {23, "Deangelo", "Vickers", "Regional Manager", ""},
            {24, "Josh", "Porter", "Regional Manager", ""},
            {25, "Meredith", "Palmer", "Supplier Relations", ""},
            {26, "Hunter", "null", "Assistant", ""},
            {27, "David", "Wallace", "Chief Financial Officer", ""}
    };

    Dictionary D;
    init_dict(&D, "Scranton");

    for(int i = 0; i < 28; i++)
        insert_dict(&D, data[i]);
    
    visualize(D);
    free(D.value);

    return 0;
}