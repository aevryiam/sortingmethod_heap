import random

def generate_random_integers(count=100000, filename="input.csv"):
    numbers = [str(random.randint(1, 100)) for _ in range(count)]

    number_string = ",".join(numbers)

    with open(filename, mode='w') as file:
        file.write(number_string)
    
    print(f"{count} angka acak telah disimpan ke '{filename}' dalam satu baris.")

if __name__ == "__main__":
    generate_random_integers()
