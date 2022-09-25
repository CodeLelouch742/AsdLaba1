#ifndef lab1_PAINTINGJSONUTIL_H
#define lab1_PAINTINGJSONUTIL_H

#include <string>
#include <sstream>

#include "Painting.cpp"
#include "../list/CustomList.h"

#include "../lib/rapidjson/document.h"
#include "../lib/rapidjson/stringbuffer.h"
#include "../lib/rapidjson/prettywriter.h"

using namespace std;
using namespace rapidjson;

CustomList<Painting>* listFromJsonString(string);
void singleToJson(PrettyWriter<rapidjson::StringBuffer>&, Painting);
void listToJson(PrettyWriter<StringBuffer>&, CustomList<Painting>*);
string jsonStringFromList(CustomList<Painting>*);

#endif //lab1_PAINTINGJSONUTIL_H
