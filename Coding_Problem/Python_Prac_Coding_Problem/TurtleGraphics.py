import turtle as t
t.shape('turtle')
#t.forward(100)
#t.right(90)
#t.forward(100)
#t.right(90)
#t.forward(100)
#t.right(90)
#t.forward(100)
for i in range(4):
    t.forward(100)
    t.right(90)

def draw_n_shape(n):
    for i in range(n):
        t.forward(100)
        t.right(360 / n)


draw_n_shape(6)