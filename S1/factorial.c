int factorial(int n)
{
    if (n <= 1) return 1;
    return n * factorial(n-1);
}


// Alternative  tail recursive

int fact2(int n, int acc)
{
    if (n <= 1) return acc;
    return fact2(n-1, acc*n);
}

int factorial(int n)
{
    return fact2(n, 1);
}


// Alternartive iterative

int factorial(int n)
{
    int ans = 1;
    for (int i=1;i<=n;i++) ans *=i;
    return ans;
}


// Alternartive iterative with while
int factorial(int n)
{
    int ans = 1;
    n++;
    while (--n) ans *= n;
    return ans;
}

