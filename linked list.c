#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node *next;
};
typedef struct node Node;

void init_head(Node *);
Node* new_node();
int add_node(Node *,Node *,int);
void print_node(Node *);
void free_node(Node *,int);

void main() {
  Node head;
  init_head(&head);
  Node a;
  int count = 0; // node 개수
  count = add_node(&head,new_node(),count);
  count = add_node(&head,new_node(),count);
  count = add_node(&head,new_node(),count);
  print_node(&head);
  free_node(&head,count);
}

void init_head(Node *head) {
  head->key = 0;
  head->next = NULL;
}

Node* new_node() {
  Node *new_node = malloc(sizeof(Node));
  new_node->key = 0;
  new_node->next = NULL;
  return new_node;
}

int add_node(Node *head,Node *new_node,int count) {
  int i = 0;
  int key;
  Node *current = head;
  while(current->next != NULL) {
      i++;
      current = current->next;
  }
  current->next = new_node;
  printf("key: ");
  scanf("%d",&key);
  new_node->key = key;
  return count + 1;
}

void print_node(Node *head) {
  Node *current = head;
  do{
    if(current->next == NULL) {
      printf("not exist node");
      break;
    }
    current = current->next;
    printf("%d\n",current->key);
  }while(current->next != NULL);
}

void free_node(Node *head,int count) {
    Node *current = head;
    Node *temp[count];
    for(int i = 0; i < count; i++) {
        current = current->next;
        temp[i] = current;
    }
    for(int i = 0; i < count; i++) {
        free(temp[i]);
    }
}
