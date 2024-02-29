/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snkeneng <snkeneng@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 11:49:03 by snkeneng          #+#    #+#             */
/*   Updated: 2024/02/18 20:05:14 by snkeneng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_Dict {
	char	*number;
	char	*word;
	int		digit;
};

/* atoi.c */
int		parse_ui(char **str, int *val);
int		ft_atoi(char *str);
long	ft_atol(char *str);
/* */
char	*ft_strncpy(char *dest, char *src, unsigned int b);
char	*read_file(char *file_name);
int		extract_lines(char *str);
void	ft_putstr(char *str);
/* dict_handler.c */
int		find_from_digit(int digit, struct s_Dict *dict, int size);
void	extract_dic_elements(char *str, struct s_Dict *dict);
void	fill_data(int size, char **arr, char *str);
void	print_dict(struct s_Dict *dict, int size);
/* number_handler.c */
int		tens_handler(char *str, struct s_Dict *dict, int p_z);
int		hund_handler(char *str, struct s_Dict *dict, int dic_len, int p_z);
void	loop_handle3(char *str, struct s_Dict *dict, int dic_len, int p_z);
/* utils.c */
int		char_to_int(char c);
int		ft_strlen(char *str);
/* sort.c */
void	sort_dict(struct s_Dict *dict, int size);
void	handle_rush(struct s_Dict *dict, int dic_len, char *str, int str_len);
int		has_duplicates(struct s_Dict *dict, int dic_len);
int		is_valid_dictionary(char *str);
