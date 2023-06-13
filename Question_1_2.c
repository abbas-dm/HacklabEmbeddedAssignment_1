#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int length(Node *head){
    Node *temp = head;
    int count = 0;
    while(temp != NULL){
        temp = temp -> next;
        count++;
    }
    return count;
}

// 1.2.1
Node* insertAtBeginning(Node* head, int data) {
    Node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;

    return head;
}

Node* insertAtEnd(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    return head;
}

Node* insertAtPosition(Node* head, int position, int data){
    int count = length(head);
    
    if(position == 1){
        head = insertAtBeginning(head, data);
        return head;
    }
    if((count+1) == position){
        head = insertAtEnd(head, data);
        return head;
    }

    if(count < position){
        printf("Given Position is out of range! \n");
        return head;
    }

    Node *prevNode = NULL;
    Node *temp = head;
    while(position > 1 && temp != NULL){
        position--;
        prevNode = temp;
        temp = temp->next;
    }
    Node* newNode = createNode(data);
    prevNode -> next = newNode;
    newNode -> next = temp;

    return head;
}

//1.2.2
Node* deleteNodeByPosition(Node* head, int position) {
    if (head == NULL) {
        printf("Linked List is empty!\n");
        return NULL;
    }

    Node* temp = head;

    if (position == 0) {
        head = temp->next;
        return head;
    }

    for (int i = 0; temp != NULL && i < position-1; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position!\n");
        return NULL;
    }

    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    nodeToDelete = NULL;

    return head;
}

//1.2.3
Node* deleteAllNodes(Node* head, int data) {
    Node* current = head;
    Node* prevNode = NULL;

    while (current != NULL) {
        if (current->data == data) {
            if (prevNode == NULL) {
                head = current->next;
                current = head;
            } else {
                prevNode->next = current->next;
                current = prevNode->next;
            }
        } else {
            prevNode = current;
            current = current->next;
        }
    }

    return head;
}

//1.2.5
void displayList(Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

//1.2.4
Node* deleteList(Node* head) {
    Node* current = head;
    Node* nextNode;

    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }

    head = NULL;

    return head;
}

int main() {
    Node* head = NULL;

    head = insertAtBeginning(head, 1);
    head = insertAtBeginning(head, 20);
    head = insertAtEnd(head, 1);
    head = insertAtEnd(head, 1);
    head = insertAtEnd(head, 1);
    displayList(head);

    // Deletes nodes at the given position
    head = deleteNodeByPosition(head, 1);
    displayList(head);

    // Inserting at given position
    head = insertAtPosition(head, 5, 1);
    displayList(head);

    // Deletes all then nodes containing value as 5
    head = deleteAllNodes(head, 1);
    displayList(head);

    // frees all the nodes memory
    head = deleteList(head);
    displayList(head);

    return 0;
}
