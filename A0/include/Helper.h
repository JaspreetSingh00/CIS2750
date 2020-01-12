#ifdef HELPER_H
#define HELPER_H

#include <stdio.h>
#include <stdlib.h>
#include <libxml/parser.h>
#include <libxml/tree.h>
#include "SVGParser.h"
#include "LinkedListAPI.h"

//create svg function
SVGimage * new_svgimage();
char * new_str();
void free_str(char * toFree);
#endif 