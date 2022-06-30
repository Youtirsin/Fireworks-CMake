#pragma once

#include <iostream>

inline int rand(int start, int end) { return (rand() % (end - start)) + start; }
