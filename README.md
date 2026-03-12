# DP-Week2-Task1-5224600079-Muhammad Farhan
Task1
Refleksi:
1. Apa struktur invariant dalam program Anda?
    Struktur invariant dalam program saya adalah urutan fase eksekusi yang kaku di dalam kelas RunSession. Urutan tersebut meliputi: pembuatan input, perhitungan skor dasar, perhitungan reward, pembaruan uang, fase toko, dan perpindahan ronde . Urutan ini adalah fondasi arsitektur yang tidak boleh berubah; jika urutannya bergeser—misalnya fase toko terjadi sebelum perhitungan reward maka logika permainan secara keseluruhan akan rusak.

2. Bagian mana yang bersifat mutable?
    Bagian yang mutable adalah detail logika di dalam masing-masing fase yang dapat berubah tanpa mengganggu struktur utama. Hal ini mencakup:
        Metode penghasil input: Bisa berupa angka statis atau angka acak dari RandomInputGenerator.
        Aturan penilaian: Rumus yang digunakan untuk menghitung skor dasar dari input.
        Logika reward: Bagaimana uang dihasilkan, misalnya mengubah reward dari yang awalnya sama dengan skor menjadi skor ditambah bonus tertentu .

3. Saat mengganti InputGenerator, mengapa RunSession tidak berubah?
    RunSession tidak berubah karena ia menggunakan prinsip abstraksi melalui interface IInputGenerator. RunSession hanya tahu bahwa ia harus memanggil fungsi untuk mendapatkan input, tanpa peduli bagaimana angka tersebut dihasilkan secara internal. Karena ketergantungan ini bersifat longgar (decoupled), saya dapat mengganti generator lama dengan RandomInputGenerator tanpa menyentuh kode di dalam RunSession sedikit pun.

4. Apa yang terjadi jika logika scoring diletakkan di dalam RunSession?
    Jika logika scoring diletakkan di dalam RunSession, maka kelas tersebut akan menjadi terlalu padat dan melanggar prinsip pemisahan tanggung jawab. Dampak buruknya adalah setiap kali ada perubahan pada cara perhitungan skor, kita terpaksa memodifikasi kelas RunSession. Hal ini meningkatkan risiko rusaknya urutan fase (invariant) hanya karena perubahan kecil pada aturan permainan (mutable), yang seharusnya bisa dihindari dengan arsitektur yang disiplin.
