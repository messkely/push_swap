#include "push_swap.h"

void leaks()
{
    system("leaks a.out");
}

int isEmpty(const char *str)
{
    if (!str)
        return 1;
    while (*str != '\0')
    {
        if (!ft_isspace((unsigned char)*str))
            return 0;
        str++;
    }
    return 1;
}

int main()
{
    int i, j;
    char *r1 = "";
    char *av[] = {"  12 383 -485", "13 +39 495 +49","2"};
    i = 0;

    while (i < 3)
    {
        if (!isEmpty(av[i]))
        {
            j = 0;
            while (av[i][j])
            {
                if (av[i][j] == '+' || av[i][j] == '-')
                    j++;
                if (!ft_isdigit(av[i][j]) && av[i][j] != ' ')
                {
                    write(1, "Error", 5);
                    return (0);
                }
                j++;
            }
            r1 = ft_strjoin(r1, av[i++]);
        }
        else
        {
            write(1, "Error", 5);
            return (0);
        }
    }
    char **r2 = ft_split(r1, ' ');
    i = 0;
    while (r2[i])
        printf("%d\n", ft_atoi(r2[i++]));

    i = 0;
    while (r2[i])
        free(r2[i++]);
    free(r1);
    free(r2);
    // atexit(leaks);
}
