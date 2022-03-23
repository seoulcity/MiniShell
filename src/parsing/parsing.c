#include "../../includes/Libft/libft.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

typedef struct	s_type_list {
    int			open_quote;
    int			close_quote;
    int			is_cmd; // pipe 포함
    int			is_flag;
    int			is_env_parameter;
}				t_type_list;

typedef struct		s_token {
    char			*str;
    t_type_list		type_list;
    struct  s_token	*next;
}					t_token;

typedef	struct		s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}					t_env;


typedef struct		s_state {
	t_token			*token_head;
	t_env			*env_head;
}					t_state;

t_state				g_state;

t_token	*array_split_to_token(char **array, t_token *token_head)
{
	t_token *temp_head;
	int 	idx;
	int		len;

	idx = 0;
	
	temp_head = token_head;
	while (*array[idx])
	{
		token_head = (t_token *)malloc(sizeof(t_token));
		len = ft_strlen(array[idx]);
		token_head->str = ft_substr(array[idx], 0, len);
		idx++;
		token_head = token_head->next;
	}
	token_head->next = NULL;

	return (temp_head);
}

void	init_state(t_state *state)
{
	ft_memset((void *)state, 0, sizeof(t_state));
}


int main(int argc, char *argv[], char **envp)
{
    char	*input;
	char	**split_strs;
    int		i = 0;
	t_token *temp;

	init_state(&g_state);
    input = readline("jsh> ");
	split_strs = ft_split(input, ' ');
	// while (split_strs[i])
    // {	
	// 	printf("%s\n", split_strs[i]);
	// 	i++;
	// }
	
	temp = array_split_to_token(split_strs, g_state.token_head);
	// 입력받은 내용을 빈칸 기준으로 나눠서 토큰에 집어넣는 거 잘 안 되네요...
    

    return 0;
}
