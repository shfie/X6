import csv

with open("data.csv", "r") as f:
    r = csv.reader(f)
    for row in r:
        print(row)
