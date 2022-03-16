#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_tup
{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_tup;

typedef struct s_proj
{
	t_tup	pos;
	t_tup	vel;
}	t_proj;

typedef struct s_env
{
	t_tup	grav;
	t_tup	wind;
}	t_env;

typedef struct s_color
{
	double  r;
	double  g;
	double  b;
}	t_color;

typedef struct s_matrix
{
	float m[4][4];
	int	rows;
	int	cols;
}	t_matrix;

typedef struct s_ray
{
	t_tup	ori;
	t_tup	dir;
} t_ray;

typedef struct	s_material
{
	t_color	color;
	float	ambient;
	float	diffuse;
	float	specular;
	float	shininess;
}	t_material;

typedef struct s_sphere
{
	t_tup		center;
	char		id;
	float		r;
	t_matrix	transform;
	t_material	material;
} t_sphere;

typedef struct s_plane
{
	t_tup		center;
	char		id;
	float		r;
	t_matrix	transform;
	t_material	material;
} t_plane;

typedef struct s_shape
{
        t_sphere        sp;
	t_plane		pl;
        char            shape;
}       t_shape;

typedef struct s_inter
{
	float		t;
	t_shape		o;
} t_inter;

typedef struct s_arr_inter
{
	int	count;
	t_inter	*a;
} t_arr_inter;

typedef struct	s_light
{
	t_tup	position;
	t_color	intensity;
}	t_light;

typedef struct s_world
{
        t_light         li;
        t_shape        *sh;
        int                     nb;
        t_arr_inter     arr;
	t_ray		ray_saved;
}       t_world;

typedef struct s_camera
{
	double			hsize;
	double			vsize;
	double			fov;
	double			pixel_size;
	double			hw;
	double			hh;
	t_matrix		transform;
}       t_camera;

typedef struct s_comps
{
        float		t;
        t_shape		o;
        int		inside;
        t_tup		point;
        t_tup		eyev;
        t_tup		normalv;
        t_tup		over_point;
}	t_comps;

typedef struct  s_mlx
{
	void    *init;
	void    *win;
	void    *img;
}	t_mlx;

typedef struct  s_image
{
	char    *data;
	int     size;
	int     endian;
	int     bpp;
	int     *px_img;
}	t_image;

typedef struct  s_map
{
	int     width;
	int     height;
	t_mlx   mlx;
	t_image image;
	t_color color;
	t_camera	cam;
}	t_map;


#endif
