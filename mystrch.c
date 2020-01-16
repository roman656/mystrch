#include "mystrch.h"

void* malloc_s(size_t memory_size) 
{
	void* ret = malloc(memory_size);
	if (ret == NULL) 
	{
	    fprintf(stderr,"malloc error!\n");
		exit(-17001);
	}
	return ret;
}

void* realloc_s(void* ptr, size_t memory_size)
{
	void* ret = realloc(ptr, memory_size);
	if (ret == NULL) 
	{
		fprintf(stderr,"realloc error!\n");
		exit(-17002);
	}
	return ret;
}

void fclose_s(FILE* filestream) 
{
    if (fclose(filestream) == EOF) 
	{
        fprintf(stderr,"fclose error!\n");
        exit(-17003);
    }
}

char* read_char_str(FILE* filestream, int array_increment_step) 
{
	int asz = 0;
	int c;
	int array_size = array_increment_step;
	char* str = (char*)malloc_s(array_size);
	*str = 0;
	while (1)
	{
		c = fgetc(filestream);
		if ((c == '\n') || (c == EOF) || (c == '\0'))
		{
		    return str;
		}
		str[asz++] = c;
		if (asz >= array_size) 
		{
			array_size += array_increment_step;
			str = (char*)realloc_s(str, array_size);
		}
		str[asz] = 0;
	}
}

int check_brackets(char* message)
{
    int i = 0;
	int brackets_count = 0;
    while (message[i] != '\0')
	{
        switch (message[i]) 
		{
            case '{': 
			case '}': 
			case '[': 
			case ']':
			case '(': 
			case ')': 
			{
                brackets_count++;
                break;
            }
            default: break;
        }
        i++;
    }
    if (brackets_count == 0) 
	{
        return 0;
    }
    else
	{
        if (brackets_count % 2 != 0) 
		{
            return 1;
        }
        else 
		{
			i = 0;
			int k = 0;
			int message_size = strlen(message) + 1;
			int brackets_array_size = 1;
            char* brackets_array = (char*)malloc_s(brackets_array_size * sizeof(char));
            while (k != message_size)
			{
                if ((message[k] == '[') || (message[k] == '(') || (message[k] == '{')) 
				{
                    brackets_array[i] = message[k];
                    i++;
                    if (brackets_array_size == i)
					{
                        brackets_array_size = i + 1;
                        brackets_array = (char*)realloc_s(brackets_array, brackets_array_size * sizeof(char));
                    }
                }
                else if (((message[k] == ']') && (brackets_array[i-1] == '[')) || ((message[k] == '}') && (brackets_array[i-1] == '{')) || ((message[k] == ')') && (brackets_array[i-1] == '(')))
				{
                    i--;
                }
				k++;
            }
            free(brackets_array);
            if (i == 0) 
			{
                return 0;
            }
            else
			{
                return 1;
            }
        }
    }
}

int str_compare(char* p1, char* p2, int mode) 
{
	char* s;
	double d;
	long l;
	switch (mode)
	{
	    case 0: 
		{
		    return strcmp(p1, p2);
		}
		case 1:
		{
		    d = strtod(p1, &s);
      		if (*s) 
			{
			    fprintf(stderr,"str_compare error.\nstrtod error in first string: %s\n", p1);
				exit(-17004);
		    }
		  	d -= strtod(p2, &s);
		  	if (*s) 
			{
			    fprintf(stderr,"str_compare error.\nstrtod error in second string: %s\n", p2);
				exit(-17005);
		    }
		  	if (d > 0) 
			{
 	   		    return 1;
		    }
		  	else if (d < 0)
			{
  	 		    return -1;
		    }
		  	else 
			{
 	   		    return 0;
		    }
		}
		case 2: 
		{
		    l = strtol(p1, &s, 10);
  			if (*s) 
			{
			    fprintf(stderr,"str_compare error.\nstrtol error in first string: %s\n", p1);
				exit(-17006);
		    }
		   	l -= strtol(p2, &s, 10);
		  	if (*s) 
			{
			    fprintf(stderr,"str_compare error.\nstrtol error in second string: %s\n", p2);
				exit(-17007);
		    }
		  	if (l > 0) 
			{
   			    return 1;
		    }
		   	else if (l < 0)
			{
	   		    return -1;
		    }
		   	else 
			{
			    return 0;
		    }
		}
		default:
		{
		    fprintf(stderr,"mode error in str_compare\n");
			exit(-17008);
		}
	}
}

FILE* fopen_s(const char* file_name, const char* open_mode)
{
    FILE* ret = fopen(file_name, open_mode);
    if (ret == NULL) 
	{
        fprintf(stderr,"fopen error!\n");
        exit(-17009);
    }
    return ret;
}

void flags_set_true(FLAGS* p1) 
{
    p1->f0 = 1;
    p1->f1 = 1;
    p1->f2 = 1;
    p1->f3 = 1;
    p1->f4 = 1;
    p1->f5 = 1;
    p1->f6 = 1;
    p1->f7 = 1;
}

void flags_set_false(FLAGS* p1)
{
    p1->f0 = 0;
    p1->f1 = 0;
    p1->f2 = 0;
    p1->f3 = 0;
    p1->f4 = 0;
    p1->f5 = 0;
    p1->f6 = 0;
    p1->f7 = 0;
}

void fread_s(void* memptr, int size, int count, FILE* fileptr) 
{
	if (fread(memptr, size, count, fileptr) != count)
	{
		fprintf(stderr,"fread error!\n");
        exit(-17010);
	}
}

void fwrite_s(void* memptr, int size, int count, FILE* fileptr)
{
	if (fwrite(memptr, size, count, fileptr) != count)
	{
		fprintf(stderr,"fwrite error!\n");
        exit(-17011);
	}
}
