import turtle

t = turtle.Turtle()
t.speed(0)
t.pensize(2)
turtle.bgcolor("navyblue")

colors = ["red", "yellow"]
for i in range(40):
    t.color(colors[i % 2]) 
    t.circle(100)
    t.right(10)

turtle.done()
