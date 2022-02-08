/*
** EPITECH PROJECT, 2022
** malloc
** File description:
** main
*/

#include <dlfcn.h>

int main(void)
{
    void *lib = dlopen("./libbasic.so", RTLD_LAZY);
    if (!lib) {
        write(2, "Error: dlopen failure\n", 22);
        return (84);
    }
    void (*my_putstr)(char *);

    *(void **) (&my_putstr) = dlsym(lib, "my_putstr");
    (*my_putstr)("Hello World!!!!\n");
    dlclose(lib);
}