/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkramer <lkramer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 02:19:22 by akuzmin           #+#    #+#             */
/*   Updated: 2025/11/04 18:14:38 by lkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int ac, char **av)
{
    t_game  *game;
    // t_list  *list; // This one is just check of my feature

    if (ac != 2)
        return (PRINT_ERROR("Usage: ./cub3d <./maps/some_map.cub>\n"), 1);

    // game = listed_malloc(&list, sizeof(t_game)); // this as well
    game = ft_calloc(1, sizeof(t_game));
    if (!game)
        return (PRINT_ERROR("Memory allocation error.\n"), 1);

    // if (testing())
    //     return (PRINT_ERROR("Invalid parsing\n"), 1);

    // game->list = list; 
    if (parse_cub_file(game, av[1]) == NULL)
        return (s_free(game), PRINT_ERROR("Parsing failed.\n"), 1);

    if (init_graphics(game))
        return (PRINT_ERROR("MLX graphic initialisation error.\n"), 1);

    mlx_hook(game->graphics.window, 2, 1L << 0, key_press, game);
    mlx_hook(game->graphics.window, 3, 1L << 1, key_release, game);
    mlx_hook(game->graphics.window, 17, 0, close_game, game); 

    mlx_loop_hook(game->graphics.mlx, update, game);
    mlx_loop(game->graphics.mlx);
    
    // ft_lstclear(&list, free); // and this
    s_free(game);
    return (PRINT_SUCCESS("Program finished as expected!"), 0);
}

