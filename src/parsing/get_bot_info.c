

#include "../../inc/vm.h"

int 		get_bot_name(const int fd, t_bot **tmp)
{
	int 	r;

	r = (int)read(fd, &(*tmp)->name, 128);
	if (r < 128)
		return (0);
	return (1);
}

int 		get_bot_size(const int fd, t_bot **tmp)
{
	int 	r;
	unsigned char 	buf[8];

	r = (int)read(fd, &buf, 4);
	if (r < 4)
		return (0);
	(*tmp)->size = 0;
	(*tmp)->size += buf[3] +
		   (buf[2] << 8) +
		   (buf[1] << 16) +
		   (buf[0] << 24);
	return (1);
}

int 		get_bot_comment(const int fd, t_bot **tmp)
{
	int 	r;

	r = (int)read(fd, &(*tmp)->comment, 254);
	if (r < 254)
		return (0);
	return (1);
}


int 		get_bot_code(const int fd, t_bot **tmp)
{
	unsigned char buf[2];
	int 	ret;
	int		flag = 0;
	int 	all;

	all = 0;
	while ((ret = (int)read(fd, buf, 1)) > 0) {
		if (buf[0] != '\0' || flag) {
			buf[ret] = '\0';
			(*tmp)->code[all] = buf[0];
			++all;
			flag = 1;
		}
	}
		(*tmp)->code_length = all;

	return (1);
}


int         check_size_is_true(t_bot bot)
{

	if (bot.code_length == bot.size)
		return (1);
	if (bot.code_length > CHAMP_MAX_SIZE)
		ft_printf(RED"Error: File %s has too large a code (%i bytes > 682 bytes)\n"RESET, bot.filename, bot.code_length);
	return (0);
}
