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

