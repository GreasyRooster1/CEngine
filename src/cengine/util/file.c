//
// Created by QuantumDeity on 3/7/2025.
//

#include <stdio.h>
#include "file.h"
#include "prelude.h"

void read_file(char *name,char buffer[],int buffer_size){
    FILE *fptr;
    fptr = fopen(name, "r");
    fgets(buffer, buffer_size, fptr);
}