import numpy as np
import matplotlib.pyplot as plt

def mandelbrot_set(width, height, x_min, x_max, y_min, y_max, max_iter):
    x, y = np.linspace(x_min, x_max, width), np.linspace(y_min, y_max, height)
    x, y = np.meshgrid(x, y)
    c = x + y * 1j
    z = np.zeros_like(c)

    fractal = np.zeros(c.shape, dtype=np.float32)

    for i in range(max_iter):
        z = z * z + c
        mask = np.abs(z) < 4.0  # Check if the magnitude is less than 4 (bounded)
        fractal += mask.astype(np.float32)

    fractal /= max_iter
    return fractal

# Set the parameters for the fractal generation
width, height = 800, 600
x_min, x_max = -2.5, 1.5
y_min, y_max = -1.5, 1.5
max_iter = 100

# Generate the Mandelbrot set fractal
fractal = mandelbrot_set(width, height, x_min, x_max, y_min, y_max, max_iter)

# Display the fractal using matplotlib
plt.imshow(fractal, cmap='hot', extent=(x_min, x_max, y_min, y_max))
plt.colorbar()
plt.title('Mandelbrot Set Fractal')
plt.xlabel('Re')
plt.ylabel('Im')
plt.show()
