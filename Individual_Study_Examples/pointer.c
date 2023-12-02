#include <stdio.h>
#include <stdlib.h>

int main() {
	int agirlik = 10;
	int *p;
	p = &agirlik;
	
	printf("%d\n", agirlik); // agirlik degiskeninin verisini yaz, 10 yazilir
	printf("%p\n", &agirlik); // agirlik degiskeninin adresini yaz, ramdeki adres yazilir
	printf("%p\n", p); // p degiskeninin verisini yaz, ramdeki adres yazilir
	printf("%d\n", *p); // p degiskeninin adresindeki veriyi yaz, 10 yazilir
	printf("%p\n", &p); // p degiskenindeki adresi yaz, ramdeki adres yazilir
return 0;
}
