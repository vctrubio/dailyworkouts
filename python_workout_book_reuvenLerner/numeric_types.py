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
