import csv

data = [
    {"Name": "Alice", "Age": 23, "City": "London"},
    {"Name": "Bob", "Age": 30, "City": "New York"}
   
]


with open("output.csv", "w", newline="") as f:
    writer = csv.writer(f)
    # Write header
    writer.writerow(["Name", "Age", "City"])
    # Write rows
    for row in data:
        writer.writerow([row["Name"], row["Age"], row["City"]])

# 3️⃣ Read CSV and display contents
with open("output.csv", "r") as f:
    reader = csv.reader(f)
    for row in reader:
        print(row)
