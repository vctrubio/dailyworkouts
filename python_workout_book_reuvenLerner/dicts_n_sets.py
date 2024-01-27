#create a new constant dict, called MENU, representing the possible items you can order at a restaurant.


def ex14():
    MENU = {
        "Burger": 5.99,
        "Pizza": 7.99,
        "Salad": 4.99,
        "Soda": 1.99
    }
    total = 0
    while True:
        ui = input("Enter a menu item: ")
        
        if not ui:
            break
        if ui in MENU:
            total = total + MENU[ui]
        else:
            print("Sorry, that item is not available.")
            continue
    print(total)



def ex15():
    rainfall = {}
    while True:
        
        city = input("Enter a city: ")
        if not city:
            break
        rain = input("Enter the rainfall: ")
        if city in rainfall:
            rainfall[city] += int(rain)
        else:
            rainfall[city] = int(rain)
        
    for i in rainfall:
        print(i, rainfall[i])

#dictdiff
def ex16():

    def dicdiff(d1, d2):
        output = {}
        d1_keys = d1.keys()
        d2_keys = d2.keys()
        d3 = d1_keys | d2_keys
        for d in d3:
            if d1.get(d) != d2.get(d):
                output[d] = [d1.get(d), d2.get(d)]
        return output

    d1 = {'a':1, 'i':6, 'b':2, 'c':3}
    d2 = {'a':1, 'b':2, 'c':4}
    print(dicdiff(d1, d2))

    return 
