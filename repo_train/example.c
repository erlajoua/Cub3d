/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 03:51:42 by lmarques          #+#    #+#             */
/*   Updated: 2020/02/21 11:16:12 by tsarafia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "example.h"
#include <stdio.h>
int	main(void)
{
	t_mlx	mlx; //Here I first create my struct that will contains all the "MLX stuff"
	int		count_w;
	int		count_h;

	count_h = -1;
	//First you need to call mlx_init and store its return value.
	mlx.mlx_ptr = mlx_init();
	//Now do the same with mlx_new_window
	mlx.win = mlx_new_window(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "A simple example");
	//One more time with mlx_new_image
	mlx.img.img_ptr = mlx_new_image(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	/*
	 Now the important part :
	 mlx_get_data_addr will return a char* that is 4 times the (width * height) of your image.
	 Why so ? Let me explain : This char* will represent your image, pixel by pixel,
	 and the values of this array are the colors. That's why the array is 4 times bigger :
	 you need 4 char to code the color of each pixels (one for Red, Green and Blue) and one for the alpha.
	 But... it's not very convenient, right ? So here is my little trick : you cast
	 mlx_get_data_addr as an int* and store it in an int*.
	 This way, the array will have the exact same size as your window, and each index
	 will represent one complete color of a pixel !
	*/
	mlx.img.data = (int *)mlx_get_data_addr(mlx.img.img_ptr, &mlx.img.bpp, &mlx.img.size_l,
		&mlx.img.endian);
	/*
	 Now just a little example : here is a loop that will draw each pixels that
	 have an odd width in white and the ones that have an even width in black.
	*/

	void *test;
	int w;
	int h;
	w = 0;
	h = 0;
	test = mlx_xpm_file_to_image(mlx.mlx_ptr, "./fruit.xpm", &w, &h);
	printf("%d - %d\n", w, h);
	
	while (++count_h < WIN_HEIGHT)
	{
		count_w = -1;
		while (++count_w < WIN_WIDTH)
		{
			if (count_w % 20)
			/*	
				 As you can see here instead of using the mlx_put_pixel function
				 I just assign a color to each pixel one by one in the image,
				 and the image will be printed in one time at the end of the loop.
				 Now one thing to understand here is that you're working on a 1-dimensional
				 array, while your window is (obviously) 2-dimensional.
				 So, instead of having data[height][width] here you'll have the following
				 formula : [current height * max width + current width] (as you can see below)
			*/	
				mlx.img.data[count_h * WIN_WIDTH + count_w] = 0xE475E4;
			else
				mlx.img.data[count_h * WIN_WIDTH + count_w] = 0;
	
		}
	}
	
	//Now you just have to print the image using mlx_put_image_to_window !
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win, mlx.img.img_ptr, 0, 0);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win, test, 655, 255);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
