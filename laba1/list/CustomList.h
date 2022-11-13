#include "CustomListItem.h"

#include "iostream"
#include <string>
#include <sstream>

using namespace std;

template <typename T> struct CustomList
{
    CustomListItem<T>* head = new CustomListItem<T>();
    int size = 0;

    T* get(int index)
    {
        if(size == 0) {
            return NULL;
        }

        CustomListItem<T>* temp = head;
        while(temp->hasNext()) {
            temp = temp->next;
            if(temp->index == index) {
                return temp->value;
            }
        }

        return NULL;
    }

    bool isEmpty(){
        if(size == 0) {
            return true;
        }
        else{
            return false;
        }
    }

    void add(T* value)
    {
        CustomListItem<T>* temp = head;
        while(temp->hasNext()) {
            temp = temp->next;
        }

        temp->next = new CustomListItem<T>(value, size++, NULL);
    }

    void add(int index, T* value)
    {
        if(index < 0 || index >= size) {
            return;
        }

        CustomListItem<T>* temp = head;
        while(temp->hasNext() && temp->next->index != index) {
            temp = temp->next;
        }

        if(temp->hasNext()) {
            temp->next = new CustomListItem<T>(value, temp->index, temp->next);
            while(temp->hasNext()) {
                temp->next->index++;
                temp = temp->next;
            }
        } else {
            temp->next = new CustomListItem<T>(value, size, NULL);
        }

        size++;
    }

    void remove(int index, bool dirty)
    {
        if(index < 0 || index >= size) {
            return;
        }

        CustomListItem<T>* temp = head;
        CustomListItem<T>* toDelete = NULL;
        while(temp->hasNext()) {
            toDelete = temp->next;
            if(toDelete->index == index) {
                break;
            }
            temp = temp->next;
        }

        if(toDelete != NULL && toDelete->index == index) {
            if(toDelete->hasNext()) {
                temp->next = toDelete->next;
                while(temp->hasNext()) {
                    temp = temp->next;
                    temp->index--;
                }
            } else {
                temp->next = NULL;
            }
            
            if(!dirty) {
                delete toDelete->value;
            }
            delete toDelete;

            size--;
        }
    }

    void remove(int index)
    {
        remove(index, false);
    }

    void clear(bool dirty)
    {
        if(size == 0) {
            return;
        }

        if(!dirty)
        {
            CustomListItem<T>* previous = NULL;
            CustomListItem<T>* temp = head->next;

            while(temp != NULL) {
                previous = temp;
                temp = temp->next;
                delete previous->value;
                delete previous;
            }

        }

        head->next = NULL;
        size = 0;
    }

    void clear()
    {
        clear(false);
    }

    string toString()
    {
        if (isEmpty()){
            return "[EMPTY LIST]";
        }

        stringstream buffer;
        buffer << "size:" << size << " content:[";

        CustomListItem<T>* temp = head;
        while(temp->hasNext()){
            temp = temp->next;
            buffer << "(index: " << temp->index << ", value: ";
            buffer << *(temp->value);
            buffer << ")";
            if(temp->hasNext()) {
                buffer << ", ";
            }
        }
        buffer << "]";

        return buffer.str();
    }

    friend ostream &operator<<(ostream &os, const CustomList &list) {
        CustomList listPointer = list;
        os << listPointer.toString();
        return os;
    }
};
