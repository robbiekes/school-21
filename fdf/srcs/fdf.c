#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int colour)
{
	char	*dst;

	dst = data->address + (y * data->line_len + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = colour;
}

void	draw_circle(int x0, int y0, int radius, int colour, t_data *img)
{
	int x = 0;
	int y = radius;
	int delta = 1 - 2 * radius;
	int error = 0;
	while (y >= 0)
	{
		my_mlx_pixel_put(img, x0 + x, y0 + y, colour);
		my_mlx_pixel_put(img, x0 + x, y0 - y, colour);
		my_mlx_pixel_put(img, x0 - x, y0 + y, colour);
		my_mlx_pixel_put(img, x0 - x, y0 - y, colour);
		colour += 0x00000001;
		colour -= 0x00010000;
		if(delta < 0 && error <= 0)
		{
			++x;
			delta += 2 * x + 1;
			continue;
		}
		error = 2 * (delta - x) - 1;
		if (delta > 0 && error > 0) {
			--y;
			delta += 1 - 2 * y;
			continue;
		}
		++x;
		delta += 2 * (x - y);
		--y;
	}
}

void	draw_square(t_data *img, void	*mlx, void	*mlx_window)
{
	int x = 200;
	int y = 200;
	while (x < 400)
	{
		my_mlx_pixel_put(img, x, y, 0x00FF0000);
		mlx_put_image_to_window(mlx, mlx_window, img->image, 0, 0);
		x++;
	}
	while (y < 400)
	{
		my_mlx_pixel_put(img, x, y, 0x00FF0000);
		mlx_put_image_to_window(mlx, mlx_window, img->image, 0, 0);
		y++;
	}
	while (x > 200)
	{
		my_mlx_pixel_put(img, x, y, 0x00FF0000);
		mlx_put_image_to_window(mlx, mlx_window, img->image, 0, 0);
		x--;
	}
	while (y > 200)
	{
		my_mlx_pixel_put(img, x, y, 0x00FF0000);
		mlx_put_image_to_window(mlx, mlx_window, img->image, 0, 0);
		y--;
	}
}

void	draw_line(int x, int y, int x1, int y1, t_data *img)
{
	int	deltaX = abs(x1 - x);
	int	deltaY = abs(y1 - y);
	int signX = 0;
	int signY = 0;
	if (x < x1)
		signX = 1;
	else
		signX = -1;
	if (y < y1)
		signY = 1;
	else
		signY = -1;
	int error = deltaX - deltaY;
	my_mlx_pixel_put(img, x1, y1, 0x00FF0000);
	while(x != x1 || y != y1) 
	{
		my_mlx_pixel_put(img, x, y, 0x00FF0000);
		int error2 = error * 2;
		if(error2 > -deltaY) 
		{
			error -= deltaY;
			x += signX;
		}
		if(error2 < deltaX) 
		{
			error += deltaX;
			y += signY;
		}
	}
}

int main()
{
	void	*mlx;
	t_data	img;
	void	*mlx_window;

	mlx = mlx_init();
	mlx_window = mlx_new_window(mlx, 900, 800, "hello world!");
	img.image = mlx_new_image(mlx, 900, 800);
	img.address = mlx_get_data_addr(img.image, &img.bits_per_pixel,
					&img.line_len, &img.endian);

	// draw_circle(300, 300, 140, 0x00FF0000, &img);
	// draw_square(&img, &mlx, &mlx_window);
	// draw_circle(500, 300, 138, 0x000000FF, &img);
	// draw_circle(400, 400, 136, 0x00FF0000, &img);
	draw_line(50, 50, 200, 150, &img);
	mlx_put_image_to_window(mlx, mlx_window, img.image, 0, 0);
	mlx_loop(mlx);
} 
