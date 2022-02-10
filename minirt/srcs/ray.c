#include "tuples.h"
#include "ray.h"

t_tup	r_position(t_ray a, float i)
{
	return (v_add(a.ori, v_multi(a.dst, i)));
}
