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
	char	**split_blanks;

	t_arg	args;
    int		i = 0;
	int		j = 0;
	int		k = 0;

	// while (1)
	// {
		input = readline("jsh> "); // 빈 문자열을 받았을 때 다시 실행되도록 해야 함

		// 따옴표 처리

		// 이하 51 - 63번째 줄은 파이프 기준으로 명령어 구조체 포인터(args.c_t)에 나눠서 배치하되,
		// 이를 다시 띄워쓰기 단위로 커맨드 나누어 배열(char** args.c_t[i].cmd)로 입력하는 부분

		split_strs = ft_split(input, '|'); // 파이프 앞뒤로 붙은 공백 제거해주어야 함
		
		while (split_strs[i])
			i++;
		args.cmd_count = i;
		args.c_t = ft_calloc(i, sizeof(t_cmd));
		args.c_t[i].cmd = NULL;

		while (j < i)
		{
			args.c_t[j].cmd = ft_split(split_strs[j], ' ');
			j++;
		}
		
		// 배열 스플릿이 잘 되었는지 확인하는 테스터
		/* j = 0;
		while (j < i)
		{
			while (args.c_t[j].cmd[k])
			{	
				printf("[%d][%d]: %s\n", j, k, args.c_t[j].cmd[k]);
				k++;
			}
			j++;
			k = 0;
		} */ 

		/* 시그널 처리
		ctrl + c 새로운 줄 출력
		ctrl + d 종료
		ctrl + \ 무반응  
		*/
	// }
    return 0;
}
