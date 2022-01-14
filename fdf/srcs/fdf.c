#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int colour)
{
	char	*dst;

	dst = data->address + (y * data->line_len + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = colour;
}

int main()
{
	void	*mlx;
	t_data	img;
	int i = 100;
	int j = 100;
	void	*mlx_window;

	mlx = mlx_init();
	mlx_window = mlx_new_window(mlx, 900, 800, "hello world!");
	img.image = mlx_new_image(mlx, 900, 800);
	img.address = mlx_get_data_addr(img.image, &img.bits_per_pixel,
					&img.line_len, &img.endian);
	while (i < 200)
	{
		my_mlx_pixel_put(&img, i, j, 0x00FF0000);
		mlx_put_image_to_window(mlx, mlx_window, img.image, 0, 0);
		i++;
	}
	while (j < 200)
	{
		my_mlx_pixel_put(&img, i, j, 0x00FF0000);
		mlx_put_image_to_window(mlx, mlx_window, img.image, 0, 0);
		j++;
	}
	while (i > 100)
	{
		my_mlx_pixel_put(&img, i, j, 0x00FF0000);
		mlx_put_image_to_window(mlx, mlx_window, img.image, 0, 0);
		i--;
	}
	while (j > 100)
	{
		my_mlx_pixel_put(&img, i, j, 0x00FF0000);
		mlx_put_image_to_window(mlx, mlx_window, img.image, 0, 0);
		j--;
	}
	mlx_loop(mlx);
} 
