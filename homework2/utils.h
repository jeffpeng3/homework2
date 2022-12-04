#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "node.h"
#include "compatiable.h"

extern const char* prompt;

int seleteOperation(char mode);

void printSpace(int count);

int getIntLen(int value);
