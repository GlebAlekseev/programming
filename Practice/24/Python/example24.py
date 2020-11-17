import json

jsona = []
jsout = []
with open('in.json','r', encoding="utf-8") as read_file:
	data = json.load(read_file)
	jso = []
	temp = 0
	task_completed = 0
	jsou = []
	jsot = []

	i = 0
	for itemi in data:

		task_completed = 0
		temp = itemi["userId"];
		for itemp in data:
			if itemi["userId"] == itemp["userId"] and itemi["id"] != -1:
				if bool(itemp["completed"]) == True:
					task_completed += 1
					


				if itemi["id"] != itemp["id"]:
					itemp["id"] = -1


		dicti = {"task_completed":task_completed,"userId":itemi["userId"]}
		jso.append(dicti)
		i +=1



	for n in jso:
		if n["task_completed"] != 0:
			jsout.append(n)



with open("out.json", "w") as write_file:
	json.dump(jsout, write_file, indent=2)