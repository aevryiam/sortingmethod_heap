# README: Implementasi Heap Sort (C++)

Heap sort bekerja dengan memanfaatkan struktur data heap. Terdapat dua jenis heap:
1. **Max Heap**: Elemen terbesar menjadi root (dipakai untuk sort ascending).
2. **Min Heap**: Elemen terkecil menjadi root (dipakai untuk sort descending).

## Langkah Utama
1. Bangun struktur heap (max heap atau min heap).
2. Tukar root dengan elemen terakhir.
3. Kecilkan ukuran heap dan perbaiki heap hingga semua elemen terurut.

Heap sort efisien karena:
• Kompleksitas membangun heap adalah O(n).  
• Proses menukar root dan memperbaiki heap berulang adalah O(n log n).

Gunakan strategi yang sesuai dengan kebutuhan urutan (ascending atau descending).

### Catatan
• Rename file csv yang ingin kamu gunakan menjadi input.csv, atau cukup gunakan script python yang sudah saya sediakan juga bilamana menginginkan jumlah yang tidak ada dalam repo ini.