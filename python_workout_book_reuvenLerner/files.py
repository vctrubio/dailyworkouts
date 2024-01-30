import sys
import os


#final line
def ex18():
   
    last_line = ''
    for ptr in open('fileexample.txt', 'r'):
        last_line = ptr

    return last_line

#file to dict
def ex19():
    user = {}
    with open('fileexample.txt', 'r') as file:
        for line in file:
            if not line.startswith(('#', '\n')):
                info = line.split(':')
                user[info[0]] = int(info[2])

    return user


#longest word per file
def ex21():
    #open dir, open each file, dict name - length

    def longest_word(file):
        long = ''
        with open(file, 'r') as f:
            for i in f:
                i2 = i.split()
                for i4 in i2:
                    if len(i4) > len(long):
                        long = i4
        return long

    diri = 'books'
    content = os.listdir(diri)
    mydic = {}
    for file in content:
        file = diri + '/' + file
        mydic[file] = longest_word(file)
    return mydic

if __name__ == '__main__':
    try:
        if len(sys.argv) < 2:
            raise IndexError("argv is less than 2")
        argv1 = sys.argv[1]
        if argv1 in globals():
            ft = globals()[argv1]
            print(ft())
        else:
            raise NameError("function does not exist")
    except Exception as e:
        print(f'{e}')
    finally:
        print('Pcomplete.')

