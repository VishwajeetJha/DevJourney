import calendar

def generate_calendar(year, month):
    cal = calendar.month(year, month)
    return cal

def validate_input(year, month):
    if year <= 0 or year <= 1000:
        print("Please enter a valid year.")
        return False
    if month < 1 or month > 12:
        print("Please enter a valid month between 1 and 12.")
        return False
    return True

year = int(input("Enter the year: "))
month = int(input("Enter the month (1-12): "))

if validate_input(year, month):
    print("\nCalendar:")
    print(generate_calendar(year, month))
else:
    print("Error: Invalid input.")


# o/p:-
# Enter the year: 2024
# Enter the month (1-12): 12

# Calendar:
#    December 2024
# Mo Tu We Th Fr Sa Su
#                    1
#  2  3  4  5  6  7  8
#  9 10 11 12 13 14 15
# 16 17 18 19 20 21 22
# 23 24 25 26 27 28 29
# 30 31


# DEV TRIVEDI@LAPTOP-8TMH97EN MINGW64 /c/dev vs code/clg/sem 5/FAI (main)
# $ python -u "c:\dev vs code\clg\sem 5\FAI\pr6_2.py"
# Enter the year: 2024
# Enter the month (1-12): 13
# Please enter a valid month between 1 and 12.
# Error: Invalid input.