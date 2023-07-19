import numpy as np
import matplotlib.pyplot as plt

def julia_set(width, height, x_min, x_max, y_min, y_max, max_iter, c):
    x, y = np.linspace(x_min, x_max, width), np.linspace(y_min, y_max, height)
    x, y = np.meshgrid(x, y)
    z = x + y * 1j
    fractal = np.zeros_like(z, dtype=np.float32)

    for i in range(max_iter):
        z = z ** 2 + c
        mask = np.abs(z) < 4.0  # Check if the magnitude is less than 4 (bounded)
        fractal += mask.astype(np.float32)

    fractal /= max_iter
    return fractal

# Set the initial parameters for the fractal generation
width, height = 800, 600
x_min, x_max = -2.0, 2.0
y_min, y_max = -1.5, 1.5
max_iter = 100
c = complex(-0.8, 0.156)

# Generate the initial Julia set fractal
fractal = julia_set(width, height, x_min, x_max, y_min, y_max, max_iter, c)

# Create the initial plot
plt.imshow(fractal, cmap='hot', extent=(x_min, x_max, y_min, y_max))
plt.colorbar()
plt.title('Julia Set Fractal (c = {:.4f} + {:.4f}i)'.format(c.real, c.imag))
plt.xlabel('Re')
plt.ylabel('Im')
plt.show()
