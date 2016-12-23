#include <stdio.h>

void mydelay(int delay) {
	float i;
	while (delay--) {
		for (i = 0; i < 1000000;)
			i += 0.1;
	}
}

int main() {
	char buf;
        FILE *f;
        int count = 0;
	long pg_size = 4096;
	int delay = 0;

        f = fopen("foo", "r");
        if (f == NULL)
                printf("Got Null\n");
        while (count++ <= 10000000) {
		mydelay(delay);
                buf= getc(f);
//                printf("%c\n", buf);
                fseek(f, 1*pg_size-1, SEEK_CUR);
        }
	fclose(f);
        return 0;
}
