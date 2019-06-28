void wrong_swap(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 2, y = 3;
    wrong_swap(x, y);
}