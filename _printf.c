#include "main.h"

void print_buff(char buffer[], int *buff_ind);

/**
 * _printf - Revised printf function
 * @format: Format of object to be printed
 * Return: Number of printed chars
 */
int _printf(const char *format, ...)
{
	int index, shown = 0, shown_char = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;

	char buffer[BUFF_SIZE];
	if (format == NULL)
	{
		return(-1);
	}

	va_start(list, format);
	for (index = 0; format [index] && format != '\0'; index++)
	{
		if (format[index] != '%') /*Check if format is correct for char*/
		{
			buffer[buff_ind++] = format[index];
			if (buff_ind == BUFF_SIZE) /*Check buffer overflow*/
			{
				print_buff(buffer, &buff_ind);
				shown_char++;
			}
		}
		else
		{
			print_buff(buffer, &buff_ind);
			/*Functions to be created ahead!*/
			flags = get_flags(format, &index);
			width = get_width(format, &index, list);
			size = get_size(format, &index);
			precision = get_precision(format, &index, list);
			index ++;
			shown = handler(format, &index, list, buffer, flags, width, precision, size);
			if (shown == -1)
			{
				return(-1);
			}
			shown_char += shown;
		}
	}
	print_buff(buffer, &buff_ind);
	return (shown_char);
}
/**
 * print_buff - Prints stuff in a buffer size if there's any
 * @array: Array of chars into buff
 * @buff_ind: Index to add preceeding char AKA Length
*/
void print_buff(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0) /*Check the existance of the buffer*/
		write(1, &buffer[0], *buff_ind); /*Perform buffer write*/
	*buff_ind = 0;
}

