#include "mystrch.h"

void* malloc_s(size_t memory_size) {
	void* ret = malloc(memory_size);
	if (ret == NULL) {
	    fprintf(stderr,"malloc error!\n");
		exit(-17001);
	}
	return ret;
}

void* realloc_s(void* ptr, size_t memory_size) {
	void* ret = realloc(ptr, memory_size);
	if (ret == NULL) {
		fprintf(stderr,"realloc error!\n");
		exit(-17002);
	}
	return ret;
}

void fclose_s(FILE* filestream) {
    if (fclose(filestream) == EOF) {
        fprintf(stderr,"fclose error!\n");
        exit(-17003);
    }
}

char* read_char_str(FILE* filestream, int array_increment_step) {
	int array_size = array_increment_step;
	char* str = (char*)malloc_s(array_size);
	int asz = 0, c;
	*str = 0;
	while (1) {
		c = fgetc(filestream);
		if ((c == '\n') || (c == EOF)) {
		    return str;
		}
		str[asz++] = c;
		if (asz >= array_size) {
			array_size += array_increment_step;
			str = (char*)realloc_s(str, array_size);
		}
		str[asz] = 0;
	}
}

int check_brackets(char* msg) {
    int i = 0, brk_count = 0;
    while (msg[i] != '\0') {
        switch (msg[i]) {
            case '{': case '}': case '[': case ']': case '(': case ')': {
                brk_count++;
                break;
            }
            default: break;
        }
        i++;
    }
    if (brk_count == 0) {
        return 1;
    }
    else {
        if (brk_count % 2 != 0) {
            return 0;
        }
        else {
            int k = 0, array_size = 1, msg_size = strlen(msg) + 1;
            i = 0;
            char* mass = (char*)malloc_s(array_size*sizeof(char));
            while (k != msg_size) {
                if ((msg[k] == '[') || (msg[k] == '(') || (msg[k] == '{')) {
                    mass[i] = msg[k];
                    i++;
                    if (array_size == i) {
                        array_size = i + 1;
                        mass = (char*)realloc_s(mass, array_size*sizeof(char));
                    }
                }
                else if (((msg[k] == ']') && (mass[i-1] == '[')) || ((msg[k] == '}') && (mass[i-1] == '{')) || ((msg[k] == ')') && (mass[i-1] == '('))) {
                    i--;
                }
				k++;
            }
            free(mass);
            if (i == 0) {
                return 1;
            }
            else {
                return 0;
            }
        }
    }
}

int str_compare(char* p1, char* p2, int mode) {
	char* s;
	double d;
	long l;
	switch (mode) {
	    case 0: {
		    return strcmp(p1, p2);
		}
		case 1:
		{
		    d = strtod(p1, &s);
      		if (*s) {
			    fprintf(stderr,"str_compare error.\nstrtod error in first string: %s\n", p1);
				exit(-17004);
		    }
		  	d -= strtod(p2, &s);
		  	if (*s) {
			    fprintf(stderr,"str_compare error.\nstrtod error in second string: %s\n", p2);
				exit(-17005);
		    }
		  	if (d > 0) {
 	   		    return 1;
		    }
		  	else if (d < 0) {
  	 		    return -1;
		    }
		  	else {
 	   		    return 0;
		    }
		}
		case 2: {
		    l = strtol(p1, &s, 10);
  			if (*s) {
			    fprintf(stderr,"str_compare error.\nstrtol error in first string: %s\n", p1);
				exit(-17006);
		    }
		   	l -= strtol(p2, &s, 10);
		  	if (*s) {
			    fprintf(stderr,"str_compare error.\nstrtol error in second string: %s\n", p2);
				exit(-17007);
		    }
		  	if (l > 0) {
   			    return 1;
		    }
		   	else if (l < 0) {
	   		    return -1;
		    }
		   	else {
			    return 0;
		    }
		}
		default: {
		    fprintf(stderr,"mode error in str_compare\n");
			exit(-17008);
		}
	}
}

FILE* fopen_s(const char* file_name, const char* open_mode) {
    FILE* ret = fopen(file_name, open_mode);
    if (ret == NULL) {
        fprintf(stderr,"fopen error!\n");
        exit(-17009);
    }
    return ret;
}

void flags_set_true(FLAGS* p1) {
    p1->f0 = 1;
    p1->f1 = 1;
    p1->f2 = 1;
    p1->f3 = 1;
    p1->f4 = 1;
    p1->f5 = 1;
    p1->f6 = 1;
    p1->f7 = 1;
}

void flags_set_false(FLAGS* p1) {
    p1->f0 = 0;
    p1->f1 = 0;
    p1->f2 = 0;
    p1->f3 = 0;
    p1->f4 = 0;
    p1->f5 = 0;
    p1->f6 = 0;
    p1->f7 = 0;
}
