/* UTF-8 before declarations: 日本語 */
#include <stddef.h>
#define EXTRA 2 \
    + 1

struct Point {
    int x;
    int y;
};

enum Direction { NORTH = 1, SOUTH, EAST, WEST, };
typedef unsigned long Size;

static int sum(const int *values, int count) {
    int result = 0;
    for (int i = 0; i < count; i++) {
        result += values[i];
    }
    return result;
}

int main(void) {
    int values[] = {1, 2, 3};
    struct Point origin = { .x = 0, .y = 0 };
    if (origin.x == 0 && origin.y == 0) {
        return sum(values, 3);
    } else {
        return -1;
    }
}
