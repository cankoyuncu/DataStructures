#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct hasta {
    char ad[100];
    char soyad[100];
    int oncelik;
} hasta;

hasta* hasta_olustur(char* ad, char* soyad, int oncelik) {
    hasta* h = malloc(sizeof(hasta));
    strcpy(h->ad, ad);
    strcpy(h->soyad, soyad);
    h->oncelik = oncelik;
    return h;
}

typedef struct siraEleman {
    hasta* veri;
    struct siraEleman* sonraki; 
} siraEleman;

siraEleman* siraEleman_yarat(hasta* yeni) {
    siraEleman* se = malloc(sizeof(siraEleman));
    se->veri = yeni;
    return se;
}

typedef struct sira {
    siraEleman* ilk;
} sira;

sira* sira_yarat() {
    sira* s = malloc(sizeof(sira));
    s->ilk = NULL;
    printf("sira olustu\n");
    return s;
}

void sira_ekle(sira* s, hasta* yeniHasta) {
    if (s->ilk == NULL) {
        printf("ilk bos\n");
        s->ilk = malloc(sizeof(siraEleman));
        s->ilk->veri = yeniHasta;
        s->ilk->sonraki = s->ilk;
    } else if (s->ilk->veri->oncelik > yeniHasta->

void sira_ekle(sira* s, hasta* yeniHasta) {
    if (s->ilk == NULL) {
        printf("ilk bos\n");
        s->ilk = malloc(sizeof(siraEleman));
        s->ilk->veri = yeniHasta;
        s->ilk->sonraki = s->ilk;
    } else if (s->ilk->veri->oncelik < yeniHasta->oncelik) {
        printf("basa ekle\n");
        siraEleman* iter = s->ilk;
        while (iter->sonraki != s->ilk)
            iter = iter->sonraki;
        printf("%s sonrasina ekliyorum\n", iter->veri->ad);
        siraEleman* yeni = malloc(sizeof(siraEleman));
        yeni->veri = yeniHasta;
        iter->sonraki = yeni;
        yeni->sonraki = s->ilk;
        s->ilk = yeni;
        printf("yeni ilk %s\n", s->ilk->veri->ad);
    } else {
        siraEleman* iter = s->ilk;
        siraEleman* gecici;
        while (iter->sonraki != s->ilk && iter->sonraki->veri->oncelik > yeniHasta->oncelik) {
            printf("onceligim : %d baktigim: %d\n", yeniHasta->oncelik, iter->veri->oncelik);
            iter = iter->sonraki;
        }    
        if (iter != s->ilk && iter->veri->oncelik < yeniHasta->oncelik)
            iter = iter->sonraki;
        gecici = iter->sonraki;
        iter->sonraki = malloc(sizeof(siraEleman));
        iter->sonraki->veri = yeniHasta;
        iter->sonraki->sonraki = gecici;
    }
    printf("eklendi\n");
}

hasta* siradaki(sira* s) {
    if (s->ilk == NULL)
        return NULL;
    else if (s->ilk->sonraki == s->ilk)
};

void sira_ekle(sira* s, hasta* yeniHasta) {
    if (s->ilk == NULL) {
        printf("ilk bos\n");
        s->ilk = malloc(sizeof(siraEleman));
        s->ilk->veri = yeniHasta;
        s->ilk->sonraki = s->ilk;
    } else if (s->ilk->veri->oncelik < yeniHasta->oncelik) {
        printf("basa ekle\n");
        siraEleman* iter = s->ilk;
        while (iter->sonraki != s->ilk)
            iter = iter->sonraki;
        printf("%s sonrasina ekliyorum\n", iter->veri->ad);
        siraEleman* yeni = malloc(sizeof(siraEleman));
        yeni->veri = yeniHasta;
        iter->sonraki = yeni;
        yeni->sonraki = s->ilk;
        s->ilk = yeni;
        printf("yeni ilk %s\n", s->ilk->veri->ad);
    } else {
        siraEleman* iter = s->ilk;
        siraEleman* gecici;
        while (iter->sonraki != s->ilk && iter->sonraki->veri->oncelik > yeniHasta->oncelik) {
            printf("onceligim : %d baktigim: %d\n", yeniHasta->oncelik, iter->veri->oncelik);
            iter = iter->sonraki;
        }    
        if (iter != s->ilk && iter->veri->oncelik < yeniHasta->oncelik)
            iter = iter->sonraki;
        gecici = iter->sonraki;
        iter->sonraki = malloc(sizeof(siraEleman));
        iter->sonraki->veri = yeniHasta;
        iter->sonraki->sonraki = gecici;
    }
    printf("eklendi\n");
}


