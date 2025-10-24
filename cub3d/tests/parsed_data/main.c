/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 02:19:22 by akuzmin           #+#    #+#             */
/*   Updated: 2025/10/24 07:15:12 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

t_parsed_data	*fake_parser(char *path)
{
	(void)path;

	t_parsed_data	*fake = parsed_data_map0();
	return (fake);
}

int main(void)
{
	int ret;
	
	ft_printf("----- Starts validation of parser -----\n");
	// ret = run_as_validator(/* PLACE FOR PARSER FUNCTION */);
	ret = run_as_validator(fake_parser);
	
	ft_printf("\n------- END OF VALIDATION -------\n");
	return (ret);	
}