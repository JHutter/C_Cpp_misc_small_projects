/*	circularList.c: circular doubly linked list implementation. */
/* Author: Jon Hutter
 * Date: 2016-04-25
 * Name: circularList.c
 * Solution: implements circular doubly linked list for deque */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "circularList.h"

// Double link
struct Link
{
	TYPE value;
	struct Link * next;
	struct Link * prev;
};

struct CircularList
{
	int size;
	struct Link* sentinel;
};

/**
 * Allocates the list's sentinel and sets the size to 0.
 * The sentinel's next and prev should point to the sentinel itself.
 */
static void init(struct CircularList* list)
{
	// FIXME: you must write this
	list->size = 0;
	list->sentinel = malloc(sizeof(struct Link));
	assert(list->sentinel);
	list->sentinel->value = 0;
	list->sentinel->prev = list->sentinel;
	list->sentinel->next = list->sentinel;
}

/**
 * Creates a link with the given value and NULL next and prev pointers.
 */
static struct Link* createLink(TYPE value)
{
	// FIXME: you must write this
	struct Link *link;
	link = malloc(sizeof(struct Link));
	assert(link);
	link->value = value;
	link->prev = 0;
	link->next = 0;
	return link;
}

/**
 * Adds a new link with the given value after the given link and
 * increments the list's size.
 */
static void addLinkAfter(struct CircularList* list, struct Link* link, TYPE value)
{
	// FIXME: you must write this
    struct Link *newLink = createLink(value);
    newLink->prev = link;
    newLink->next = link->next;
    link->next->prev = newLink;
    link->next = newLink;
	list->size++;
}

/**
 * Removes the given link from the list and
 * decrements the list's size.
 */
static void removeLink(struct CircularList* list, struct Link* link)
{
	// FIXME: you must write this
	link->prev->next = link->next;
	link->next->prev = link->prev;
	free(link);
	list->size--;
}

/**
 * Allocates and initializes a list.
 */
struct CircularList* circularListCreate()
{
	struct CircularList* list = malloc(sizeof(struct CircularList));
	init(list);
	return list;
}

/**
 * Deallocates every link in the list and frees the list pointer.
 */
void circularListDestroy(struct CircularList* list)
{
	// FIXME: you must write this
	while (!list->size) {
        removeLink(list, list->sentinel->next);
	}
	free(list);
}

/**
 * Adds a new link with the given value to the front of the deque.
 */
void circularListAddFront(struct CircularList* list, TYPE value)
{
	// FIXME: you must write this
	addLinkAfter(list, list->sentinel, value);
}

/**
 * Adds a new link with the given value to the back of the deque.
 */
void circularListAddBack(struct CircularList* list, TYPE value)
{
	// FIXME: you must write this
	addLinkAfter(list, list->sentinel->prev, value);

}

/**
 * Returns the value of the link at the front of the deque.
 */
TYPE circularListFront(struct CircularList* list)
{
	// FIXME: you must write this
	assert(list->size);
	return list->sentinel->next->value;
}

/**
 * Returns the value of the link at the back of the deque.
 */
TYPE circularListBack(struct CircularList* list)
{
	// FIXME: you must write this
	assert(list->size);
	return list->sentinel->prev->value;
}

/**
 * Removes the link at the front of the deque.
 */
void circularListRemoveFront(struct CircularList* list)
{
	// FIXME: you must write this
	assert(list->size);
	removeLink(list, list->sentinel->next);
}

/**
 * Removes the link at the back of the deque.
 */
void circularListRemoveBack(struct CircularList* list)
{
	// FIXME: you must write this
	assert(list->size);
	removeLink(list, list->sentinel->prev);
}

/**
 * Returns 1 if the deque is empty and 0 otherwise.
 */
int circularListIsEmpty(struct CircularList* list)
{
	// FIXME: you must write this
	if (list->size) {
        return 0;
	}
	else {
        return 1;
	};
}

/**
 * Prints the values of the links in the deque from front to back.
 */
void circularListPrint(struct CircularList* list)
{
	// FIXME: you must write this
	struct Link *cur = list->sentinel->next;
	if (list->size) {
        while (cur != list->sentinel) {
            printf("%f\n", cur->value);
            cur = cur->next;
        }

	}
	printf("\n");
}

/**
 * Reverses the deque.
 */
void circularListReverse(struct CircularList* list)
{
	// FIXME: you must write this
	struct Link *cur = list->sentinel;
	do {
        struct Link *tempNext = cur->next;
        struct Link *tempPrev = cur->prev;
        cur->next = tempPrev;
        cur->prev = tempNext;

        cur = tempNext;
	}
	while (cur != list->sentinel);
}
