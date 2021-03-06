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

len_raw = int(input())
start_elem_raw = int(input())
step_raw = int(input())
array_dark = create(len_raw, start_elem_raw, step_raw)
print(sort(array_dark))

