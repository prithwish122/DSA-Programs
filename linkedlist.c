//Linked List Program

//header files
#include<stdio.h>
#include<stdlib.h>

//creating Linked List datastructure
typedef struct Node{
    int data;  
    struct Node *next; 
}Node;

//to insert item at beginning
void insertBegin(Node **phead, int data){
    Node *new_node;
    new_node=(Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    if(*phead == NULL)
        *phead = new_node;
    else{
        new_node->next = *phead;
        *phead = new_node;
    }
}

//to insert at end
void append(Node **phead, int data){
    Node *new_node;
    new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    if(*phead == NULL)
        *phead = new_node;
    else{
        Node *ptr;
        ptr = *phead;
        while(ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = new_node;
    }
}

//to find Node from given data
Node* searchKey(Node** phead, int key){
    Node* ptr = *phead;
    while(ptr->next != NULL && ptr->data != key)
        ptr = ptr->next;
    if(ptr->data == key)
        return ptr;
    else
        return NULL;
}

//to find Node from given position
Node* SearchPos(Node** phead, int pos){
    Node* ptr = *phead;
    int i;
    for(i=0; i<pos; i++){
        if((pos-1) != i)
            ptr = ptr->next;
    }
    if(ptr != NULL)
        return ptr;
    else
        return NULL;
}

//insert after given data of node
void insertAfter(Node *prevNode, int data){
    Node* new_node;
    new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->next = prevNode->next;
    prevNode->next = new_node;
}

//insert item at given position
void insertPosition(Node **phead, int data, int pos){
    int i;
    Node *new_node;
    new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    Node* prevNode = *phead;
    Node* ptr = *phead;

    for(i=0; i<pos; i++){
        if(i==0 && pos==1){
            new_node->next = *phead;
            *phead = new_node;
        }
        else{
            if(i==(pos-1) && ptr!=NULL){
                //prevNode->next = ptr->next;
                new_node->next = ptr;
                prevNode->next = new_node;
            }
            else{
                prevNode = ptr;
                ptr = ptr->next;
            }
        }
    }
}

//delete first Node
void deleteBeginning(Node** phead){
    if(*phead != NULL){
        Node* ptr = *phead;
        *phead = (*phead)->next; //*phead = ptr->next;
        free(ptr);
    }
    else
        printf("Empty Linked List!");
}

//delete last Node
void deleteEnd(Node** phead){
    if(*phead != NULL){
        Node* ptr = *phead;
        Node* prevNode = *phead;
        while(ptr->next != NULL){
            prevNode = ptr;
            ptr = ptr->next;
        }
        prevNode->next = NULL;
        free(ptr);
    }
    else
        printf("Empty Linked List!");
}

//delete Node after given data of Node
void deleteAfter(Node* prevNode){
    Node* ptr = prevNode->next;
    prevNode->next = prevNode->next->next;
    free(ptr);
}

//delete Node at given position
void deletePosition(Node** phead, int pos){
    Node* prevNode = *phead;
    Node* ptr = *phead;
    int i=0;

    if(pos == 1){
        *phead = prevNode->next;
        free(ptr);
    }
    else{
        while(ptr!= NULL && i!=pos-1){
            prevNode = ptr;
            ptr = ptr->next;
            i++;
        }
        prevNode->next = prevNode->next->next;
        free(ptr);
    }

}

//delete Node by data
void deleteKey(Node** phead, int key){
    Node* ptr = *phead;
    Node* prevNode = *phead;
    while(prevNode->data != key){
        prevNode = ptr;
        ptr = ptr->next;
    }
    prevNode->next = prevNode->next->next;        
    free(ptr);
}

//display items in nodes
void display(Node **phead){
    Node* ptr = *phead;
    while(ptr != NULL){
        printf("%d, ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main(){

    Node *head;
    head=NULL;
    int data, data2, pos, choice;

    while(1){
        printf("\nCHOICES-\n    1. ENTER AT BEGINNING\n    2. ENTER AT END\n    3. ENTER AFTER NODE\n    4. ENTER AT POSTION\n    5. DELETE AT BEGINNING\n    6. DELETE AT END\n    7. DELETE AFTER NODE\n    8. DELETE AT POSITION\n    9. DISPLAY\n    0. EXIT\n");
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch (choice){
            case 2:
                printf("Enter the Element:");
                scanf("%d",&data);
                append(&head,data);
                break;
            
            case 1:
                printf("Enter the Element:");
                scanf("%d",&data);
                insertBegin(&head, data);
                break;

            case 3:
                printf("Enter data of Node after which new Node to be added: ");
                scanf("%d",&data2);
                printf("Enter the Element:");
                scanf("%d",&data);
                insertAfter(searchKey(&head,data2),data);
                break;

            case 4:
                printf("Enter position at which new Node to be added: ");
                scanf("%d",&pos);
                printf("Enter the Element: ");
                scanf("%d",&data);
                insertPosition(&head, data, pos);
                break;

            case 5:
                deleteBeginning(&head);
                break;

            case 6:
                deleteEnd(&head);
                break;

            case 7:
                printf("Enter data of Node after which Node to be deleted: ");
                scanf("%d",&data2);
                deleteAfter(searchKey(&head, data2));
                break;

            case 8:
                printf("Enter position at which new Node to be added: ");
                scanf("%d",&pos);
                deletePosition(&head, pos);
                break;

            case 9:
                display(&head);
                break;

            case 0:
                exit(0);
                break;

            default:
                printf("\nInvalid Choice!\n");
        }
    }
    return 0;
}
