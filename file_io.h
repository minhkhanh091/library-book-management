#ifndef FILEIO_H
#define FILEIO_H

#include "book.h"

void input_source(int choice, int need_maintain_order, List &list);

void read_from_file(List &list, const char *file_name);
void read_from_keyboard(List &list, int need_maintain_order, int insert_pos);

#endif