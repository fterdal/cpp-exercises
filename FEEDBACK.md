# Feedback

## Single Linked List

### Append / Prepend

- Fixed: Head and tail now correctly point to the same node on empty list. Looks good.

### DeleteHead

- Fixed: Now resets `tail` to `nullptr` when deleting the last element. Looks good.

### DeleteTail

- Fixed: Single-element case now sets both `head` and `tail` to `nullptr`.
- **Still open:** Multi-element case — after `delete ptr->next`, need to set `ptr->next = nullptr` so that `tail->next` isn't a dangling pointer.

### Destructor

- **Still open:** Uses `if` instead of `while` — only deletes one node. Needs to loop until the list is empty.

### Copy / Print

- Both look good.
