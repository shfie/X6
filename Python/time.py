class Time:
    def __init__(self):
        self.__hour = 0
        self.__minute = 0
        self.__second = 0

    def set_time(self, hour, minute=0, second=0):
        self.__hour = hour
        self.__minute = minute
        self.__second = second

    def display_time(self):
        
        print(self.__hour, ":", self.__minute, ":", self.__second)

# Example usage
t = Time()
t.display_time()       # 0 : 0 : 0

t.set_time(9)
t.display_time()       # 9 : 0 : 0

t.set_time(10, 30)
t.display_time()       # 10 : 30 : 0

t.set_time(14, 45, 20)
t.display_time()       # 14 : 45 : 20
