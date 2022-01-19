/*
** EPITECH PROJECT, 2022
** Rush2
** File description:
** new
*/

#include "raise.h"
#include "new.h"
#include "object.h"
#include "player.h"
extern const Class  *Player;

Object *new(const Class *class, ...)
{
    Object *object = NULL;
    va_list args;

    va_start(args, class);
    object = va_new(class, &args);
    va_end(args);
    return (object);
}

Object *va_new(const Class *class, va_list *ap)
{
    Object *object = malloc(class->__size__);

    if (object == NULL)
        raise("Out of memory");
    memcpy(object, class, class->__size__);
    if (class->__ctor__ != NULL)
        class->__ctor__(object, ap);
    return (object);
}

void delete(Object *ptr)
{
    Class *name = ptr;

    if (name->__dtor__ != NULL)
        name->__dtor__(ptr);
    free(ptr);
}