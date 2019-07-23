void *memcpy(void *dst, void *src, size_t n) {
   char *dp = dst;
   char *sp = src;

   while (dp - (char *) dst < n) {
      *dp++ = *sp++;
   }

   return dst;
}