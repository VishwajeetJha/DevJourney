import calendar
from datetime import datetime

def display_calendar(year):
    today = datetime.today()
    current_day = today.day if today.year == year else None
    current_month = today.month if today.year == year else None

    for month in range(1, 13):
        print(f"\n{calendar.month_name[month]} {year}")
        month_calendar = calendar.month(year, month)

        # Highlight the current day in the current month
        if month == current_month and current_day:
            highlighted_calendar = month_calendar.replace(f"{current_day:2}", f"\033[31m{current_day:2}\033[0m")
            print(highlighted_calendar)
        else:
            print(month_calendar)

def get_year():
    """Prompts the user for a year and validates the input.

    Returns:
        int: The valid year entered by the user.
    """
    while True:
        try:
            year = int(input("Enter the year (e.g., 2024): "))
            if year < 1:
                raise ValueError("Year must be a positive integer.")
            return year
        except ValueError:
            print("Invalid input. Please enter a valid positive integer for the year.")

if __name__ == "__main__":
    year = get_year()
    display_calendar(year)

# o/p:-
# Enter the year (e.g., 2024): 2024

# January 2024
#     January 2024
# Mo Tu We Th Fr Sa Su
#  1  2  3  4  5  6  7
#  8  9 10 11 12 13 14
# 15 16 17 18 19 20 21
# 22 23 24 25 26 27 28
# 29 30 31
# .
# .
# .

# September 2024
#    September 2024
# Mo Tu We Th Fr Sa Su
#                    1
#  2  3  4  5  6  7  8
#  9 10 11 12 13 14 15
# 16 17 18 19 20 21 22
# 23 24 25 26 27 28 29 change color of current date in written o/p
# 30

# .
# .
# .
# December 2024
#    December 2024
# Mo Tu We Th Fr Sa Su
#                    1
#  2  3  4  5  6  7  8
#  9 10 11 12 13 14 15
# 16 17 18 19 20 21 22
# 23 24 25 26 27 28 29
# 30 31