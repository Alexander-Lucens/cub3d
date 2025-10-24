/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 02:19:22 by akuzmin           #+#    #+#             */
/*   Updated: 2025/10/24 02:35:57 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

int	parser_test_map0(t_parsed_data *origin)
{
	int				ret;
	t_test_data		*data;
	t_parsed_data	*expect;

	ft_printf(" --- Parser test 0 ---\n");
	expect = parsed_data_map0(void);
	data = init_test_struct(origin, expect, MAP_0_WIDTH, MAP_0_HEIGHT);
	ret = parser_test_map(data);
	ft_printf(" --- END OF TEST ---\n");
	return (ret);
}

int	parser_test_map1(t_parsed_data *origin)
{
	int				ret;
	t_test_data		*data;
	t_parsed_data	*expect;

	ft_printf(" --- Parser test 1 ---\n");
	expect = parsed_data_map1(void);
	data = init_test_struct(origin, expect, MAP_0_WIDTH, MAP_0_HEIGHT);
	ret = parser_test_map(data);
	ft_printf(" --- END OF TEST ---\n");
	return (ret);
}

int	parser_test_map2(t_parsed_data *origin)
{
	int				ret;
	t_test_data		*data;
	t_parsed_data	*expect;

	ft_printf(" --- Parser test 2 ---\n");
	expect = parsed_data_map2(void);
	data = init_test_struct(origin, expect, MAP_0_WIDTH, MAP_0_HEIGHT);
	ret = parser_test_map(data);
	ft_printf(" --- END OF TEST ---\n");
	return (ret);
}