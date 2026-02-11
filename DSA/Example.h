#ifndef EXAMPLE_H
#define EXAMPLE_H
#pragma once

typedef int (*ExampleFunc)(void);

typedef struct 
{
    const int index;
    ExampleFunc run;
} ExampleEntry;

#endif