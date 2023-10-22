#include<stdio.h>
#include<stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

void insertStart (struct Node **head, int data)
{
  struct Node *newNode = (struct Node *) malloc (sizeof (struct Node));
  newNode->data = data;
    if(*head == NULL)
    {
      *head = newNode;
      (*head)->next = *head;
      return;
    }
  struct Node *curr = *head;
  while (curr->next != *head)
  {
      curr = curr->next;
  }
  curr->next = newNode;
  newNode->next = *head;
  *head = newNode;
}

void display (struct Node *head)
{
  if (head == NULL)
    return;
  struct Node *temp = head;
    do
    {
      printf ("%d ", temp->data);
      temp = temp->next;
    }
  while (temp != head);
  printf ("\n");
}

int main ()
{
  struct Node *head = NULL;
  printf ("Linked List: ");
  insertStart (&head, 40);
  insertStart (&head, 30);
  insertStart (&head, 20);
  insertStart (&head, 10);
  display (head);
  return 0;
}
