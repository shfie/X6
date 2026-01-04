import datetime

current_year = datetime.datetime.now().year


final_year = int(input("Enter the final year: "))

print("Leap years:")

for year in range(current_year, final_year + 1):
    if (year % 4 == 0 and year % 100 != 0) or (year % 400 == 0):
        print(year)
