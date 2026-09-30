#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

# define KNRM  "\x1B[0m"
# define KRED  "\x1B[31m"

//prototype:
int switch_case(char *src, char *dest);

int	test_function(char *src)
{
	char	*dest = NULL;
	int		len;
	int		n = -1;
	
	len = strlen(src);
	dest = calloc(len + 1, sizeof(char));
	if (!dest)
		return (1);

	n = switch_case(src, dest);
	if (n != len)
		printf(KRED "Return value: KO" KNRM "\n");

	free(dest);
	return (0);
}

int	main()
{
	FILE	*stream;
	size_t	size = 0;
	char	*line = NULL;

	stream = fopen("input.txt", "r");
	if (stream == NULL)
	{
		perror("[MAIN] Could not open file.");
		return (1);
	}
	
	ssize_t	nread;
	while (((nread = getline(&line, &size, stream)) != -1))
	{
		test_function(line);
	}
	free(line);
	fclose(stream);
	return (0);
}