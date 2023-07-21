import numpy as np

# Sample data
X = np.array([-190.2142857, 4173.071429, 8291.571429, 12429.78571, 16509.78571, 20434.85714, 25490.35714, 30169.35714])
y = np.array([0, 9.9, 20.1, 30.5, 40.4, 50.4, 60.5, 70.6])

# Create the Vandermonde matrix
n = X.shape[0]
X_poly = np.column_stack([X**2, X, np.ones(n)])

# Calculate the coefficients using the least squares method
coefficients = np.linalg.lstsq(X_poly, y, rcond=None)[0]

# Extract the coefficients for ax^2 + bx + c
a = coefficients[0]
b = coefficients[1]
c = coefficients[2]

# Print the coefficients
print("Coefficients:")
print("a =", a)
print("b =", b)
print("c =", c)
