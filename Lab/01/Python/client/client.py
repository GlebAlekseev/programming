def left_click(event):
	r = requests.get('http://localhost:3000/raw') 
	
from tkinter import *
import requests 
import json
jsona = []



r = requests.get('http://localhost:3000/raw') 


jsona = r.text
parsed_string = json.loads(jsona)

root =  Tk()


label1 = Label(root,font='MicrosoftSansSerif 11 bold',text = "Симферополь",bg="Gold")
label2 = Label(root,height="1",font='MicrosoftSansSerif 10',text = parsed_string["description"].encode('l1').decode(),bg="Gold")
label3 = Label(root,font='MicrosoftSansSerif 44 bold',height=2,bg="white",text = parsed_string["temp"]+"°С")
frame1 = Frame(root,height=35,bg="Gold")
label1.pack(fill=X)
label2.pack(fill=X)
label3.pack(fill=X)
frame1.pack(fill=X)

root.bind("<Button-1>",left_click)
root.mainloop()
