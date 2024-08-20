import numpy as np

Credit = np.array([3 , 3 , 2 , 3 , 3 , 3])
Grade = np.array([4 , 3.7 , 4 , 4.3 , 4.3 , 4])
print(f"GPA: {(Credit * Grade).sum() / Credit.sum():.2f}")