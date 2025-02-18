def calculate_factorial(n):
    """
    Calculate the factorial of a given number.

    Parameters:
    n (int): The number for which to calculate the factorial.

    Returns:
    int: The factorial of the input number.
    """
    if n == 0 or n == 1:
        return 1
    else:
        result = 1
        for i in range(2, n + 1):
            result *= i
        return result

def nPr(n, r):
    """
    Calculate the permutation (nPr) of n objects taken r at a time.

    Parameters:
    n (int): Total number of objects.
    r (int): Number of objects taken at a time.

    Returns:
    int: The value of nPr.
    """
    if n >= r >= 0:
        return calculate_factorial(n) // calculate_factorial(n - r)
    else:
        return 0

def nCr(n, r):
    """
    Calculate the combination (nCr) of n objects taken r at a time.

    Parameters:
    n (int): Total number of objects.
    r (int): Number of objects taken at a time.

    Returns:
    int: The value of nCr.
    """
    if n >= r >= 0:
        return calculate_factorial(n) // (calculate_factorial(r) * calculate_factorial(n - r))
    else:
        return 0
