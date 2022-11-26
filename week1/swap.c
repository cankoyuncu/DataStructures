void swap_1(int x, int y) // Call By Value
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}
void swap_2(int &x, int &y) // Call By Reference
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}
int main()
{
    int a = 100;
    int b = 200;

    printf("Swap oncesi a'nin degeri: %d\n", a);
    printf("Swap oncesi b'nin degeri: %d\n\n", b);

    swap_1(a, b); // Call By Value

    printf("Swap_1 sonrasi a'nin degeri: %d\n", a);
    printf("Swap_1 sonrasi b'nin degeri: %d\n\n", b);

    swap_2(a, b); // Call By Reference

    printf("Swap_2 sonrasi a'nin degeri: %d\n", a);
    printf("Swap_2 sonrasi b'nin degeri: %d\n\n", b);
    getch();
    return 0;
}