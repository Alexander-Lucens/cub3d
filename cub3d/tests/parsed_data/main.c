/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkramer <lkramer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 02:19:22 by akuzmin           #+#    #+#             */
/*   Updated: 2025/10/24 21:44:09 by lkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

t_parsed_data	*fake_parser(char *path)
{
	(void)path;

	t_parsed_data	*fake = parsed_data_map2();
	return (fake);
}

int main(void)
{
	int ret;

	ft_printf("=== PARSER TESTING SUITE ===\n\n");
	
	ft_printf("----- Starts validation of parser -----\n");
	ret = run_as_validator(fake_parser);

	/* ft_printf("----- Testing real parser -----\n");
    ret = run_as_validator(test_parser_wrapper);   */

	ft_printf("----- Testing individual parser functions -----\n");
    test_parse_texture_path();
    test_parse_color();
	test_parse_cub_file();
	
	ft_printf("\n------- END OF VALIDATION -------\n");
	return (ret);	
}