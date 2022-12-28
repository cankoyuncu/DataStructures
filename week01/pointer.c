main() {

    int kutle = 100;
    int *m;
    m = &kutle;

    printf("%d\n", kutle); // kutle değişkeninin verisini yazdirir. ekrana 100 yazılır.
    printf("%p\n", &kutle); // kutle değişkeninin Ram'de bulunduğu yeri yazdirir.
    printf("%p\n", m); // a değişkeninin verisini yazdirir.
    printf("%d\n", *m); // a değişkeninin adresindeki veri yazilir.
    printf("%p\n", &m); // a değişkeninin adresi yazilir.

    return 0;
}
