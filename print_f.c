#include "main.h"

int _printf(const char *format, ...)
{
    int n = 0;
    char c;
    char* string;
    int string_len = 0;

    va_list name_list;

    if (format == NULL)
    {
        return (-1);
    }
    va_start(name_list, format);

    while(*format)
    {
        if (*format == '%')
        {
            format++;
            if (*format == 'c')
            {
                c = va_arg (name_list, int);
                write (1, &c, 1);
                n++;
                format++;
            }
            else if (*format == 's')
            {
                string = va_arg(name_list, char*);

                while (string[string_len] != '\n')
                    string_len++;

                write(1, string, string_len);
                n+= string_len;
                format++;
            }
            else if (*format == '%')
            {
                write(1, format, 1);
                n++;
                format++;
            }
            else if (*format == '\0')
                break;
        }
        else 
        {
            write(1, format, 1);
            n++;
            format++;
        }
    }
    format++;
    va_end(name_list);

    return n;
}