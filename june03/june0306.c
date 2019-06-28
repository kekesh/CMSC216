void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 2, y = 3;
    int p = &x;
    int q = &y;
    swap(p, q);
}