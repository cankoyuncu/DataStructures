#include <stdio.h>
#include <stdlib.h>

int main() {
	int agirlik = 10;
	int *p;
	p = &agirlik;
	
	printf("%d\n", agirlik); // agirlik deðiþkeninin verisini yaz, 10 yazýlýr
	printf("%p\n", &agirlik); // agirlik deðiþkeninin adresini yaz, 0022FF44 yazýlýr
	printf("%p\n", p); // p deðiþkeninin verisini yaz, 0022FF44 yazýlýr
	printf("%d\n", *p); // p deðiþkenindeki adresteki veriyi yaz, 10 yazýlýr
	printf("%p\n", &p); // p deðiþkeninin adresini yaz, 0022FF40 yazýlýr
return 0;
}
