//
// Created by QuantumDeity on 3/7/2025.
//

#include <stdio.h>
#include "file.h"
#include "prelude.h"

void read_file_buf(char *name,char buffer[],int buffer_size){
    FILE *fptr;
    fptr = fopen(name, "r");
    if(fptr==NULL){
        printf("%s%s\n","file not found: ",name);
        return;
    }
    fgets(buffer, buffer_size, fptr);
}

int get_file_size(FILE *file){
    int prev = ftell(file);
    fseek(file, 0L, SEEK_END);
    int sz = ftell(file);
    fseek(file,prev,SEEK_SET);
    return sz;
}