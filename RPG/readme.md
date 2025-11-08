## Deskripsi Game:
Program ini merupakan game pertarungan sederhana berbasis console, di mana dua karakter (Player dan Enemy) bertarung secara bergantian (turn-based). Masing-masing karakter memiliki atribut seperti HP, Attack, Mana, dan Defense, serta dapat menggunakan kemampuan khusus (Ability) yang memberikan efek tertentu (FireBlast atau Heal).

## Tujuan permainan: 
Mengalahkan lawan dengan menyerang biasa atau menggunakan ability pada waktu yang tepat.

## Ketentuan: 
1. Program menggunakan konsep OOP (Object Oriented Programming), termasuk Inheritance, Polymorphism, dan Encapsulation, menggunakan bahasa pemrograman CPP atau Python.
2. Game berjalan di console, tidak perlu GUI.
3. Untuk requirements dan langkah langkah ini adalah contoh minimal dan bisa dikembangkan lagi.
4. Logika permainan:
    - Player mencari musuh diawal permainan dengan menambah jumlah langkah (steps).
    - Player dan Enemy bergantian menyerang, untuk Enemy serangannya random.
    - Masing-masing bisa memilih serangan biasa atau kemampuan khusus.
    - Pertarungan berakhir jika HP salah satu karakter ≤ 0.
    - Tambahan:
        - Cooldown untuk ability (setelah dipakai butuh 2 giliran untuk ready).
        - Limited uses di FireBlast (maks 3 kali).
        - Heal conditional (hanya jika HP < 30%).
        - Mana regen tiap akhir ronde.

## Requirements: 
1. Character (class induk)
    - Atribut: name, _hp, _mana, _attack, _defense
    - Method: attack(target), take_damage(amount), is_alive()
2. Ability (class induk)
    - Method: use(caster, target) → di-override oleh subclass
3. Player dan Enemy (subclass dari Character)
    - Player dapat berjalan menyusuri dungeon dengan menambahkan nilai steps, setiap jumlah step kelipatan 3 dan tidak habis di bagi 5 maka akan muncul Enemy.
    - Player dapat memilih antara serangan biasa atau menggunakan ability.
    - Enemy memiliki nama (Goblin, Slime, Skeleton, Wolf) perilaku dan stats otomatis/random.
4. FireBlast dan Heal (subclass dari Ability)
    - FireBlast: memberikan damage tambahan.
    - Heal: menambah HP pengguna.
5. GameController
    - Mencari musuh, mengatur giliran, menampilkan status, dan mengecek kondisi akhir.


## Langkah-langkah: 
1. Buat class Ability dengan method abstrak use().
2. Buat dua subclass:
    - FireBlast: mengurangi HP lawan sebesar (attack * 1.5), mengurangi mana (-10), hanya bisa digunakan 3 kali dalam 1 pertarungan.
    - Heal: menambah HP pengguna sebesar (attack * 0.8), mengurangi mana (-20), hanya bisa digunakan saat HP dibawah 30%.
3. Buat class Character yang memiliki atribut dasar (HP, attack, mana, defense, steps).
4. Buat subclass Player dan Enemy.
    - Player: memilih antara attack biasa atau ability.
    - Enemy: memilih aksi secara otomatis (misalnya random).
5. Buat class GameController untuk mengatur loop permainan:
    - Mencari musuh dengan menjalankan karakter
    - Menampilkan status HP.
    - Mengatur giliran.
    - Mengecek pemenang.
6. Jalankan simulasi di terminal.

## Notes for 4 Concept of OOP
### Encapsulation:
Encapsulation bundles data and methods together, restricting direct access to some components using access specifiers (private, protected, public).

### Inheritance:
Inheritance allows a class (child) to inherit properties and methods from another class (parent).

### Polymorphism:
Polymorphism allows methods to behave differently based on the object. It can be achieved through function overloading or method overriding.

### Abstraction:
Abstraction hides implementation details and shows only the essential features. This is often achieved using abstract classes or interfaces.