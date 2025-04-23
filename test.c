#include <mlx.h>
#include <math.h> // For sin() and cos()

typedef struct s_data {
    void    *mlx;
    void    *win;
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
} t_data;

// Function to put a pixel at (x,y) with specified color
void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    // Check if the pixel is within window bounds
    if (x >= 0 && x < 800 && y >= 0 && y < 600)
    {
        dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
        *(unsigned int*)dst = color;
    }
}

// Function to draw a circle using trigonometric functions
void draw_trig_circle(t_data *data, int center_x, int center_y, int radius, int color)
{
    double  angle;
    double  angle_step;
    int     x;
    int     y;
    int     i;

    angle_step = 2 * M_PI / 360; // Step size (1 degree in radians)
    
    for (i = 0; i < 360; i++)
    {
        angle = i * angle_step;
        x = center_x + (int)(radius * cos(angle));
        y = center_y + (int)(radius * sin(angle));
        my_mlx_pixel_put(data, x, y, color);
    }
}

int main(void)
{
    t_data  data;

    // Initialize MLX and create window
    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, 800, 600, "Trigonometric Circle");
    
    // Create image buffer
    data.img = mlx_new_image(data.mlx, 800, 600);
    data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, 
                                 &data.line_length, &data.endian);
    
    // Draw a white circle with radius 100 at center (400, 300)
    draw_trig_circle(&data, 400, 300, 100, 0x00FFFFFF);
    
    // Display the image in the window
    mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
    
    // Start the MLX loop
    mlx_loop(data.mlx);
    return (0);
}


///////////////////////////////////////////
#include <mlx.h>

typedef struct s_data {
    void    *mlx;
    void    *win;
    void    *img;
    int     img_width;
    int     img_height;
}               t_data;

int main(void)
{
    t_data  data;

    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, 800, 600, "Circle Image Example");
    
    // Load your circle image (must be in XPM format for MLX)
    data.img = mlx_xpm_file_to_image(data.mlx, "circle.xpm", 
                                    &data.img_width, &data.img_height);
    if (!data.img)
    {
        // Handle error - image not found
        return (1);
    }
    
    // Display the image at position (x, y)
    mlx_put_image_to_window(data.mlx, data.win, data.img, 350, 250);
    mlx_loop(data.mlx);
    return (0);
}
