/* Try variants for StreamReadDword - re-read pattern */

/* Cleanest form: explicit re-read */
int Try1(int **stream) {
    int *p, *q;
    p = *stream;
    *stream = p + 1;
    q = *stream;
    return *(q - 1);
}

/* Without intermediate locals — use *stream twice */
int Try2(int **stream) {
    *stream = *stream + 1;
    return (*stream)[-1];
}

/* p++ style */
int Try3(int **stream) {
    int *p = *stream;
    *stream = p + 1;
    p = *stream;
    return p[-1];
}

/* Concise form: ++(*stream); return prev */
int Try4(int **stream) {
    int *p = ++*stream;
    return p[-1];
}
