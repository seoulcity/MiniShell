#include "../../includes/Libft/libft.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

typedef struct	s_type_list {
    int			open_quote;
    int			close_quote;
    int			is_cmd;
    int			is_flag;
    int			is_env_parameter;
}				t_type_list;

typedef struct s_redir {
	int  in_type; // enum으로 here_doc = 0, redir_in = 1, redir_out = 2, redir_app = 3으로 지정
	int  out_type;
	char *filename; // redirection에 들어갈 filename
}              t_redir;

typedef struct s_cmd {
	char    **cmd; // [0]은 적절한 path가 연결된 cmd, [1]부터 cmd에 들어갈 인자
	t_redir redir_type;
}              t_cmd;

typedef struct s_arg {
	t_cmd *c_t; // 명령어 구조체 (파이프를 구분자로 끊어서 한 명령어 구조체에 넣는다)
	int  cmd_count; // 명령어 구조체 수
	int  **fds; // pipe의 fd[2]의 배열
}              t_arg;


int main(int argc, char *argv[], char **envp)
{
    char	*input;
	char	**split_strs;
	t_arg	args;
    int		i = 0;
	int		j = 0;

    input = readline("jsh> "); // 빈 문자열을 받았을 때 다시 실행되도록 해야 함
	
	split_strs = ft_split(input, '|'); // 파이프 앞뒤로 붙은 공백 제거해주어야 함
	while (split_strs[i])
    {	
		printf("%s\n", split_strs[i]);
		i++;
	}
	printf("size of args: %d\n", i);

	while (j > i) {
		args.c_t = ft_calloc(1, sizeof(t_cmd));
		args.c_t[j].cmd = ft_split(split_strs[j], ' ');
		j++;
	}
	// 배열 커맨드 나눠서 넣는 와일문 작업중!!!

	printf("the first command str: %s\n", args.c_t[0].cmd[0]);
	printf("the second command str: %s\n", args.c_t[0].cmd[1]);
	printf("the third command str: %s\n", args.c_t[0].cmd[2]);

    return 0;
}
