int insert(Node **head, int new_value) {
   Node *current = *head, *prev = NULL, *new_item;

   while (current != NULL && new_value > current->data) {
      prev = current;
      current = current->next;
   }

   new_item = malloc(sizeof(Node));
   if (new_item == NULL) {
      return 0;
   }
   new_item->data = new_value;
   new_item->next = current;
   if (prev == NULL) { /* inserting at the beginning */ 
      *head = new_item;
   } else {
      prev->next = new_item;
   }

   return 1;
}