# Define functions for different cases
def case1():
    return "This is case 1"

def case2():
    return "This is case 2"

def case3():
    return "This is case 3"

# Create a dictionary that maps case names to functions
cases = {
    "case1": case1,
    "case2": case2,
    "case3": case3
}

# Function to simulate a switch case
def switch_case(case_name):
    # Get the function for the given case_name from the dictionary
    func = cases.get(case_name, lambda: "Invalid case")
    
    # Call the function and return its result
    return func()

# Test the switch_case function
result = switch_case("case2")
print(result)
