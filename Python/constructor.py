class BankAccount:
    def __init__(self, name, balance=0):
        self.name = name
        self.balance = balance

    def deposit(self, amount):
        self.balance += amount
        print("Deposited $", amount)
        print(" Balance is now $", self.balance)

    def withdraw(self, amount):
        if amount > self.balance:
            print("Not enough balance!")
        else:
            self.balance -= amount
            print("Withdrew $", amount)
            print("Balance is now $", self.balance)

    def get_balance(self):
        print("Balance: $", self.balance)


name = input("ENTER UR NAME ")
balance = float(input(" ENTER Starting balance: "))
account = BankAccount(name, balance)

while True:
    print("choose operation")
    
    
    choice = input("deposit, withdraw, balance, exit: ").lower()

    if choice == "deposit":
        amount = float(input("Amount to deposit: "))
        account.deposit(amount)

    elif choice == "withdraw":
        amount = float(input("Amount to withdraw: "))
        account.withdraw(amount)

    elif choice == "balance":
        account.get_balance()

    elif choice == "exit":
        print("Bye!")
        break

    else:
        print("Invalid choice.")
