/* The Tom and Jerry Traversal */
prev = NULL;
curr = head;
while (curr != NULL) {
    /* Processing */
    prev = curr;
    curr = curr->next;
}