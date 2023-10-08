/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 20:59:53 by jahernan          #+#    #+#             */
/*   Updated: 2022/10/28 13:57:24 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"
# define ZER_F 1
# define MIN_F 2
# define HSH_F 4
# define SPC_F 8
# define PLS_F 16

typedef struct s_options
{
	unsigned char	flags;
	int				width;
	int				precision;
	unsigned char	specifier;
}	t_options;

size_t	ft_handle_conversion(const char **str, va_list args);
void	ft_fix_flags(t_options *opts);
void	ft_process_flags(const char **str, t_options *opts);
void	ft_process_precision(const char **str, t_options *opts);
void	ft_process_width(const char **str, t_options *opts);
void	ft_process_spec(const char **str, t_options *opts);
size_t	ft_print_value(t_options *opts, va_list args);
char	*ft_convert_usig(t_options *opts, va_list args);
char	*ft_convert_p(t_options *opts, va_list args);
char	*ft_convert_dec(t_options *opts, va_list args);
char	*ft_convert_str(t_options *opts, va_list args);
char	*ft_convert_c(t_options *opts, va_list args, size_t *len);
void	ft_store_sign(t_array *arr, int is_neg, t_options *opts);
void	ft_store_width(t_array *arr, int is_neg, t_options *opts);
void	ft_store_precision(t_array *arr, t_options *opts);
void	ft_init_opts(t_options *opts);
char	ft_get_digit(size_t idx, char specifier);
void	ft_arr_handle_outofbounds_depr(t_array *arr);
#endif
