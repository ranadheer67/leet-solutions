#include <stdlib.h>

int numIslands(char** grid, int gridSize, int* gridColSize) {
    int rows = gridSize;
    int cols = gridColSize[0];
    int count = 0;

    int *stack = malloc(rows * cols * sizeof(int));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {

            if (grid[i][j] == '1') {
                count++;

                int top = -1;

                stack[++top] = i * cols + j;
                grid[i][j] = '0';

                while (top != -1) {
                    int pos = stack[top--];

                    int r = pos / cols;
                    int c = pos % cols;

                    if (r > 0 && grid[r-1][c] == '1') {
                        grid[r-1][c] = '0';
                        stack[++top] = (r-1) * cols + c;
                    }

                    if (r < rows-1 && grid[r+1][c] == '1') {
                        grid[r+1][c] = '0';
                        stack[++top] = (r+1) * cols + c;
                    }

                    if (c > 0 && grid[r][c-1] == '1') {
                        grid[r][c-1] = '0';
                        stack[++top] = r * cols + c-1;
                    }

                    if (c < cols-1 && grid[r][c+1] == '1') {
                        grid[r][c+1] = '0';
                        stack[++top] = r * cols + c+1;
                    }
                }
            }
        }
    }

    free(stack);
    return count;
}