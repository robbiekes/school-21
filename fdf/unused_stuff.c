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

