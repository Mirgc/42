#include "map.h"

int main(int argc, char **argv)
{
    int             bytes;
    int             i;
    unsigned char   buffer[10];
    char            *str;
    t_map           *map;
    t_map           *map_c1;
    t_map           *map_c2;

    if (argc == 1)
        bytes = read(1, buffer, 10);
    else
    {
        i = 1;
        while (i < argc)
        {
            str = ft_read_file(argv[i]);
            printf("%s \n", str);
            map = ft_parse_str_to_map(str);
            map_c1 = ft_copy(map);
            map_c2 = ft_copy(map);
            //ft_fill_test_square(map);
            //ft_get_table_max_size(map);
            ft_printf_dia(map);
            map->r_size = 2;
            printf("size:%i\n", map->size);
            printf("r_size:%i\n",map->r_size);
            printf("resolved:%i\n",map->resolved);
            ft_decision_tree(map_c1, map_c2);
            printf("\n");
            ft_printf_dia(map);
            printf("\n");
            ft_printf_dia(map_c2);
            printf("\n");
            ft_printf_dia(map_c1);
            i++;
        }
    }
    return (0);
}
