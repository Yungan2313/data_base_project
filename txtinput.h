#ifndef TXT_INPUT_H
#define TXT_INPUT_H
#include "linked_list.h"
#include "basic.h"
struct linked_list *data_base_read(char txt[]);
struct acpd_list *acpd_read(char txt[]);
struct comment_list *comment_list_read(char txt[]);
#endif