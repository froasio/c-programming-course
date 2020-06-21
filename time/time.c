#include <stdio.h>
#include <time.h>

/*
struct tm

Miembro	Tipo	Significado
tm_sec	int		seconds after the minute	0-61*
tm_min	int		minutes after the hour	0-59
tm_hour	int		hours since midnight	0-23
tm_mday	int		day of the month	1-31
tm_mon	int		months since January	0-11
tm_year	int		years since 1900	
tm_wday	int		days since Sunday	0-6
tm_yday	int		days since January 1	0-365
tm_isdst int	daylight Saving Time flag	

*/

int main(void) {

	time_t t, tt;
	struct tm *st;
	char s[100];

	/*
		time(&t) 
	*/
	t = time(NULL);
	printf("Unix Time: %lu\n", t);

	st = localtime(&t);

	printf ( "Fecha: %s", asctime (st));
	printf ( "Fecha: %s", ctime (&t));

	strftime (s,80,"Ahora son las %I:%M%p.",st);
	puts(s);

	st->tm_sec += 30;
	tt = mktime(st);
	printf("Unix Time: %lu\n", tt);

	printf("Diff: %.1f \n", difftime(tt,t));

	return 0;
}
