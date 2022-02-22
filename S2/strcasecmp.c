int strcasecmp(const char *s1, const char *s2)
{
    int i;
    for (i=0; s1[i] != '\0' && s2[i] != '\0'; i++) {
        char one, two ;
        one = s1[i];
        two = s2[i];
        if (one >= 97 && one <= 122) one = one - 'a' + 'A';
        if (two >= 97 && two <= 122) two = two - 'a' + 'A';

        if (one < two) return -1;
        else if (two < one) return 1;
    }

    if (s1[i] == s2[i]) return 0;
    if (s1[i] == '\0') return -1;
    return 1;
}