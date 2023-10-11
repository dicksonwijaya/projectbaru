#include <stdlib.h> 
#include <stdio.h>
#include <stdbool.h>

// 定義節點的元素
struct node{
    int data;
    struct node *next;
};

struct node *head = NULL;

bool isEmpty();
void insert(int insert_data);
void printList();


bool isEmpty(){
    return head == NULL;
}

void insert(int insert_data){
    struct node* current = head;
    struct node* prev = NULL;

    while (current != NULL && current->data < insert_data) {
        prev = current;
        current = current->next;
    }

    printf("Inserting %d...\n", insert_data);

    if (current != NULL && current->data == insert_data) {
        if (prev != NULL) {
            prev->next = current->next;
        } else {
            head = current->next;
        }
        free(current);
    } else {
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = insert_data;
        newNode->next = current;
        if (prev != NULL) {
            prev->next = newNode;
        } else {
            head = newNode;
        }
    }
    printList();
}

void printList() {
    struct node *ptr = head;
    printf("[ ");
    //從頭開始印  
    while(ptr != NULL){
        printf("(%d) ", ptr->data);
        ptr = ptr->next;
    }
    printf(" ]\n");
}

int main(){
    
    int input;
    
    // fopen – opens a text file. 
    FILE *fp_r = fopen("input.txt", "r");
    
    // feof – detects end-of-file marker in a file. 
    while(!feof(fp_r)){
        // fscanf –reads formatted input from a file. 
        fscanf(fp_r, "%d ", &input);
        insert(input);
    }

    fclose(fp_r);

    return 0;
}