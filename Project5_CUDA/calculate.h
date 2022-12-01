#pragma once

#include <windows.h>
#include "matrix.h"

void DotProductByCPU(Matrix *input_1, Matrix *input_2, Matrix *output);

void DotProductByGPU(Matrix *input_1, Matrix *input_2, Matrix *output);
