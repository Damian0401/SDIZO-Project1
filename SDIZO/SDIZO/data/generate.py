import random

def generate_random_numbers(amount: int, filename: str, startRange: int = -1000, endRange: int = 1000):
    file = open(filename, 'w')
    file.write(f'{amount}\n')
    for _ in range(amount):
        file.write(f'{random.randint(startRange, endRange)}\n')
    file.close()

def main():
    generate_random_numbers(10, '10.txt')
    generate_random_numbers(100, '100.txt')
    generate_random_numbers(500, '500.txt')
    generate_random_numbers(1000, '1000.txt')
    generate_random_numbers(2000, '2000.txt')

if __name__ == '__main__':
    main()