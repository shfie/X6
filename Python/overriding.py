# Base class: Publisher
class Publisher:
    def __init__(self, name):
        self.name = name  # Constructor for Publisher
    
    def display_info(self):
        print(f"Publisher Name: {self.name}")


# Derived class: Book
class Book(Publisher):
    def __init__(self, name, title, author):
        # Call base class constructor
        super().__init__(name)
        self.title = title
        self.author = author

    # Overriding method
    def display_info(self):
        # Call base class method (optional)
        super().display_info()
        print(f"Book Title: {self.title}")
        print(f"Author: {self.author}")


# Example usage
b1 = Book("Penguin Books", "The Great Gatsby", "F. Scott Fitzgerald")
b1.display_info()
