import random

def generate_random_integers(count=1000000, filename="random_numbers.csv"):
    numbers = [str(random.randint(1, 100)) for _ in range(count)]

    # Gabungkan semua angka jadi satu string dipisahkan koma
    number_string = ",".join(numbers)

    # Tulis ke file CSV sebagai satu baris
    with open(filename, mode='w') as file:
        file.write(number_string)
    
    print(f"{count} angka acak telah disimpan ke '{filename}' dalam satu baris.")

if __name__ == "__main__":
    generate_random_integers()
