#include <stdio.h>
#include <stdlib.h>
#include "convert_to_csv.h"
#include "read.csv.h"

void find_name(const char* csv_filenmae, const char* name);
void add_record(const char* csv_filename, const char* name, const int age, const char* city);
void delete_record(const char* csv_filename, const char* name);