int delete(Node **head, int value) {
   Node *prev = NULL, *current = *head;

   while (current != NULL && current->data != value) {
      prev = current;
      current = current->next;
   }
   if (current == NULL){
      return 0;  /* not found */
   }
   if (prev == NULL) {
      *head = current->next;  /* deleted first item */
   } else {
      prev->next = current->next;
   }
   free(current);

   return 1;
}