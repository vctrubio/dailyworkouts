
import sys

#pig latin
def ex05():
    ui = input("input str: ")
    mod = ui[1:]
    if ui[0] in 'aeiou':
        mod += 'way'
    else:
        let = ui[0:1]
        mod += let
        mod += 'ay'
    print(mo[::[::2]])



if __name__ == '__main__':
    try:
        if len(sys.argv) < 2:
            raise IndexError("argv is less than 2")
        argv1 = sys.argv[1]
        if argv1 in globals():
            ft = globals()[argv1]
            globals()
            ft()
        else:
            raise NameError("function does not exist")
    except Exception as e:
        print(f'{e}')
    finally:
        print('Pcomplete.')
