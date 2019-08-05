int i, j, k;
....
int prod_2j, prod_jk;
prod_2j = 2 * j;
prod_jk = j * k;
for (i = 0; i < 200; i++) {
    a[prod_2j + i] = prod_jk + i;
}