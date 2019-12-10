#pragma once
#include <stdio.h>

typedef enum datatype_t {
    DATA_CREATURE,
    DATA_ITEM
} DataType;

typedef struct creature_template_t {
    int str;
    int stam;
    int skl;
    int spd;
    int sag;
    int smt;
    char glyph;
    char name[20];
} CreatureTemplate;

typedef struct item_template_t {
    int atp;
    int dfp;
    int mat;
    int mdf;
    int vis;
    char glyph;
    char name[20];
} ItemTemplate;

int readData(const char* fileName, DataType dType);
int getCreatureData(FILE* f);
int getItemData(FILE* f);