
import sys

#pig latin
def ex05(ui):
    mod = ui[1:]
    if ui[0] in 'aeiou':
        mod += 'way'
    else:
        let = ui[0:1]
        mod += let
        mod += 'ay'
    print(mod)

#pig latin sentence
def ex06():
    ui = input("input str: ")
    ui = ui.split()
    for word in ui:
       ex05(word)

#prefix ub 
def ex07():
    ui = input("input str: ")
    output = []
    vowel = 'aeiou'
    ui = ui.split()
    for it, word in enumerate(ui):
        for i in word:
            if i in vowel:
                output.append('ub')
            output.append(i)
        if it != len(ui) - 1:     
            output.append(' ')
    
    output = ''.join(output)
    print(output)

#sorting a string
def ex08():
    ui = input("input str: ")
    sui = ui.replace(' ','')
    sui = set(sui)
    sui = sorted(sui)
    bui = sorted(set(ui.replace(' ','')))
    #print(sui) 
    print(bui) 


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
