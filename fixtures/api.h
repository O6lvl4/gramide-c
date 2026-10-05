#ifndef EXAMPLE_API_H
#define EXAMPLE_API_H
struct Reader { const char *name; int offset; };
int read_value(struct Reader *reader, const char *text);
unsigned long measure(const char *text);
int first(int x), second(int y);
int third(void), count;
#endif
