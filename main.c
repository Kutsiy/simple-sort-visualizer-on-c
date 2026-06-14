#include <stdio.h>
#include <stdlib.h>

#include "raylib.h"
#include "win_utils.h"



void createArray(int* array, int size)
{
    for (int i = 0; i < size; i++)
    {
        array[i] = GetRandomValue(10, 400);
    }
}

void drawAllRects(int* array, int size, int gap, int screenHeight, int hindex) {
     for (int i = 0; i < size; i++)
    {
            if (i == hindex) {
                DrawRectangle(i * gap + 50, screenHeight - array[i], 10, array[i], RED);
            }
            else
            {
                DrawRectangle(i * gap + 50, screenHeight - array[i], 10, array[i], WHITE);
            }
    }
}


int main(void)
{
    int size = 40;
    int gap = 14;
    int* array = malloc(size * sizeof(int));
    createArray(array, size);
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "sort visualizer");

    int i = 0;
    int j = 0;
    int done = 0;

    SetTargetFPS(60);    
    while (!WindowShouldClose())
    {
        if (i < size - 1 && !done) {
            if (array[j] > array[j + 1])
        {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;

        }
        if(j < size - i - 2)
        {
            j++;
        }
        else
        {
            j = 0;
            i++;
        }
        } else {
            done = 1;
            i = -1;
            j = -1;
        }


        BeginDrawing();
        ClearBackground(BLACK);
        drawAllRects(array, size, gap, screenHeight, j);
        EndDrawing();
    }

    CloseWindow();     
    
    free(array);
    return 0;
}