#include "My_Lib.h"
#include <iomanip>
#include <random>

int minimum(int a, int b) { return a < b ? a : b; }

Student::Student() {}

Student::Student(std::string N, std::string S, std::vector<int> H, int E) {
	Name = N;
	Surname = S;
	HW = H;
	Exam = E;
	Result();
}

Student::Student(const Student& A) {
	Name = A.Name;
	Surname = A.Surname;
	HW = A.HW;
	Exam = A.Exam;
	AvgRes = A.AvgRes;
	MedRes = A.MedRes;
}

Student& Student::operator=(const Student& A) {
	if (this == &A) return *this;
	Name = A.Name;
	Surname = A.Surname;
	HW = A.HW;
	Exam = A.Exam;
	AvgRes = A.AvgRes;
	MedRes = A.MedRes;
	return *this;
}

Student::~Student() {
	Name.clear();
	Surname.clear();
	HW.clear();
	Exam = 0;
	AvgRes = 0;
	MedRes = 0;
}

float Student::Avg() {
	return std::accumulate(HW.begin(), HW.end(), 0.0) / HW.size();
}

float Student::Med() {
	std::sort(HW.begin(), HW.end());
	int n = HW.size() / 2;
	return (n % 2 == 1) ? HW[n] / 1.0 : (HW[n] + HW[n + 1]) / 2.0;
}

void Student::Result() {
	AvgRes = 0.4 * Avg() + 0.6 * Exam;
	MedRes = 0.4 * Med() + 0.6 * Exam;
}

std::ostream& operator<<(std::ostream& out, const Student& A) {
	static bool isFirst = true;
	if (isFirst) {
		out << std::left << std::setw(20) << "Pavarde"
			<< std::setw(20) << "Vardas"
			<< std::setw(25) << "Galutinis (Vid.)"
			<< std::setw(25) << "Galutinis (Med.)" << std::endl;
		out << "----------------------------------------------------------------------------------" << std::endl;
		isFirst = false;
	}
	out << std::setw(20) << A.Surname
		<< std::setw(20) << A.Name
		<< std::setw(25) << std::fixed << std::setprecision(2) << A.AvgRes
		<< std::setw(25) << std::fixed << std::setprecision(2) << A.MedRes << std::endl;
	return out;
}

std::istream& operator>>(std::istream& in, Student& A) {
	std::string tempS;
	std::vector<int> Vec;
	in >> A.Name;
	in >> A.Surname;
	for (int i = 0; i < 4; i++) {
		int grade;
		in >> grade;
		A.HW.push_back(grade);
	}
	in >> A.Exam;
	A.Result();
	return in;
}

void manualEnter() {
	std::vector<Student> Group;
	std::cout << "Veskite studentus ranka: " << std::endl;
	bool last = true;
	while (last) {
		Student Temp;
		std::string tempS;
		std::cin >> Temp;
		Group.push_back(Temp);
		Temp.~Student();

		std::cout << "Ar tai paskutinis studentas? (y/n)" << std::endl;
		std::string answer = "n";
		std::cin >> answer;
		if (answer == "y") {
			last = false;
			for (auto& data : Group) std::cout << data;
		}
		else {
			std::cout << "Sekantis studentas: " << std::endl;
		}
	}
}

void generateStudents() {
	std::vector<Student> Group;
	int amount;
	std::cout << "Kiek grupeje bus studentu?" << std::endl;
	std::cin >> amount;

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(1, 10);

	for (size_t i = 0; i < amount; i++) {
		Student Temp;
		Temp.SetName("Vardas" + std::to_string(i + 1));
		Temp.SetSurname("Pavarde" + std::to_string(i + 1));

		std::vector<int> tempHW;
		for (int j = 0; j < 4; j++) {
			tempHW.push_back(dis(gen));
		}
		Temp.SetHW(tempHW);

		Temp.SetExam(dis(gen));

		Temp.Result();

		Group.push_back(Temp);
	}

	for (auto& data : Group) {
		std::cout << data;
	}
}

void generateStudentsFromInputFile(const std::string& filename, int numberOfStudents) {
	try {
		std::ifstream inputFile(filename);
		if (!inputFile.is_open()) {
			throw std::runtime_error("Nepavyko atidaryti failo " + filename);
		}

		std::vector<Student> Group;
		for (int i = 0; i < numberOfStudents; ++i) {
			Student Temp;
			inputFile >> Temp;
			Temp.Result();
			Group.push_back(Temp);
		}

		for (const auto& data : Group) {
			std::cout << data;
		}
		inputFile.close();
	}
	catch (const std::exception& e) {
		std::cerr << "Išimtis generateStudentsFromInputFile metode: " << e.what() << std::endl;
	}
}
