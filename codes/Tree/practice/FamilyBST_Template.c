#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

typedef char String[30];
typedef struct{
	String fname;
	String mname;
	String lname;
	char gender;
}FamilyName;

typedef struct{
	FamilyName members[MAX];
	int last; //last index
}Heap;

typedef struct node{
	FamilyName members;	
	struct node *left;
	struct node *right;
}*BST;

void initialize(BST *F);
void insertFamily(BST *F, FamilyName x);
void removeFamily(BST *F, String x); //x is last name
Heap convertToHeap(BST *F); //delete contents from BST F and insert all of them to a newly created heap
void displayInorder(BST F);
void displayHeap(Heap H);

int main(){
	FamilyName x[MAX] = {{"Mark", "Dupio", "Mendoza", 'M'}, {"Stacy", "Jel", "Cruz", 'F'}, {"Tori", "Crie", "Jellica", 'M'}, 
						{"Ben", "Cruz", "Holly", 'M'}, {"Travis", "Hobug", "Manuez", 'M'}, {"Steven", "Zomez", "Ralf", 'M'}, 
						{"Bryan", "Inigo", "Ola", 'M'}, {"Jane", "Ola", "Azenya", 'F'}, {"Kia", "Lopez", "Simmons", 'F'}, 
						{"Sokki", "Greece", "Holly", 'F'}};
	BST F;
	int i;
	
	initialize(&F);
//	for(i = 0; i < MAX; i++) insertFamily(&F, x[i]);
	printf("Last Name:\tFirst Name:\tMiddle Initial:\n"); displayInorder(F);
	
//	Heap H = convertToHeap(&F);

	return 0;
}

void initialize(BST *F){
}

void insertFamily(BST *F, FamilyName x){
}

void removeFamily(BST *F, String x){
}

Heap convertToHeap(BST *F){
}

void displayInorder(BST F){
	if(F != NULL){
		displayInorder(F->left);
		printf("%s\t-\t", F->members.lname);
		printf("%s\t-\t", F->members.fname);
		printf("%c\n", F->members.mname[0]);
		displayInorder(F->right);
	}
}

void displayHeap(Heap H){
	int i;
	for(i = 0; i <= H.last; i++){
		printf("%s\t-\t", H.members[i].lname);
		printf("%s\t-\t", H.members[i].fname);
		printf("%c\n", H.members[i].mname[0]);
	}
}
