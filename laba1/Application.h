#ifndef lab1_APPLICATION_H
#define lab1_APPLICATION_H

#include <Windows.h>

#include "util/Utils.h"
#include "painting/PaintingListUtil.h"

using namespace std;

void menu();
bool processSelect(int);

void load();
void save();

#endif //lab1_APPLICATION_H