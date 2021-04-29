#include <stdio.h>
#include <string.h> 
#include <stdlib.h> 
#include <ctype.h> 

#define FALSE 0
#define TRUE 0
#define MAX 100

typedef struct treenode {
  struct treenode* leftChild;
  struct treenode* rightChild;
  char* nickname;
  char* contra; 
  unsigned int depth;
} node;
node* insert(char* u, char* p, node* pos, int d);
void copy(char l[MAX],char p[MAX],char u[MAX]);
void ordenamiento(node* position);
void celim(node* rama, char* u, char* p, int* n);
int saca();
char linea[MAX], contra[MAX], nickname[MAX];
int convert_to_line(char*, char*);
node* insert(char* , char* , node* , int );
void show(node*, char);
int del(node* ,char *, char*);
