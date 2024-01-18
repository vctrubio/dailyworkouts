import sys
import random

def ex01():
    number = random.randint(0, 100)
   
    while True:
        ui = int(input('input>'))
        if ui == number:
            break
        if ui < number:
            print('higher')
        else:
            print('lower')
    print('ex01 complete; random_number = ', number)
    
#mysum via de splat operator (*)
def ex02():
    ui = input("what is your input: only numbers please: ")
    lst = [int(i) for i in ui.split()]
    
    def splat(*lst):
        final_sum = 0
        for i in lst:
            final_sum += i
        return final_sum

    print("final sum: ", splat(*lst))

#run timing
def ex03():
    ui = []

    while True:
        inpt = input('input>')
        if len(inpt) == 0:
            break
        ui.append(ui)
   
    for i in ui:
        print(i)
    print(f'Average of {ui}, over runs')


if __name__ == '__main__':
    try:
        if len(sys.argv) < 2:
            raise IndexError("argv is less than 2")
        argv1 = sys.argv[1]
        if argv1 in globals():
            ft = globals()[argv1]
            ft()
        else:
            raise NameError("function does not exist")
    except Exception as e:
        print(f'{e}')
    finally:
        print('Pcomplete.')
