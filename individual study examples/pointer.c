#include <stdio.h>
#include <stdlib.h>

int main() {
	int agirlik = 10;
	int *p;
	p = &agirlik;
	
	printf("%d\n", agirlik); // agirlik de�i�keninin verisini yaz, 10 yaz�l�r
	printf("%p\n", &agirlik); // agirlik de�i�keninin adresini yaz, 0022FF44 yaz�l�r
	printf("%p\n", p); // p de�i�keninin verisini yaz, 0022FF44 yaz�l�r
	printf("%d\n", *p); // p de�i�kenindeki adresteki veriyi yaz, 10 yaz�l�r
	printf("%p\n", &p); // p de�i�keninin adresini yaz, 0022FF40 yaz�l�r
return 0;
}
