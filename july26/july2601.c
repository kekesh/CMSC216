char *itoa(int n) {
    static char buffer[50];
    sprintf(buffer, "%d", n);
    return buffer;
}