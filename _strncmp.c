/**
 * _strncmp - compares two strings
 * @s1: the first string
 * @s2: the second string
 * @n: the number of bytes to be copied
 *
 * Return: an integer (equals, less than or greater than zero)
 */

int _strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n && (s1[i] != '\0') && (s2[i] != '\0'); i++)
	{
		if (s1[i] - s2[i] != 0)
		{
			break;
		}
	}
	return (s1[i] - s2[i]);
}
