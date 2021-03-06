// LLIST1.C [140911]
// Code provided for ELEC278 Lab 1 Step 5

#include "llist1.h"

void insertFront(int v, LList1 *l)
{
    if (l != NULL)	{
        /* create new link */
        Link* link = initLink(v);

        /* has at least one element */
        if (!isEmpty(l))
        {
            link->next = l->head;
            l->head = link;
        } else {
            l->head = link;
        }
    }
}



Link* extract(int v, LList1 *list)
// Extract Element from list with value v and return it
// return NULL if no link exists with value v
{
    Link	*link1=NULL,
			*link2=NULL,
			*resLink=NULL ;

	// check if list is NULL
    if (list != NULL)	{
        if (list->head != NULL) /* something in list */
        {
			/* head contains value v */
            if (list->head->value == v)
            {
                resLink = list->head; // since the head contains the value, set the resulting link equal to head
                list->head = list->head->next;  //then make the head(first link) equal to the next link in the list, essentially removing the first link
            }
			/* head doesn't contain value v. Must traverse list to find it */
            else
            {
                link1 = list->head;
                link2 = link1->next;
				/* Move link1 and link2 until you find link with value v or reach end of list */
				/*** fill in code here ***/
				while (1) {
                    if(link2->value == v){
                        resLink = link2; // since link2 contains the value, set the resulting link equal to link2
                        link1->next = link2->next; // since we want to remove link2, make link1->next equal to link2's->next, essentially skipping link2
                        break;
                    }

                    if(link2->next == NULL) break; //no next link, therefore at the end of the list
                    /* link1 is now equal to link2, and link2 is equal to the next one, essentially forgetting about  */
                    else {
                        link1 = link2;
                        link2 = link2->next;
                    }

				}

				
				/* update resLink accordingly */
				/*** fill in code here ***/
            }
        }
    }
    return( resLink ) ;
}//extract()


int isEmpty (LList1 *l)
{
	if (l == NULL)	return 1;	// no list provided
    if (l->head == NULL)	return 1;	// list has no elements
    return 0;					// exiting list with elements - not empty
}//isEmpty()


Link* initLink (int v)
// Create a new linked list element and initialize the value field; set
// the next pointer to NULL
{
    Link* link = malloc(sizeof(Link));
    link->value = v;
    link->next = NULL;
    return link;
}//initLink()


LList1* initList ()
// Create a new linked list descriptor. The descriptor contains a description
// of the list - number of elements and a pointer to the first element.
{
    LList1 *list = malloc(sizeof(LList1));
    list->size = 0;
    list->head = NULL;
    return list;
}


void printList (LList1 *l)
{
    if (l != NULL) {
        if (!isEmpty(l)) {
            Link *link = l->head;
            while (link != NULL) {
                printf("%d-->",link->value);
                link = link->next;
            	}//endwhile
            printf("NULL\n");
		} else	{
			//list descriptor exists, but seems to have no elements
			printf (" <EMPTY>\n");
        	}//endif
    	}//endif valid list descriptor
}//printlist()


