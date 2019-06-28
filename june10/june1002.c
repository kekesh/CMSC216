int strcmp(const char *s1, const char *s2) {
    int i;
    for (i = 0; s1[i] && s2[i]; i++) {
        if (s1[i] != s2[i]) {
            break; /* Gets us out of the for loop */
        }
    }
    return s1[i] - s2[i];
}