#include "../../includes/Libft/libft.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>



int main(int argc, char *argv[], char **envp)
{
    char	*ret;
    char	**token;
    int		i = 0;

    ret = readline("jsh> ");
    token = ft_split(ret, ' ');
    
    while (token[i])
    	printf("%s\n", token[i++]);

    return 0;
}
