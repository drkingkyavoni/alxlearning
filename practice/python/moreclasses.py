#!/usr/bin/python3

class User:
    id = 1


if __name__ == "__main__":
    u = User()
    u.id = 89
    User.id = 98
    print(User.id)
