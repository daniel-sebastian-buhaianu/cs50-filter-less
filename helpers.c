#include <math.h>
#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			// get rgb values from image[i][j]
			BYTE blue_hex, green_hex, red_hex;
			blue_hex = image[i][j].rgbtBlue;
			green_hex = image[i][j].rgbtGreen;
			red_hex = image[i][j].rgbtRed;

			// calculate gray shade using the average method
			BYTE gray_hex = round( (blue_hex + green_hex + red_hex) / 3.0 );

			// replace rgb with gray
			image[i][j].rgbtBlue = gray_hex;
			image[i][j].rgbtGreen = gray_hex;
			image[i][j].rgbtRed = gray_hex;
		}
	}
	return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			// get rgb values from image[i][j]
			BYTE blue_hex, green_hex, red_hex;
			blue_hex = image[i][j].rgbtBlue;
			green_hex = image[i][j].rgbtGreen;
			red_hex = image[i][j].rgbtRed;

			// calculate sepia values using the harvard formula;
			red_hex = round( (float)(red_hex * 0.393) + (float)(green_hex * 0.769) + (float)(blue_hex * 0.189) );
			green_hex = round( (float)(red_hex * 0.349) + (float)(green_hex * 0.686) + (float)(blue_hex * 0.168) );
			blue_hex = round( (float)(red_hex * 0.272) + (float)(green_hex * 0.534) + (float)(blue_hex * 0.131) );

			// replace rgb with sepia
			image[i][j].rgbtBlue = blue_hex;
			image[i][j].rgbtGreen = green_hex;
			image[i][j].rgbtRed = red_hex;
		}
	}
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
	// create a "mirrored" copy of image (mirror effect)
	RGBTRIPLE mirrored_image[height][width];
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			int k = width - 1 - j;
			// mirrored_image[i][j] = image[i][k] to create mirror effect
			mirrored_image[i][j].rgbtRed = image[i][k].rgbtRed;
			mirrored_image[i][j].rgbtGreen = image[i][k].rgbtGreen;
			mirrored_image[i][j].rgbtBlue = image[i][k].rgbtBlue;
		}
	}

	// replace image[][] with mirrored_image[][]
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			image[i][j].rgbtRed = mirrored_image[i][j].rgbtRed;
			image[i][j].rgbtGreen = mirrored_image[i][j].rgbtGreen;
			image[i][j].rgbtBlue = mirrored_image[i][j].rgbtBlue;
		}
	}
	return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
