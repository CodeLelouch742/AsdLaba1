#include "Application.h"

string GALLERY_FILE = "gallery.json";
string REPAIR_FILE = "repair.json";

CustomList<Painting>* gallery = new CustomList<Painting> {};
CustomList<Painting>* repair = new CustomList<Painting> {};



int main()
{
    SetConsoleOutputCP(CP_UTF8);

    load();
    menu();

    return 0;
}

void menu()
{
    while (true)
    {
        system("cls");

        printBreakLine();
        cout << "Загружено картин в галерее:    " << gallery->size << endl;
        cout << "Загружено картин на ремонте:   " << repair->size << endl;
        printBreakLine();

        cout << "Выберите пункт меню из следующего списка:" << endl;
        cout << "|1 | Вывести все картины в галерее" << endl;
        cout << "|2 | Добавить элемент в начало списка" << endl;
        cout << "|3 | Добавление элемента по индексу" << endl;
        cout << "|4 | Добавление элемента в конец списка" << endl;
        cout << "|5 | Замена/Редактирование элемента на введённый пользователем" << endl;
        cout << "|6 | Удаление картины по индексу" << endl;
        cout << "|7 | Удаление всех картин из галереи" << endl;
        cout << "|8 | Вывод картины по индексу" << endl;
        cout << "|9 | Удаление первого элемента в списке" << endl;
        cout << "|10| Удаление последнего элемента в списке" << endl;
        cout << "|11| Последнее вхождения в список" << endl;
        cout << "|12| Сохранить данные на диск" << endl;
        cout << "|0 | Выйти из программы" << endl;

        printBreakLine();
        int select = inputInt("Выберите один из вариантов");
        printBreakLine();

        if(processSelect(select)) {
            return;
        }

        printBreakLine();
        system("pause");
    }
}

bool processSelect(int select)
{
    switch(select)
    {

        /* Вывод картин списка*/
        case 1: {
            cout << *gallery << endl;
            break;
        }

        /*Добавление элемента в начало списка*/
        case 2:{
            addToBegin();
            break;
        }

        /*Добавление элемента по индексу*/
        case 3:{
            int index = inputInt("Введите индекс будущей картины ");
            string title =  inputString("Введите название");
            string author = inputString("Введите автора");
            string school = inputString("Введите школу");
            double durability = inputDouble("Введите прочность");
            int status = inputInt("Введите статус");

            Painting* painting = new Painting {title, author, school, durability, status };

            gallery->add(index,painting);

            printBreakLine();
            cout << "Картина успещно создана и добавлена в галерею" << endl;
            break;
        }

        /* Добавление элемента в конец списка */
        case 4:{
            string title =  inputString("Введите название");
            string author = inputString("Введите автора");
            string school = inputString("Введите школу");
            double durability = inputDouble("Введите прочность");
            int status = inputInt("Введите статус");

            Painting* painting = new Painting {title, author, school, durability, status };
            if(status > 0) {
                repair->add(painting);
            } else {
                gallery->add(painting);
            }

            printBreakLine();
            cout << "Картина успещно создана и добавлена в галерею" << endl;
            break;
        }

        /* Замена элемента на передаваемый*/
        case 5:{
            int index = inputInt("Введите индекс картины для редактирования");
            Painting* painting = gallery->get(index);
            if(painting == NULL) {
                cout << "Картина с таким индексом не найдена" << endl;
                break;
            }
            cout << *painting << endl;
            printBreakLine();

            painting->title = inputString("Введите новое название");
            painting->author = inputString("Введите нового автора");
            painting->school = inputString("Введите новую школу");
            painting->durability = inputDouble("Введите новую прочность");
            painting->status = inputInt("Введите новый статус");

            printBreakLine();
            cout << "Картина успешно отредактирована" << endl;
            break;
        }

        /* Удаление картины по индексу */
        case 6:{
            gallery->remove(inputInt("Введите индекс картины для удаления"));
            cout << "Картина успещно удалена из галереи" << endl;
            break;
        }

        /* Удаление всех картин из галереи*/
        case 7:{
            gallery->clear();
            cout << "Галерея успешно очищена" << endl;
            break;
        }

        /* Вывод картины по индексу */
        case 8:{
            CustomList<Painting>* list = getIndexPainting(gallery, inputInt("Введите индекс картины: "));
            cout << *list << endl;
            list->clear(true);
            delete list;
            break;
        }

        /*Удаление первого элемента в списке*/
        case 9:{
            removeFirstElement();
            cout << "Картина успещно удалена из галереи" << endl;
            break;
        }

        /*Удаление последнего элемента в списке*/
        case 10: {
            removeLastElement();
            cout << "Картина успещно удалена из галереи" << endl;
            break;
        }

        /* Последнее вхождение списка */
        case 11:{
            lastOccurrenceListWithinList();
            break;
        }

        case 12: {
            save();
            cout << "Данные успешно сохранены на диск" << endl;
            break;
        }

        case 0: {
            cout << "Программа завершила свою работу" << endl;
            printBreakLine();
            system("pause");
            return true;
        }

        default: {
            cout << "Нет такого варианта ответа!" << endl;
            break;
        }
    }

    return false;
}

void addToBegin(){
    int index = 0;
    string title =  inputString("Введите название");
    string author = inputString("Введите автора");
    string school = inputString("Введите школу");
    double durability = inputDouble("Введите прочность");
    int status = inputInt("Введите статус");

    Painting* painting = new Painting {title, author, school, durability, status };

    gallery->add(index,painting);

    printBreakLine();
    cout << "Картина успещно создана и добавлена в галерею" << endl;
}

void removeLastElement(){
    gallery->remove(gallery->size-1);
}

void removeFirstElement(){
    gallery->remove(0);
}

void lastOccurrenceListWithinList(){
    int findElements = -1;
    int amountElements = 0;
    int countFindElements = inputInt("Введите колличество элементов: ");
    for ( int i = 0; i < countFindElements; i++) {
        string title = inputString("Введите название");
        string author = inputString("Введите автора");
        string school = inputString("Введите школу");
        double durability = inputDouble("Введите прочность");
        int status = inputInt("Введите статус");
        cout << "\n";

        Painting *painting = new Painting{title, author, school, durability, status};

        repair->add(painting);
    }

    for(int i = 0; i < gallery->size-repair->size; i++){
        for(int j = 0; j < repair->size; j++){

            Painting* paintingGallery = gallery->get(i);
            Painting* paintingRepair = repair->get(j);

            if((paintingGallery->title == paintingRepair->title) && (paintingGallery->author == paintingRepair->author) && (paintingGallery->school == paintingRepair->school) && (paintingGallery->durability == paintingRepair->durability) && (paintingGallery->status == paintingRepair->status)){
                amountElements = 1;
                Painting* paintingGalleryNext;
                Painting* paintingRepairNext;
                for(int k = 1; k < repair->size; k++){
                    paintingGalleryNext = gallery->get(i+k);
                    paintingRepairNext = repair->get(j+k);

                    if((paintingGalleryNext->title != paintingRepairNext->title) &&
                       (paintingGalleryNext->school != paintingRepairNext->school) &&
                       (paintingGalleryNext->author != paintingRepairNext->author) &&
                       (paintingGalleryNext->durability != paintingRepairNext->durability) &&
                       (paintingGalleryNext->status != paintingRepairNext->status)) {
                        break;
                    }
                    amountElements++;
                }
                if (amountElements == repair->size){
                    findElements = i;
                }
            }
            else{
                break;
            }
        }
    }
    if(findElements == -1){
        cout << "Вхождений не найдено!";
    }
    else{
        cout << "ID первого элемента последнего вхождения в список: " << findElements << endl;
    }
    repair->clear();
}

void load()
{
    gallery = listFromJsonString(fileInput(GALLERY_FILE));
    repair = listFromJsonString(fileInput(REPAIR_FILE));
}

void save()
{
    fileOutput(GALLERY_FILE, jsonStringFromList(gallery));
    fileOutput(REPAIR_FILE, jsonStringFromList(repair));
}
