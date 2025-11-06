/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 02:19:22 by akuzmin           #+#    #+#             */
/*   Updated: 2025/11/06 16:59:01 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static int	individual_testing(void)
{
	int	ret;

	ret = 0;
	ft_printf("----- Testing individual parser functions -----\n");
	ret += test_valid_parse_texture_path();
	ret += test_invalid_parse_texture_path();
	ret += test_valid_parse_color();
	ret += test_invalid_parse_color();
	ret += test_valid_parse_cub_file();
	ret += test_valid1_parse_cub_file();
	ret += test_valid2_parse_cub_file();
	return (ret);
}

int	testing(void)
{
	int	ret;

	ret = 0;

	ft_printf("=== PARSER TESTING SUITE ===\n\n");
	ft_printf("----- VALIDATE PARSER -----\n");
	ret = run_as_validator_game(parse_cub_file);
	ret += individual_testing();
	ft_printf("------- END OF VALIDATION -------\n");
	if (ret)
		return (1);
	return (0);
}
