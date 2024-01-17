import sys
import random

def ex01():
    number = random.randint(0, 30)
    print(number)
    



if __name__ == '__main__':
    try:
        argv1 = sys.argv[1]
        try:
            ft_call = globals()[argv1]
            ft_call()
        except Exception:
            print("no correct argument")
    except Exception:
        print("No argumentes given")
    finally:
        print('complete.')
