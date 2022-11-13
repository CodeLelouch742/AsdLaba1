#include "Painting.h"

struct Painting
{
    string title;
    string author;
    string school;
    double durability;
    int status;

    string toString() {
            stringstream buffer;
        buffer << title<< " " << author<< " " << school<< " " << durability<< " " << status;
        return buffer.str();
    }

    bool operator>(Painting other) const{
        return durability > other.durability;
    }

    bool operator<(Painting other) const{
        return durability < other.durability;
    }

    bool operator==(const Painting &rhs) const {
        return title == rhs.title &&
               author == rhs.author &&
               school == rhs.school &&
               durability == rhs.durability &&
               status == rhs.status;
    }

    bool operator!=(const Painting &rhs) const {
        return !(rhs == *this);
    }

    friend ostream &operator<<(ostream& os, const Painting& painting) {
        Painting paintingPointer = painting;
        os << paintingPointer.toString();
        return os;
    }
};
