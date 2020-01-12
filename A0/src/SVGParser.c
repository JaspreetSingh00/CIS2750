/* Zainab Ghori */

#include "SVGParser.h"
#include "LinkedListAPI.h"
#include "Helper.h"

// SVGimage* createSVGimage(char* fileName)
// {
//     /* check if file exists */
//     if (fileName == NULL) {
//         return NULL;
//     }
//     return 0;
    // xmlDoc * img = NULL;
// }

// char* SVGimageToString(SVGimage* img)
// {
    // /* check if exists */
    // if (img == NULL) {
    //     return NULL;
    // }
    // return 0;
// }

/* deallocate object and its components */
void deleteSVGimage(SVGimage* img)
{
    if (img == NULL) {
        return;
    } 
    freeList(img->rectangles);
    freeList(img->circles);
    freeList(img->paths);
    freeList(img->groups);
    freeList(img->otherAttributes);
    /* free entire SVG struct */
    free(img);
}

/* ******************************* List helper functions  - MUST be implemented *************************** */

void deleteAttribute(void* data)
{
    Attribute* buffer = (Attribute*) data;
    /* free contents of struct */
    free(buffer->name);
    free(buffer->value);
    /* free entire attribute struct */
    free(buffer);
}
// char* attributeToString(void* data)
// {
//     Attribute* attributeToString = (Attribute*) data;
//     char* buffer = calloc(50, sizeof(char));
//     printf("Attributes: \n");
//     strcpy(buffer, "    name: ");
//     strcat(buffer, attributeToString->name);
//     strcat(buffer, "\n");
//     strcat(buffer, "    value: ");
//     strcat(buffer, attributeToString->value);
    
//     return buffer;
// }
int compareAttributes(const void *first, const void *second)
{
    int first_name = ((struct Attribute*) first)->name;
    int second_name = ((struct Attribute*) second)->name;
    int first_value = ((struct Attribute*) first)->value;
    int second_value = ((struct Attribute*) second)->value;

    return (strcmp(first_name, second_name) && strcmp(first_value, second_value))
}

void deleteGroup(void* data)
{
    Group* buffer = (Group*) data;
    /* free group attributes */
    freeList(buffer->rectangles);
    freeList(buffer->circles);
    freeList(buffer->paths);
    freeList(buffer->groups);
    freeList(buffer->otherAttributes);
    /* free entire group struct */
    free(buffer);
}
// char* groupToString(void* data);
/* comparing groups by name */
int compareGroups(const void *first, const void *second);

void deleteRectangle(void* data)
{
    Rectangle* buffer = (Rectangle*) data;
    /* free rectangle attributes */
    freeList(buffer->otherAttributes);
    /* free entire rectangle struct */
    free(buffer);
}
// char* rectangleToString(void* data);
// int compareRectangles(const void *first, const void *second);

void deleteCircle(void* data)
{
    Circle* buffer = (Circle*) data;
    freeList(buffer->otherAttributes);
    free(buffer);
}
// char* circleToString(void* data);
// int compareCircles(const void *first, const void *second);

void deletePath(void* data)
{
    Path* buffer = (Path*) data;
    free(buffer->data);
    freeList(buffer->otherAttributes);
    free(buffer);
}
// char* pathToString(void* data);
int comparePaths(const void *first, const void *second)
{
    int path_a = ((struct Attribute*) first)->data;
    int path_b = ((struct Attribute*) second)->data;

    return (strcmp(path_a, path_b))
}

/* resources: http://www.xmlsoft.org/html/index.html 
https://stackoverflow.com/questions/42566481/casting-void-pointers-in-c 
https://www.geeksforgeeks.org/comparator-function-of-qsort-in-c/ */

// assume 1 namespace 
