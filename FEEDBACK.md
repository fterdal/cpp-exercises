# Feedback

## Single Linked List

### Append / Prepend

- Fixed: Head and tail now correctly point to the same node on empty list. Looks good.

### DeleteHead

- Fixed: Now resets `tail` to `nullptr` when deleting the last element. Looks good.

### DeleteTail

- Fixed: Single-element case now sets both `head` and `tail` to `nullptr`.
- Fixed: Multi-element case now sets `ptr->next = nullptr` after delete. Looks good.

### Destructor

- Fixed: Now uses `while` loop to delete all nodes. Looks good.

### Copy / Print

- Both look good.
