def first():
    second()
    print("I am the first")


def second():
    third()
    print("I am the second")


def third():
    fourth()
    print("I am the third")


def fourth():
    print("I am the fourth")


first()

# I am the fourth
# I am the third
# I am the second
# I am the first
