#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10000

typedef struct Node {
  char code[256];
  char room[256];
  struct Node* left;
  struct Node* right;
} Node;

Node all[MAX];
int n = 0;
int count = 0;
Node* root = NULL;

Node* makeNode(char* code, char* room) {
  Node* p = (Node*)malloc(sizeof(Node));
  strcpy(p->code, code);
  strcpy(p->room, room);
  p->left = NULL;
  p->right = NULL;
  return p;
}

Node* insertNode(Node* r, char* code, char* room) {
  if (r == NULL)
    return makeNode(code, room);

  int c = strcmp(r->code, code);
  if (c == 0) {
    return r;
  } else if (c < 0) {
    r->right = insertNode(r->right, code, room);
    return r;
  } else {
    r->left = insertNode(r->left, code, room);
    return r;
  }
}

Node* find(Node* r, char* code) {
  if (r == NULL)
    return NULL;

  int c = strcmp(r->code, code);
  count++;
  if (c == 0)
    return r;
  if (c < 0)
    return find(r->right, code);
  return find(r->left, code);
}

void inOrder(Node* r) {
  if (r == NULL)
    return;
  inOrder(r->left);
  printf("%s ", r->code);
  inOrder(r->right);
}

void storeInOrder(Node* r, char** array, int* index) {
  if (r == NULL)
    return;
  storeInOrder(r->left, array, index);
  strcpy(array[*index], r->code);
  (*index)++;
  storeInOrder(r->right, array, index);
}

void printArray(char** array, int size) {
  for (int i = 0; i < size; i++) {
    printf("%s", array[i]);
    if(i < size - 1) printf(" ");
  }
}

int countNodes(Node* r) {
  if (r == NULL)
    return 0;
  return countNodes(r->left) + countNodes(r->right) + 1;
}

int main() {
  while (1) {
    char command[256];
    scanf("%s", command);
    char eof[256];
    if (strcmp(command, "insert") == 0) {
      char code[256], room[256];
      scanf("%s %s", code, room);
      root = insertNode(root, code, room);
    } else if (strcmp(command, "inOrder") == 0) {
      scanf("%s", eof);
      if (strcmp(eof, "#") == 0) {
        int nodeCount = countNodes(root);

        char** inOrderArray =(char**) malloc(nodeCount * sizeof(char*));
        for (int i = 0; i < nodeCount; i++) {
          inOrderArray[i] = (char*)malloc(256 * sizeof(char));
        }

        int index = 0;
        storeInOrder(root, inOrderArray, &index);

        printArray(inOrderArray, nodeCount);

        for (int i = 0; i < nodeCount; i++) {
          free(inOrderArray[i]);
        }
        free(inOrderArray);

        printf("!");

        return 0;
      }
    } else if (strcmp(command, "countStep") == 0) {
      count = 0;
      char keyword[256];
      scanf("%s", keyword);
      scanf("%s", eof);
      if (strcmp(eof, "#") == 0) {
        find(root, keyword);
        printf("%d", count);
        return 0;
      }
    } else if (strcmp(command, "#") == 0)
      return 0;
  }
  return 0;
}
