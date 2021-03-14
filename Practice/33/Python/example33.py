def create(len, start_elem = 0,Step = 0):
    array_main = []
    for i in range(int(len)):
        array_main.append(Step*i + start_elem)
    return array_main

def sort (array_main):
    i = 1
    while i < len(array_main):
        j=i
        while j > 0 and array_main[j-1] > array_main[j]:
            tmp = array_main[j - 1];
            array_main[j - 1] = array_main[j];
            array_main[j] = tmp;
            j-=1
        i+=1
    return array_main

_print = print
def print(array_main):
    _print(array_main)
    return array_main

while 1:
    len_raw = int(input())
    if len_raw <= 10000 and len_raw >= 1:
        break
    else:
        _print("len_raw ",len_raw," не входит в диапазон [1...10000]")

while 1:
    start_elem_raw = int(input())
    if start_elem_raw <= 10000 and start_elem_raw >= -10000:
        break
    else:
        _print("start_elem_raw ",start_elem_raw," не входит в диапазон [-10000...10000]")

while 1:
    step_raw = int(input())
    if step_raw <= 10000 and step_raw >= -10000:
        break
    else:
        _print("step_raw ",step_raw," не входит в диапазон [-10000...10000]")



array_dark = create(len_raw, start_elem_raw, step_raw)
print(sort(array_dark))

