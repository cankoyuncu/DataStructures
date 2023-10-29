#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ISIM_UZUNLUGU 50
#define MAX_SIZE 100

struct Ogrenci {
    int numara;
    char isim[MAX_ISIM_UZUNLUGU];
    int yas;
    struct Ogrenci *sonraki;
};

void sirala_liste() {
    int liste[MAX_SIZE];
    int index = 0;
    int sayi;

    while (1) {
        printf("Bir sayi girin (Cikis icin -1): ");
        scanf("%d", &sayi);

        if (sayi == -1) {
            break;
        }

        if (index < MAX_SIZE) {
            if (sayi % 2 == 0) {
                liste[index] = sayi;
                index++;
            } else {
                for (int i = index; i > 0; i--) {
                    liste[i] = liste[i - 1];
                }
                liste[0] = sayi;
                index++;
            }
        } else {
            printf("Liste dolu! Daha fazla eleman eklenemez.\n");
            break;
        }
    }

    printf("Siralanmis Liste: ");
    for (int i = 0; i < index; i++) {
        printf("%d ", liste[i]);
    }
    printf("\n");
}

void yazdirListe(int liste[], int uzunluk) {
    for (int i = 0; i < uzunluk; i++) {
        if (i != uzunluk - 1) {
            printf("%d -> ", liste[i]);
        } else {
            printf("%d\n", liste[i]);
        }
    }
}

void buyuktenKucugeSiralama(int liste[], int uzunluk) {
    for (int i = 0; i < uzunluk - 1; i++) {
        for (int j = i + 1; j < uzunluk; j++) {
            if (liste[i] < liste[j]) {
                int temp = liste[i];
                liste[i] = liste[j];
                liste[j] = temp;
            }
        }
    }
}

void listeyiDolas(struct Ogrenci *baslangic) {
    int index = 1;

    while (baslangic != NULL) {
        printf("%d- %s %d %d\n", index, baslangic->isim, baslangic->yas, baslangic->numara);
        baslangic = baslangic->sonraki;
        index++;
    }
}

struct Ogrenci *aramaIsmeGore(struct Ogrenci *baslangic, const char *arananIsim) {
    struct Ogrenci *gecici = baslangic;

    while (gecici != NULL) {
        if (strcmp(gecici->isim, arananIsim) == 0) {
            return gecici;
        }
        gecici = gecici->sonraki;
    }

    return NULL;
}

void sonrakiDugumuSil(struct Ogrenci *baslangic, const char *arananIsim) {
    struct Ogrenci *gecici = baslangic;
    struct Ogrenci *onceki = NULL;

    while (gecici != NULL && strcmp(gecici->isim, arananIsim) != 0) {
        onceki = gecici;
        gecici = gecici->sonraki;
    }

    if (gecici == NULL) {
        printf("Aranan isim bulunamadi.\n");
        return;
    }

    if (onceki == NULL) {
        baslangic = gecici->sonraki;
    } else {
        onceki->sonraki = gecici->sonraki;
    }

    free(gecici);
    printf("Aranan isimden sonraki dugum basariyla silindi.\n");
}

void enUzunIsmiYazdir(struct Ogrenci *baslangic) {
    if (baslangic == NULL) {
        printf("Liste bos, en uzun isim bulunamadi.\n");
        return;
    }

    struct Ogrenci *gecici = baslangic;
    int maxUzunluk = 0;
    char enUzunIsim[MAX_ISIM_UZUNLUGU];

    while (gecici != NULL) {
        int uzunluk = strlen(gecici->isim);
        if (uzunluk > maxUzunluk) {
            maxUzunluk = uzunluk;
            strcpy(enUzunIsim, gecici->isim);
        }
        gecici = gecici->sonraki;
    }

    if (maxUzunluk > 0) {
        printf("Listedeki en uzun isim: %s\nUzunluk: %d\n", enUzunIsim, maxUzunluk);
    } else {
        printf("Listede isim bulunamadi.\n");
    }
}

void menuYazdir() {
    printf("\n--- MENU ---\n");
    printf("1. Tek sayilari listenin basina, cift sayilari listenin sonuna ekle\n");
    printf("2. Rastgele listeyi buyukten kucuge sirala ve yazdir\n");
    printf("3. Ogrenci bilgilerini saklayip onlari uygun formatta yazdir\n");
    printf("4. Arama kaydi yapar\n");
    printf("5. Aranan ismin sonraki dugumunu sil\n");
    printf("6. En uzun ismi listele\n");
    printf("0. Cikis\n");
    printf("Seciminiz: ");
}

struct Ogrenci *listeOlustur() {
    struct Ogrenci *baslangic = NULL;
    struct Ogrenci *yeni;

    char devam;
    do {
        yeni = (struct Ogrenci *)malloc(sizeof(struct Ogrenci));
        if (yeni == NULL) {
            printf("Bellek tahsis edilemedi.");
            exit(1);
        }

        printf("Ogrenci numarasi: ");
        scanf("%d", &yeni->numara);
        
        printf("Ogrenci ismi: ");
        scanf("%s", yeni->isim);
        
        printf("Ogrenci yasi: ");
        scanf("%d", &yeni->yas);

        yeni->sonraki = baslangic;
        baslangic = yeni;

        printf("Baska ogrenci var mi? (E/H): ");
        scanf(" %c", &devam);
    } while (devam == 'E' || devam == 'e');

    return baslangic;
}

int main() {
    struct Ogrenci *baslangic = NULL;

    srand(time(0));

    int secim;
    do {
        menuYazdir();
        scanf("%d", &secim);

        switch (secim) {
            case 1:
                sirala_liste();
                break;
                
            case 2: {
                int liste[MAX_SIZE];
                for(int i = 0; i < MAX_SIZE; i++) {
                    liste[i] = rand() % 300;
                }

                buyuktenKucugeSiralama(liste, MAX_SIZE);

                printf("\nBuyukten kucuge siralanmis liste: ");
                yazdirListe(liste, MAX_SIZE);
                break;
            }
                
            case 3:
                listeyiDolas(baslangic);
                break;

            case 4:
                baslangic = listeOlustur();
                break;

            case 5: {
                char arananIsim[MAX_ISIM_UZUNLUGU];
                printf("Silinecek ismi girin: ");
                scanf("%s", arananIsim);
                sonrakiDugumuSil(baslangic, arananIsim);
                break;
            }

            case 6:
                enUzunIsmiYazdir(baslangic);
                break;

            case 0:
                printf("Programdan cikiliyor...\n");
                break;

            default:
                printf("Gecersiz secim, lutfen tekrar deneyin.\n");
        }
    } while (secim != 0);

    return 0;
}
