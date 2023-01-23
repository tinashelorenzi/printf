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
		return (-1);
	}

	va_start(list, format);
	for (index = 0; format[index] && format != '\0'; index++)
	{
		if (format[index] != '%')
		{
			buffer[buff_ind++] = format[index];
			if (buff_ind == BUFF_SIZE)
			{
				print_buff(buffer, &buff_ind);
				shown_char++;
			}
		}
	}
}

