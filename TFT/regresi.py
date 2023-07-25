'''
import numpy as np

# Sample data
X = np.array([3628.25, 8063, 11984.66667, 15954.41667, 20934.41667, 25697, 30451.66667, 34567.75, 38670.58333,
              42718.58333, 46890.16667, 51216.66667, 55251.16667, 59269.83333, 63374.66667, 67359.16667,
              71647.33333, 75642.58333, 79803.66667, 83757.33333, 88592.41667, 92698.08333, 96866.33333])

y = np.array([10.1, 20.2, 30.2, 40.2, 50.4, 60.4, 70.4, 80.5, 90.6, 100.6, 110.7, 120.7, 130.7, 140.7, 150.7,
              160.7, 170.8, 180.9, 191, 201, 211.2, 221.3, 231.4])


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

'''

import numpy as np
from scipy.optimize import curve_fit

# Given data
X = np.array([3628.25, 8063, 11984.66667, 15954.41667, 20934.41667, 25697, 30451.66667, 34567.75, 38670.58333,
              42718.58333, 46890.16667, 51216.66667, 55251.16667, 59269.83333, 63374.66667, 67359.16667,
              71647.33333, 75642.58333, 79803.66667, 83757.33333, 88592.41667, 92698.08333, 96866.33333])

Y = np.array([10.1, 20.2, 30.2, 40.2, 50.4, 60.4, 70.4, 80.5, 90.6, 100.6, 110.7, 120.7, 130.7, 140.7, 150.7,
              160.7, 170.8, 180.9, 191, 201, 211.2, 221.3, 231.4])

# Define the linear function
def linear_func(X, a, b):
    return a * X + b

# Perform the linear regression
coefficients, _ = curve_fit(linear_func, X, Y)

# Extract the coefficients
a, b = coefficients

# Print the coefficients
print(f"The coefficients of the linear regression are:")
print(f"a: {a}")
print(f"b: {b}")
