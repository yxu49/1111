#ifndef LOCK_H
#define LOCK_H

#include "threads/semaphore.h"

/* Lock */
struct lock {
    struct thread *holder; /* Thread holding lock (for debugging) */
    struct semaphore semaphore; /* Binary semaphore controlling access */
    struct list_elem elem;
    int max_priority;
};

void lock_init(struct lock *);
void lock_acquire(struct lock *);
bool lock_try_acquire(struct lock *);
void lock_release(struct lock *);
bool lock_held_by_current_thread(const struct lock *);
bool lock_cmp_priority(const struct list_elem *, const struct list_elem *, void *aux);
#endif /* UCSC CMPS111 */
