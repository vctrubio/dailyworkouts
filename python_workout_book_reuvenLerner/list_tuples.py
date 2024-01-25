import operator
import sys
import random
from collections import Counter
#lists are meant to be used for sequences of the same type, whereas tuples are meant for sequences of different types

t = (100, 200, 300)
lst = [1, 2, 3]

#firstlast
def ex09():
    ui = input("input: ")
    return ui[0], ui[-1]

#summing anything
def ex10():
    def sum(*args):
        if not args:
            print('empty')
            return 
        rtn = args[0]
        for i in args[1:]:
            rtn += i
        return rtn
    #ui = input('input: ')

    #ui = [[1,2,3], [4,5,6]]
    #ui = [[1,3,4], [5,4,1]]
    ui = (1, 3,4, 10)
    print('--> ', sum(ui))

#alpha names
def ex11():
    PEOPLE = [{'first':'Reuven', 'last':'Lerner',
               'email':'reuven@lerner.co.il'},
              {'first':'Donald', 'last':'Trump',
               'email':'president@whitehouse.gov'},
              {'first':'Vladimir', 'last':'Putin',
               'email':'president@kremvax.ru'}
              ]
    def sort_last_first(param):
        return sorted(param, key=lambda i: i['last'])
    return sort_last_first(PEOPLE)
    

#most repeating words
def ex12():
    ui = input('input: ')
    return Counter(ui).most_common(1)[0][0]

#printing tuple records
def ex13():
    PEOPLE = [('Donald', 'Trump', 7.85),
          ('Vladimir', 'Putin', 3.626),
          ('Jinping', 'Xi', 10.603)]
    
    #template = full-name = 10chr field, time = 5 chr fiel | 1 chr field of padding
    template = '{0:8} {1:18} {2:5.2f}'
    ppl_sort = sorted(PEOPLE, key=operator.itemgetter(1,0))
    for i in ppl_sort:
        print(template.format(*i))
    #print(template.format(ppl_sort[0]))


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
