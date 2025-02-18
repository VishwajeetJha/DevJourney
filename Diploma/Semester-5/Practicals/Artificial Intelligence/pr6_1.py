import calendar
def display_calendar(year):
    cal = calendar.TextCalendar(calendar.SUNDAY)
    print(f"Full calendar for the year {year}:\n")
    for month in range(1, 13):
        print(cal.formatmonth(year, month))
year = int(input("Enter the year: "))
display_calendar(year)

# o/p:-
# Enter the year: 2024
# Full calendar for the year 2024:

#     January 2024
# Su Mo Tu We Th Fr Sa
#     1  2  3  4  5  6
#  7  8  9 10 11 12 13
# 14 15 16 17 18 19 20
# 21 22 23 24 25 26 27
# 28 29 30 31
# .
# .
# .
#    December 2024
# Su Mo Tu We Th Fr Sa
#  1  2  3  4  5  6  7
#  8  9 10 11 12 13 14
# 15 16 17 18 19 20 21
# 22 23 24 25 26 27 28
# 29 30 31