#include "PaintingJsonUtil.h"

CustomList<Painting>* listFromJsonString(string json)
{
    if(json == "NULL") {
        return new CustomList<Painting> {};
    }

    CustomList<Painting>* list = new CustomList<Painting> {};
    Document doc;
    doc.Parse(json.c_str());

    for (Value::ConstValueIterator itr = doc.Begin(); itr!=doc.End(); ++itr)
    {
        const Value &cmd = *itr;
        Painting* painting = new Painting {};

        for (Value::ConstMemberIterator it = cmd.MemberBegin(); it != cmd.MemberEnd(); ++it)
        {
            string param = it->name.GetString();
            if(param == "title") {
                painting->title = it->value.GetString();
            } else if(param == "author") {
                painting->author = it->value.GetString();
            } else if(param == "school") {
                painting->school = it->value.GetString();
            } else if(param == "durability") {
                painting->durability = it->value.GetDouble();
            } else if(param == "status") {
                painting->status = it->value.GetInt();
            }
        }

        list->add(painting);
    }

    return list;
}

void singleToJson(PrettyWriter<StringBuffer>& writer, Painting* painting)
{
    writer.StartObject();

    writer.String("title");
    writer.String(painting->title.c_str());

    writer.String("author");
    writer.String(painting->author.c_str());

    writer.String("school");
    writer.String(painting->school.c_str());

    writer.String("durability");
    writer.Double(painting->durability);

    writer.String("status");
    writer.Int(painting->status);

    writer.EndObject();
}

void listToJson(PrettyWriter<StringBuffer>& writer, CustomList<Painting>* paintingList)
{
    writer.StartArray();

    CustomListItem<Painting>* temp = paintingList->head;
    while(temp->next != NULL) {
        temp = temp->next;
        singleToJson(writer, temp->value);
    }

    writer.EndArray();
}

string jsonStringFromList(CustomList<Painting>* paintingList)
{
    StringBuffer buffer;
    PrettyWriter<StringBuffer> writer(buffer);
    listToJson(writer, paintingList);
    return buffer.GetString();
}

