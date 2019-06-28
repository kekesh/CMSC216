int* get_value-wrong() {
    int x = 20;
    return &x;
}

int add_value(int y) {
    int a = 99;
    return a + y;
}

int main(void) {
    int *a, b;
    
    a = get_value_wrong();
    printf("First result %d\n", *a);
    
    b = add_value(7);
    printf("Second value %d\n", b);
    
    printf("First result (changed?) %d\n", *a);
}