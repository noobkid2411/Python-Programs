# sorting using custom key
friends= [
    {'Name': 'Phoebe', 'age': 35, 'salary': 9000},
    {'Name': 'Rachel', 'age': 30, 'salary': 8000},
    {'Name': 'Ross', 'age': 25, 'salary': 10000},
    {'Name': 'Chandler', 'age': 30, 'salary': 15000},
    {'Name': 'Joey', 'age': 29, 'salary': 8000},
    {'Name': 'Monica', 'age': 30, 'salary': 15000},
]

# custom functions to get friends' info
def get_name(friends):
    return friends.get('Name')


def get_age(friends):
    return friends.get('age')


def get_salary(friends):
    return friends.get('salary')


# sort by name (Ascending order)
friends.sort(key=get_name)
print(friends, end='\n\n')

# sort by Age (Ascending order)
friends.sort(key=get_age)
print(friends, end='\n\n')

# sort by salary (Descending order)
friends.sort(key=get_salary, reverse=True)
print(friends, end='\n\n')