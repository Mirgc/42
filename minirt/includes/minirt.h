#ifndef MINIRT_H
# define MINIRT_H

# include "mlx.h"
# include "tuples.h"
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>

# ifdef MACOS
#  define OS_NAME 1
# endif

# ifdef LINUX
#  define OS_NAME 2
# endif

# define EPSILON 0.00001
# define P_WIDTH 900 
# define P_HEIGHT 550

typedef struct s_color
{
        double  r;
        double  g;
        double  b;
} t_color;

typedef struct  s_mlx
{
        void    *init;
        void    *win;
        void    *img;
}                               t_mlx;

typedef struct  s_image
{
        char    *data;
        int     size;
        int     endian;
        int     bpp;
        int     *px_img;
}                               t_image;

typedef struct  s_map
{
        int     width;
        int     height;
        t_mlx   mlx;
        t_image image;
        t_color color;
}                               t_map;

t_color addcolor(t_color a, t_color b);
t_color subcolor(t_color a, t_color b);
t_color multicolor(t_color a, int b);
t_color hadacolor(t_color a, t_color b);

#endif
