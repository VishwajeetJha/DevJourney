import datetime
year = (int(input("Enter the year: ")))
start_date = datetime.date(year, 1, 1)
day_of_week = start_date.weekday()
days_to_sunday = 6 - day_of_week
sunday_date = start_date + datetime.timedelta(days=days_to_sunday)
print(f"Sundays in {year}:")
print("Day Month Year")
while sunday_date.year == year:
    print(sunday_date.strftime(" %d   %m  %Y"))
    sunday_date += datetime.timedelta(weeks=1)