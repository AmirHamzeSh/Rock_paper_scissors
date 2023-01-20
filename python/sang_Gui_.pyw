from random import choice
from tkinter import Tk,Frame,Label,Button,StringVar

# =================window=================
Window = Tk()
Window.title("سنگ کاغذ قیچی")
Window.geometry("500x500")
Window.resizable(width=False, height=False)

Frame_up =     Frame(Window, height=166.66, bg="#00b7ff").pack(fill='x')
Frame_middle = Frame(Window, height=166.66, bg="#6fd6ff").pack(fill='x')
Frame_down =   Frame(Window, height=166.66, bg="#00b7ff").pack(fill='x')

# ================Base================
GAME = ["سنگ", "کاغذ", "قیچی"]
sPlayer_1 = 0
sPlayer_2 = 0

# ==================wellcome==================
Label(Frame_up, text="\U0001f600 به بازی سنگ، کاغذ، قیچی خوش آمدید",
    width=30, height=2, bg="#6fd6ff").place(x=155, y=0)

Label(text=f"==== .امتیاز شما {sPlayer_1} و کامپیوتر  {sPlayer_2} است ====",
    width=40, height=3,bg="#86fcfc",fg="black").place(x=120, y=60)

# ===============================================
Label(Frame_up, width=10, height=2, 
    text=":انتخاب کنید",
    bg="#00b7ff", fg="black").place(x=400, y=125)
# =======
Button_Sang =   Button(Frame_up, text="سنگ", width=10, bg="#6fd6ff",
    fg="black",  command=lambda: Action(GAME[0])).place(x=310, y=130)
# =======
Button_kaghaz = Button(Frame_up, text="کاغذ", width=10, bg="#6fd6ff",
    fg="black",  command=lambda: Action(GAME[1])).place(x=220, y=130)
# =======
Button_ghekhi = Button(Frame_up, text="قیچی", width=10, bg="#6fd6ff",
    fg="black",  command=lambda: Action(GAME[2])).place(x=130, y=130)
# ===============================================
Button_Exit =   Button(Frame_down, text="خروج", width=30, height=2,
    fg="black",bg="#6fd6ff", command=Window.destroy).place(x=150, y=390)


# ====================Action====================
def Action(Value):
    
    Player1 = Value
    Player2 = choice(GAME)

    Label(Frame_middle, text=f"انتخاب شما:        {Player1}",
        width=20, height=2, bg="#f2e906", fg="black").place(x=190, y=190)
    Label(Frame_middle, text=f"انتخاب کامپیوتر:   {Player2}",
        width=20, height=2, bg="#f2e906", fg="black").place(x=190, y=230)

    def Print_result(value):
        Action_ = StringVar()
        Action_.set(value)

        Label(Frame_middle, textvariable=Action_, width=20,height=2,
            bg="yellow", fg="black").place(x=190, y=270)

    def Score(arg):
        global sPlayer_1, sPlayer_2
        if arg == 1:
            sPlayer_1 += 1
        elif arg == 2:
            sPlayer_2 += 1
        else:
            Print_result("خطا در امتیاز دهی")

        Label(text=f"==== .امتیاز شما {sPlayer_1} و کامپیوتر  {sPlayer_2} است ====",
            width=40, height=3, bg="#86fcfc", fg="black").place(x=120, y=60)

    if   Player1 == Player2:
        Print_result("مساوی"),
    elif Player1 == GAME[0] and Player2 == GAME[1]:
        Print_result("کامپیوتر برنده شد"), Score(2)
    elif Player1 == GAME[0] and Player2 == GAME[2]:
        Print_result("شما برنده شدید"), Score(1)
    elif Player1 == GAME[1] and Player2 == GAME[0]:
        Print_result("شما برنده شدید"), Score(1)
    elif Player1 == GAME[1] and Player2 == GAME[2]:
        Print_result("کامپیوتر برنده شد"), Score(2)
    elif Player1 == GAME[2] and Player2 == GAME[0]:
        Print_result("کامپیوتر برنده شد"), Score(2)
    elif Player1 == GAME[2] and Player2 == GAME[1]:
        Print_result("شما برنده شدید"), Score(1)
    else:
        Print_result("خطای نامشخص!")

# =====Run Window in loop=====
Window.mainloop()
