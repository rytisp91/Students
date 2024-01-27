# Studentų Vertinimo Programa

Ši programa leidžia įvesti arba sugeneruoti studentų duomenis, apskaičiuoti jų galutinius vertinimus pagal skirtingus kriterijus ir juos išvesti.

## Naudojimas

### Suvesti Studentus Ranka

Norint suvesti studentus ranka (įvesti vardą, pavardę, namų darbų ir egzamino rezultatus), atkomentuokite šią funkciją:

//manualEnter();

Sugeneruoti Studentus Automatiškai
Norint sugeneruoti studentų duomenis automatiškai, atkomentuokite šią funkciją:

//generateStudents();

Nuskaityti Studentus Iš Failo
Norint nuskaityti studentus iš failo, atkomentuokite šią eilutę ir nurodykite failo pavadinimą ir norimą studentų skaičių:

//generateStudentsFromInputFile("studentai100.txt", 100);

Studento Klasė
Klasė Student aprašo studento duomenis, taip pat suteikia galimybę skaičiuoti galutinį vidurkį ir medianą.

Papildomos Funkcijos
manualEnter(): Leidžia vartotojui ranka suvesti studentus.
generateStudents(): Sugeneruoja studentus automatiškai.
generateStudentsFromInputFile(const std::string& filename, int numberOfStudents): Nuskaito studentus iš failo.

Pastabos
Programa leidžia pasirinkti skirtingus būdus duomenų įvedimui ir apskaičiavimams.
Galutiniai rezultatai yra išvesti lentele formatu, kuris lengvai skaitomas ir suprantamas.
Svarbu: Atkreipkite dėmesį, kad kodo fragmentai gali būti aktyvuojami arba deaktyvuojami komentaro simboliais, kad galėtumėte pasirinkti pageidaujamą funkcionalumą. Norėdami įvesti arba sugeneruoti studentus, atkomentuokite atitinkamas eilutes pagrindiniame faile (main.cpp).
