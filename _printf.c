#include "main.h"

void print_buff(char buffer[], int *buff_ind);
/**
 * print_buff - Prints stuff in a buffer, if there's anything
 * @buffer: Array of chars to print
 * @buff_ind: Index to add preceeding chars, precisely the length
 */
void print_buff(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}


/**
 * _printf - Revised printf function
 * @format: format of objects to print
 * Return: Number of chars printed
 */
int _printf(const char *format, ...)
{
	int i, shown = 0, shown_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
	{
		return (-1);
	}

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		/* Task 0 */
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buff(buffer, &buff_ind);
			shown_chars++;
		}
/*
*		else
*		{
*			print_buff(buffer, &buff_ind);
*			flags = get_flags(format, &i);
*			width = get_width(format, &i, list);
*			precision = get_precision(format, &i, list);
*			size = get_size(format, &i);
*			++i;
*			shown = handle_print(format, &i, list, buffer,
*				flags, width, precision, size);
*			if (shown == -1)
*				return (-1);
*			shown_chars += shown;
*		}
*/
	}

/*	print_buff(buffer, &buff_ind);*/

	va_end(list);

	return (shown_chars);
}
