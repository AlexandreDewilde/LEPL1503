struct fract_t {
    int num;
    int denum;
};

void swap(struct fract_t *a, struct fract_t *b)
{
    struct fract_t temp = *a;
    *a = *b;
    *b = temp;
}