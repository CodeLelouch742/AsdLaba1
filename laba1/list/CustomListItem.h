#include <ostream>

using namespace std;

template <typename T> struct CustomListItem
{
    T* value;
    int index;
    CustomListItem* next;

    CustomListItem(T* value, int index, CustomListItem* next) : value(value), index(index), next(next) {}

    CustomListItem() : value(NULL), index(-1), next(NULL) {}

    bool isPresent() {
        return value != NULL;
    }

    bool hasNext() {
        return next != NULL;
    }

    friend ostream &operator<<(ostream &os, const CustomListItem &item) {
        os << "value: " << item.value << " index: " << item.index << " next: " << item.next;
        return os;
    }
};
