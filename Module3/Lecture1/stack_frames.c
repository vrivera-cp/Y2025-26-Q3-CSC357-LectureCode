int function(int a)
{
    int b = a + 1;
    int c = function(b);
    return c;
}

int main(void)
{
    function(0);
    return 0;
}