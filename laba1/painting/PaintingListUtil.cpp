#include "PaintingListUtil.h"

CustomList<Painting>* getIndexPainting(CustomList<Painting>* list, int index)
{
    CustomList<Painting>* subList = new CustomList<Painting> {};

    CustomListItem<Painting>* temp = list->head;
    while(temp->hasNext()) {
        temp = temp->next;
        if(temp->index == index) {
            subList->add(temp->value);
        }
    }

    return subList;
}
