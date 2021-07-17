#include <stdlib.h>
#include <string.h>
#include "list.h"

/* list_init  */
void list_init(List *list, void(*destroy)(void * data)){
    /* Initialize the list. */
    list->size = 0;
    list->destroy = destroy;
    list->head = NULL;
    list->tail = NULL;
    return;
};

/* list_destroy */
void list_destroy(List *list){
    void *data;
    // Remove each element
    while (list_size(list)>0){
        if (list_rem_next(list,NULL,(void **)&data)==0 && 
            list->destroy != NULL){
            // call a user-defined function to freee dynamically allocated data
            
            list->destroy(data);
        }
    }
    /* No operations are allowed now, but clear the struct are a precaution */
    memset(list,0,sizeof(list));
    return;
}

/* list_ins_next */
int list_ins_next(List *list,ListElmt *element,const void *data){
    ListElmt *new_element;
    // Allocate sorage for the element
    if ((new_element = (ListElmt *)malloc(sizeof(ListElmt))) == NULL)
    {
        return -1;
    }

    // Insert the element into the list
    new_element->data = (void *)data;
    
}










