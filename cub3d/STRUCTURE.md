## Structure 
``` s
cub3d/
├── Makefile
│
├── includes/
│   └── cub3d.h
│
├── libft/
│
├── maps/
│
├── textures/
│
└── src/
    ├── main.c					# Finel root file
    │
    ├── parser/
    │   ├── parser.c            # Core file of parser
    │   ├── validate_map.c      # Map validation and throw error on issue
    │   ├── parse_elements.c	# Add graphics element to struct
    │   └── parser_utils.c		# Just utils
    │
    └── renderer/
	│       ├── renderer.c      	# Initialise MLX, start game loop
	│       ├── hooks.c         	# Key pres hooks
	│       ├── raycasting.c    	# Raycasting, first of all for 2d then finde ot how to use this "rays" and >
	│       └── draw.c          	# Draw textures (walls, floor, ceiling)
	│
	└── tests/
		├── test_main.c				# Pre difine structures and "main" to run render separately from parser
		├── test_cases.c			# This things try to run parser and compare it output with mok data
		├──	moks_data.c				# Pre made date for 3 maps which will be in /maps folder
		└──	test_parser.c			# Runs all test cases and make validation is parser past test or not
```
