## Structure 
``` s
cub3d/
├── Makefile
│
├── includes/
│	├── colors.h
│	├── defines.h
│   └── cub3d.h
│
├── libft/
│
├── maps/
│
├── textures/
│
└── src/						# Final root file
    │
    ├── core/
    │   ├── main.c				# Root execution point of programm    	
	│   └── cleenup.c			# Cleen after finish execution
    │
	├──init/					# Initialisation of data
	│   ├── init_data.c	      	    	
	│   └── init_graphics.c		# Initialise MLX, load images ind initialise collors for F&C
	|
    ├── input/
	│   ├── key_press.c			# Listner on key press    	
	│   └── Move_player.c		# move player/update game data
	│
	├── parser/					# Parser as input get string with path to map.cub
	│   ├── 1.c      	    	
	│   └── parser.c
	│
	├──render/					# Part with calculation of raus and display
	│   ├── renderer.c
	│   ├── draw_minimap.c   	   	
	│   └── draw_game.c
	│
	└── tests/
		├── tests.h
		├── parsed_data
		│	├── init.c
		│	├── main.c 
	    │   ├── maps.c
		│	├── tests.c
		│	├── utils.c   	
	    │   └── validator.c
		│
		├── ToDo:		# Iest to check is validation success and all data aranged correct	
		├──	ToDo:		# Other features to run it separately
		└──	Feature:	# Maybe need to change it from allocate to initialise on stack (without pointer)
```
