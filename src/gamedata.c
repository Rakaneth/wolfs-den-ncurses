#include "gamedata.h"
#include <string.h>

static CreatureTemplate C_TEMPLATES[100];
static ItemTemplate I_TEMPLATES[100];

int readData(const char* fileName, DataType dType) {
    FILE* datafile = fopen(fileName, "r");
    int result;

    if (datafile == NULL)
        return 0;
    switch (dType) {
        case DATA_CREATURE:
            result = getCreatureData(datafile);
            break;
        case DATA_ITEM:
            result = getItemData(datafile);
            break;
    }

    fclose(datafile);
    return result;
}

int getCreatureData(FILE* f) {
    CreatureTemplate cur;
    int i = 0;
    char buf[50] = {0};
    char stat[10] = {0};
    int value = 0;
    char glyph = 0;
    char name[20] = {0};
    int statCheck = 0;
    int nameCheck = 0;

    cur.str = 10;
    cur.stam = 10;
    cur.spd = 10;
    cur.skl = 10;
    cur.sag = 10;
    cur.smt = 10;
    strcpy(cur.name, "No name");
    cur.glyph = '\0';

    while (fgets(buf, 50, f) != NULL) {
        statCheck = sscanf(buf, "%[^: ]: %d", stat, &value);
        nameCheck = sscanf(buf, "{%[^}:]: %c}", name, &glyph);

        if (nameCheck) {
            strcpy(cur.name, name);
            cur.glyph = glyph;
        } else if (statCheck == 2) {
            if (strcmp(stat, "STR") == 0)
                cur.str = value;
            if (strcmp(stat, "STAM") == 0)
                cur.stam = value;
            if (strcmp(stat, "SPD") == 0)
                cur.spd = value;
            if (strcmp(stat, "SKL") == 0)
                cur.skl = value;
            if (strcmp(stat, "SAG") == 0)
                cur.sag = value;
            if (strcmp(stat, "SMT") == 0)
                cur.smt = value;
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
            i++;
        }
    }

    C_TEMPLATES[i] = cur;

    return 1;
}

int getItemData(FILE* f) { return 1; }