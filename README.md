# Studentų Rezultatų Apskaitos Programa

## Aprašymas

Ši programa leidžia vartotojui įvesti studentų duomenis ranka, sugeneruoti studentus atsitiktinai arba nuskaityti duomenis iš failo. Programa skaičiuoja galutinį studento rezultatą naudodama vidurkį ir medianą.

## Naudojimas

### 1. Rankinis įvedimas

manualEnter();
Vartotojas gali įvesti studentų duomenis rankiniu būdu (vardas, pavardė, namų darbų įvertinimai, egzamino įvertinimas).

### 2. Studentų generavimas

generateStudents();
Programa sugeneruoja studentus atsitiktinai, priskirdama jiems atsitiktinius vardus, pavardes, namų darbų ir egzamino įvertinimus.

### 3. Nuskaitymas iš failo

generateStudentsFromInputFile("studentai100.txt", 100);
Duomenys nuskaitomi iš failo, o programa skaičiuoja rezultatus.

### Failų Struktūra
Students.cpp: Pagrindinė funkcija ir naudojimo pavyzdžiai.

My_Lib.h: Header failas

My_Lib.cpp: Aprašyta Student klasė ir pagrindinė programa.

### Išimčių Valdymas
Išimtys yra tvarkomos try ir catch blokuose, pavyzdžiui:
try {
    // kodas, kuris atlieka tam tikras užduotis
} catch (std::exception& e) {
    // kodas, kuris apdoroja išimtis
    std::cerr << "Išimtis: " << e.what() << std::endl;
}

### Reikalavimai
C++11 arba naujesnė versija.

Autorius

Rytis Povilaitis
