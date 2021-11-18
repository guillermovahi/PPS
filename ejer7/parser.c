#include "parser.h"
int num_chars(char *first_line, int pos);
int num_words(char *first_line);
char **string_to_array2D(char *line, int n_fields);
void	add_format(char **field_names, char *element, int n_fields);

int		parser(FILE *file)
{
	char first_line[MaxLinea+1];
	char rest_lines[MaxLinea+1];
	char **field_names;
	char **field_names_aux;
	char **line_examples;
	int n_fields; 
	int i;
	
	fgets(first_line, MaxLinea, file);
	n_fields = num_words(first_line);

	if(n_fields > MaxFields)
	{
		fprintf(stderr, "Muchos campos\n");
		return 1;
	}

	field_names = string_to_array2D(first_line, n_fields);
	field_names_aux = string_to_array2D(first_line, n_fields);

	//while()
	printf("%s\n", field_names[0]);
	printf("%s\n", field_names[1]);
	printf("%s\n", field_names[2]);
	printf("%s\n", field_names[3]);
	printf("%s\n", field_names[4]);
	printf("%s\n", field_names[5]);
	add_format(field_names, ": ", n_fields);
	//printf("NUMERO CAMPOS: %d\n", n_fields);
	printf("%s\n", field_names[0]);
	printf("%s\n", field_names[1]);
	printf("%s\n", field_names[2]);
	printf("%s\n", field_names[3]);
	printf("%s\n", field_names[4]);
	printf("%s\n", field_names[5]);

	//add_format(field_names_aux, ": ", n_fields);
	field_names_aux = field_names;
	// i = 0;
	// while(feof(file) == 0)
	// {
		printf("-----------------------------\n");
		fgets(rest_lines, MaxLinea, file);
		field_names = field_names_aux;
		line_examples = string_to_array2D(rest_lines, n_fields);
		add_format(line_examples, "; ", n_fields);
		i = 0;
		while(i < n_fields)
		{
			strcat(field_names[i], line_examples[i]);
			i++;
		}
		
		printf("%s\n", field_names[0]);
		printf("%s\n", field_names[1]);
		printf("%s\n", field_names[2]);
		printf("%s\n", field_names[3]);
		printf("%s\n", field_names[4]);
		printf("%s\n", field_names[5]);

	// 	i++;
	// }
	
	


	fclose(file);

	return 0;

}
void	add_format(char **field_names, char *element, int n_fields)
{
	int i = -1;
	if (strcmp(element, "; ") == 0)
		n_fields--;
	while(++i < n_fields)
		strcat(field_names[i], element);
}
char **string_to_array2D(char *line, int n_fields)
{
	int n_chars;
	int i, j, k, fields;
	char **array_res;
	i = 0;
	j = 0;
	fields = 0;
	array_res = (char **) malloc((n_fields + 1) * sizeof(char *));
	while(fields < n_fields)
	{
		n_chars = num_chars(line, i);
		array_res[j] = (char *) malloc((n_chars + 1) * sizeof(char));
		k = 0;
		while(k < n_chars)
			array_res[j][k++] = line[i++];
		array_res[j][k] = 0;
		j++;
		i++;
		fields++;
	}
	array_res[j]= 0;

	return array_res;
}

int num_words(char *first_line)
{
	int commas = 1;
	int i = 0;
	while(first_line[i])
	{
		if(first_line[i] == ',')
			commas++;
		i++;	
	}
	return commas;
}

int num_chars(char *first_line, int pos)
{
	int aux = pos;
	while(first_line[pos] != ',' && first_line[pos] != '\n' && first_line[pos])
		pos++;
	return (pos - aux);
}

