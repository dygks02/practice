#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

struct node {
    int key;
    struct node *next;
};
typedef struct node Node;

void init_head(Node *);
Node* new_node();
int check_null(Node *);
int add_node(Node *,Node *,int);
void print_node(Node *);
void free_node(Node *,int);
int delete_node(Node *,int);
void search_node(Node *,int);
void swap(Node*,Node*);
void sort_node(Node *,int);


int main() {
  Node head;
  init_head(&head);
  Node a;
  int count = 0; // node 개수
  int i = 0;
  while(i < 5) {
    count = add_node(&head,new_node(),count);
    i++;
  }
  print_node(&head);
  count = delete_node(&head, count);
  print_node(&head);
  search_node(&head,count);
  sort_node(&head,count);
  print_node(&head);
  free_node(&head,count);
  return 0;
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

int check_null(Node *head) {
    if(head->next == NULL) {
        printf("not exist node(no print)\n");
        return 1;
    }
    return 0;
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
  int count = 0;
  do{
    if(check_null(head)) return;
    current = current->next;
    count++;
    printf("Node %d -> key: %d\n\n",count ,current->key);
  }while(current->next != NULL);
}

void free_node(Node *head,int count) {
    Node *current = head;
    if(check_null(head)) return;
    else {
        Node *temp[count];
        for(int i = 0; i < count; i++) { //바로 free하면 다음 노드 주소도 삭제되니까 미리 배열에 저장
            current = current->next;
            temp[i] = current;
        }
        for(int i = 0; i < count; i++) {
            free(temp[i]);
            printf("Node %d: free\n",i+1);
        }
    }
    
}

int delete_node(Node *head,int count) {
    Node *current = head;
    int i = 0;
    if(check_null(head)) return 0;
    else {
        while(current->next->next != NULL) {
            current = current->next;
        }
        Node *temp = current->next;
        current->next = NULL;
        free(temp);
    }    
    return count -1;
}

void search_node(Node *head,int count) {
    Node *current = head;
    if(check_null(head)) return ;
    int key;
    printf("Find key: ");
    scanf("%d",&key);
    int check = 0;
    for(int i = 0;i< count; i++) {
        current = current->next;
        if(key == current->key) {
            printf("Exist!\nNode %d -> key: %d\n\n",i+1,key);
            check++;
        }
    }
    if(check == 0) printf("no exist key\n");
}

void swap(Node *a,Node *b) {
    int temp;
    temp = a->key;
    a->key = b->key;
    b->key = temp;
}

void sort_node(Node *head,int count) {
    Node *current = head;
    if(check_null(head)) return;
    current = current->next;
    int min;
    Node *node;
    for(int i = 0;i<count; i++) {//
        int check = 0;
        min = current->key;
        Node *temp = current->next;
        for(int k = i+1; k < count; k++) {
            if(min > temp->key) {
                min = temp->key;
                node = temp;
                check = 1;
            }
            temp = temp->next; 
        }
        if(check == 1)swap(current,node);
        current = current->next;
    }
    printf("\nsort complete\n");
}


