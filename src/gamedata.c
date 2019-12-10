#include "gamedata.h"
#include <string.h>

static CreatureTemplate C_TEMPLATES[100];
static ItemTemplate I_TEMPLATES[100];

int readData(const char* fileName, DataType dType) {
    FILE* datafile = fopen(fileName, "r");
    int result;
    
    if (datafile == NULL) return 0;
    switch(dType) {
        case DATA_CREATURE:
            result = getCreatureData(datafile);
            break;
        case DATA_ITEM:
            result = getItemData(datafile);
            break;
    }

    fclose(fileName);
    return result;
}

int getCreatureData(FILE* f) {
    CreatureTemplate cur;
    int i = 0;
    char buf[50];
    char stat[5];
    int value;
    char glyph;
    char name[20];
    int statCheck;
    int charCheck;
    int nameCheck;
    
    cur.str = 10;
    cur.stam = 10;
    cur.spd = 10;
    cur.skl = 10;
    cur.sag = 10;
    cur.smt = 10;
    strcpy(cur.name, "No name");
    cur.glyph = '\0';

    while(fgets(buf, 50, f) != NULL) {
        statCheck = sscanf(buf, "%[^: ]s%*[: ]%d", stat, &value);
        charCheck = sscanf(buf, "%[^: ]s%*[: ]%c", stat, &glyph);
        nameCheck = sscanf(buf, "%[^: ]s%*[: ]%s", stat, name);

        if (nameCheck == 2 && strcmp(stat, "NAME") == 0) {
            strcpy(cur.name, name);
        } else if (charCheck == 2 && strcmp(stat, "GLYPH") == 0) {
            cur.glyph = glyph;
        } else if (statCheck == 2) {
            if (strcmp(stat, "STR") == 0) cur.str = value;
            if (strcmp(stat, "STAM") == 0) cur.stam = value;
            if (strcmp(stat, "SPD") == 0) cur.spd = value;
            if (strcmp(stat, "SKL") == 0) cur.skl = value;
            if (strcmp(stat, "SAG") == 0) cur.sag = value;
            if (strcmp(stat, "SMT") == 0) cur.smt = value;
        } else {
            C_TEMPLATES[i] = cur;
            cur.str = 10;
            cur.stam = 10;
            cur.spd = 10;
            cur.skl = 10;
            cur.sag = 10;
            cur.smt = 10;
            strcpy(cur.name, "No name");
            cur.glyph = '\0';
        }

        i++;
    }

    return 1;
}

int getItemData(FILE* f) {
    return 1;
}