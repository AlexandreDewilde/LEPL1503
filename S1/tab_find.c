/* tab_find

@tab : an array of int
@len : the number of int in tab
@elem : the elem looked for
@return : return the index at which elem is found, else returns -1 if not found. */
int tab_find(int tab[], int len, int elem)
{
    for (int i = 0; i < len; i++)
    {
        if (tab[i] == elem) return i;
    }
    return -1;
}