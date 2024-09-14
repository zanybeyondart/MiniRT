#include "../inc/minirt.h"

int	create_trgb(int t, int r, int g, int b) //zain function
{
	t = 0;
	if (r < 0)
		r = 0;
	else if (r > 255)
		r = 255;
	if (g < 0)
		g = 0;
	else if (g > 255)
		g = 255;
	if (b < 0)
		b = 0;
	else if (b > 255)
		b = 255;
	return (t << 24 | r << 16 | g << 8 | b);
}