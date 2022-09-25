cmake_minimum_required(VERSION 3.21)
project(Laba1)

set(CMAKE_CXX_STANDARD 20)

add_executable(laba1 Application.cpp Application.h util/Utils.cpp util/Utils.h painting/Painting.cpp list/CustomList.h list/CustomListItem.h painting/Painting.h painting/PaintingJsonUtil.cpp painting/PaintingJsonUtil.h painting/PaintingListUtil.cpp painting/PaintingListUtil.h)
