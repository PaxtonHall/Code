import numpy as np

A_PLUS = 4.3
A = 4.0
A_MINUS = 3.7

Credit = np.array([3 , 3 , 2 , 3 , 3 , 3])
Grade = np.array([A , A_MINUS , A , A_PLUS , A_PLUS , A])

print(f"GPA: {(Credit * Grade).sum() / Credit.sum():.2f}")